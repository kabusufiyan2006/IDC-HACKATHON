// MPU6050 I2C Example for ESP32
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
  } else {
    Serial.println("MPU6050 connection successful");
  }
}

void loop() {
  // Update values from MPU6050
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print the values
  Serial.print("Accel X:"); Serial.print(ax);
  Serial.print(" | Accel Y:"); Serial.print(ay);
  Serial.print(" | Accel Z:"); Serial.println(az);
  Serial.print("Gyro X:"); Serial.print(gx);
  Serial.print(" | Gyro Y:"); Serial.print(gy);
  Serial.print(" | Gyro Z:"); Serial.println(gz);

  delay(100);
}