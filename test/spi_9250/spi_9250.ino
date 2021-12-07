/*
19:19:07.111 -> AcX: -156.9144  AcY: -16.2191 AcZ: 5.9092 GyX: 0.0202 GyY:-0.0502 GyZ:-0.0011 MgX:-29.4753  MgY: -7.6311  MgZ: 11.8815  Temp: 29.9286
19:19:07.211 -> AcX: -156.9144  AcY: -16.4921 AcZ: 5.9810 GyX: 0.0404 GyY:-0.1111 GyZ:-0.0010 MgX:-29.8326  MgY: -7.6311  MgZ: 13.2591  Temp: 29.9226
19:19:07.310 -> AcX: -156.9144  AcY: -16.6645 AcZ: 6.3066 GyX: 0.1346 GyY:-0.0019 GyZ:0.0009  MgX:-30.0112  MgY: -6.0339  MgZ: 10.3317  Temp: 29.9226
19:19:07.409 -> AcX: -156.9144  AcY: -16.6741 AcZ: 6.3162 GyX: -0.0243  GyY:-0.0100 GyZ:0.0016  MgX:-30.0112  MgY: -6.0339  MgZ: 10.3317  Temp: 29.9286
19:19:07.509 -> AcX: -156.9144  AcY: -16.3053 AcZ: 6.1726 GyX: -0.1294  GyY:-0.1332 GyZ:-0.0000 MgX:-31.2617  MgY: -7.2761  MgZ: 11.1927  Temp: 29.9256
*/

/*
Basic_SPI.ino
Brian R Taylor
brian.taylor@bolderflight.com

Copyright (c) 2017 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on SPI bus 0 and chip select pin 26
//MPU9250 IMU(SPI,10);
MPU9250 IMU(SPI,26);
int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  // read the sensor
  IMU.readSensor();
  // display the data
  Serial.print("AcX: ");
  Serial.print(IMU.getAccelX_mss(),4);
  Serial.print("\tAcY: ");
  Serial.print(IMU.getAccelY_mss(),4);
  Serial.print("\tAcZ: ");
  Serial.print(IMU.getAccelZ_mss(),4);
  Serial.print("\tGyX: ");
  Serial.print(IMU.getGyroX_rads(),4);
  Serial.print("\tGyY:");
  Serial.print(IMU.getGyroY_rads(),4);
  Serial.print("\tGyZ:");
  Serial.print(IMU.getGyroZ_rads(),4);
  Serial.print("\tMgX:");
  Serial.print(IMU.getMagX_uT(),4);
  Serial.print("\tMgY: ");
  Serial.print(IMU.getMagY_uT(),4);
  Serial.print("\tMgZ: ");
  Serial.print(IMU.getMagZ_uT(),4);
  Serial.print("\tTemp: ");
  Serial.println(IMU.getTemperature_C(),4);
  delay(100);
}
