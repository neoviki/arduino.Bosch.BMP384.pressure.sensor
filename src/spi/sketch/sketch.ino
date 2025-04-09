#include <Wire.h> 
#include <SPI.h> 
#include <Adafruit_Sensor.h> 
#include "Adafruit_BMP3XX.h" 


//Viki Board
#if 1
#define BMP_CS 8 
#define BMP_SCK 9
#define BMP_MOSI 10 
#define BMP_MISO 11 

#endif

#define SEALEVELPRESSURE_HPA (1013.25) 
Adafruit_BMP3XX bmp; 

bool init_bmp384()
{
        static bool bmp_init_flag = false;

        if(bmp_init_flag) return true;

        digitalWrite(BMP_CS, LOW);
         
        if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) 
        {  
            Serial.println("Could not find a valid BMP3 sensor, check wiring!"); 
            return false;
        } 
    
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
     delay(100); 
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X); 
     delay(100);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3); 
     delay(100);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ); 
     delay(100);
    Serial.println("Init Success");
    delay(100);
    bmp_init_flag = true;
    return true;
}

void init_bmp384_unit_success()
{
  while(1){
    if(init_bmp384()) break;
    delay(500);
  }
}

void setup() 
{ 
    int i;
    Serial.begin(115200); 

    while (!Serial); 

    for( i=0;i<2;i++){ 
        delay(100); Serial.println("Setup()"); 
    } 

    init_bmp384();
} 

void loop() { 
  
  //init_bmp384_unit_success();

  if (! bmp.performReading()) { 
    Serial.println("Failed to perform reading :("); 
    return; 
  } 

  Serial.print("TEMPERATURE = "); 
  Serial.print(bmp.temperature); 
  Serial.print(" *C"); 
  Serial.print(" | PRESSURE = "); 
  Serial.print(bmp.pressure / 100.0); 
  Serial.print(" hPa"); 
  Serial.print(" | ALTITUDE = "); 
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA)); 
  Serial.print(" m"); 
  Serial.println(); 

  delay(500); 
} 
