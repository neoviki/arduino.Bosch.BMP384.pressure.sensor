#include <Wire.h> 
#include <SPI.h> 
#include <Adafruit_Sensor.h> 
#include "Adafruit_BMP3XX.h" 


//Breakout Board
#if 0
#define VOLT_SRC 8 /*Connect sensor voltage input vcc to this pin*/
#define BMP_MOSI 9 
#define BMP_MISO 10
#define BMP_SCK 11 
#define BMP_CS 12 
#endif


//Viki Board
#if 1
#define VOLT_SRC 8 /*Connect sensor voltage input vcc to this pin*/
#define BMP_MOSI 9 
#define BMP_SCK 10
#define BMP_MISO 11 
#define BMP_CS 12 
#endif

#define SEALEVELPRESSURE_HPA (1013.25) 
bool bmp_init_flag = false;
Adafruit_BMP3XX bmp; 

void init_bmp384()
{
        digitalWrite(BMP_CS, LOW); 
        if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) 
        {  
            Serial.println("Could not find a valid BMP3 sensor, check wiring!"); 
            return;
        } 
    
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X); 
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X); 
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3); 
    bmp.setOutputDataRate(BMP3_ODR_50_HZ); 
    Serial.println("Init Success");
    delay(100);
    bmp_init_flag = true;
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
  
  if(!bmp_init_flag){
    init_bmp384();
  }

  if (! bmp.performReading()) { 
    Serial.println("Failed to perform reading :("); 
    return; 
  } 

  Serial.print("Temperature = "); 
  Serial.print(bmp.temperature); 
  Serial.println(" *C"); 
  Serial.print("Pressure = "); 
  Serial.print(bmp.pressure / 100.0); 
  Serial.println(" hPa"); 
  Serial.print("Approx. Altitude = "); 
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA)); 
  Serial.println(" m"); 
  Serial.println(); 

  delay(500); 
} 
