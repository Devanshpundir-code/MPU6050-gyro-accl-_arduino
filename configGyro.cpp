#include <MPU6050_tockn.h>
#include <Wire.h>
//importing required modules
//mpu uses I2C protocol

MPU6050 mpu6050(Wire);
//creating a object 
//we are using wire lib because mpu is a low speed device so to link mpu with arduino 




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true); // this line is used to calibrate the gyro because it gyro can give drift errors while stationary


}

void loop() {
  // put your main code here, to run repeatedly:
  mpu6050.update();//this updates the value of gyro everytime the this loop is used
  Serial.print("angleX");
  Serial.print(mpu6050.getAngleX());


  Serial.print("\tangleY");
  Serial.print(mpu6050.getAngleY());


  Serial.print("\tangleZ");
  Serial.print(mpu6050.getAngleZ());



}
