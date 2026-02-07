#include <Wire.h>
#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx;

sBmx160SensorData_t accel;
sBmx160SensorData_t gyro;
sBmx160SensorData_t mag;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing BMX160...");

  if (!bmx.begin()) {   // default address: 0x68
    Serial.println("BMX160 not detected!");
    while (1);
  }

  Serial.println("BMX160 initialized!");
}

void loop() {
  // Read all sensor data
  bmx.getAllData(&accel, &gyro, &mag);

  Serial.println("-------------------------");

  Serial.print("Accel (mg): ");
  Serial.print(accel.x); Serial.print(", ");
  Serial.print(accel.y); Serial.print(", ");
  Serial.println(accel.z);

  Serial.print("Gyro (dps): ");
  Serial.print(gyro.x); Serial.print(", ");
  Serial.print(gyro.y); Serial.print(", ");
  Serial.println(gyro.z);

  Serial.print("Mag (uT): ");
  Serial.print(mag.x); Serial.print(", ");
  Serial.print(mag.y); Serial.print(", ");
  Serial.println(mag.z);

  delay(500);
}
