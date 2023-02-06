#include <Wire.h> 
#include <SPI.h> 
#include <Adafruit_Sensor.h> 
#include "Adafruit_BMP3XX.h" 
#define BMP_MOSI 8 
#define BMP_MISO 9 
#define BMP_SCK 10
#define BMP_CS 11 



#define SEALEVELPRESSURE_HPA (1013.25) 

Adafruit_BMP3XX bmp; 

void setup() 
{ 
    Serial.begin(115200); 

    while (!Serial); 

    for(int i=0;i<2;i++){ 
        delay(1000); Serial.println("Setup()"); 
    } 

    while(1)
    {
        delay(500);
        digitalWrite(BMP_CS, LOW); 
        delay(500);

        if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) 
        {  
            delay(2000); Serial.println("2"); 
            Serial.println("Could not find a valid BMP3 sensor, check wiring!"); 
        }else{
            break;
        } 
    }  

    delay(2000); Serial.println("3"); 
    Serial.println("Init Success"); 
    // Set up oversampling and filter initialization 
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X); 
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X); 
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3); 
    bmp.setOutputDataRate(BMP3_ODR_50_HZ); 
} 

void loop() { 
  
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
  delay(2000); 
} 
