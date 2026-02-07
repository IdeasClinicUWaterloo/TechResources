#include <Wire.h>

#define BMX160_ADDR 0x68

// ================= REGISTERS =================
#define BMX160_CHIP_ID      0x00
#define BMX160_ERR_REG      0x02
#define BMX160_PMU_STATUS   0x03
#define BMX160_CMD          0x7E

#define BMX160_ACC_CONF     0x40
#define BMX160_ACC_RANGE    0x41
#define BMX160_DATA_START   0x12

// ================= COMMANDS =================
#define CMD_SOFT_RESET      0xB6
#define CMD_ACC_NORMAL      0x11

// ================= CONSTANTS =================
#define ACC_LSB_PER_G       16384.0f   // ±2g
#define GRAVITY             9.80665f

// ================= LOW-LEVEL I2C =================
void writeReg(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(BMX160_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

uint8_t readReg(uint8_t reg) {
  Wire.beginTransmission(BMX160_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(BMX160_ADDR, (uint8_t)1);
  return Wire.read();
}

void readRegs(uint8_t reg, uint8_t *buf, uint8_t len) {
  Wire.beginTransmission(BMX160_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(BMX160_ADDR, len);
  for (uint8_t i = 0; i < len; i++) {
    buf[i] = Wire.read();
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  delay(500);

  // Explicit I2C init
  Wire.begin();
  Wire.setClock(100000);   // stable for BMX160

  // -------- Soft reset --------
  writeReg(BMX160_CMD, CMD_SOFT_RESET);
  delay(150);  // allow NVM reload

  // -------- Verify chip ID --------
  uint8_t chip = readReg(BMX160_CHIP_ID);
  if (chip != 0xD8) {
    Serial.print("BMX160 not detected! Chip ID = 0x");
    Serial.println(chip, HEX);
    while (1);
  }

  // -------- Power up accelerometer --------
  writeReg(BMX160_CMD, CMD_ACC_NORMAL);
  delay(50);

  // Wait until accel reports normal mode
  while ((readReg(BMX160_PMU_STATUS) & 0x30) != 0x10) {
    delay(10);
  }

  // -------- Configure accelerometer --------
  // ACC_CONF:
  // ODR = 100 Hz
  // Bandwidth = normal
  // Avg = 1 sample
  writeReg(BMX160_ACC_CONF, 0x28);
  delay(10);

  // ACC_RANGE: ±2g
  writeReg(BMX160_ACC_RANGE, 0x03);
  delay(10);

  // -------- Clear errors --------
  readReg(BMX160_ERR_REG);

  Serial.println("BMX160 fully initialized");
}

// ================= LOOP =================
void loop() {
  uint8_t raw[6];
  readRegs(BMX160_DATA_START, raw, 6);

  int16_t rawX = (int16_t)((raw[1] << 8) | raw[0]);
  int16_t rawY = (int16_t)((raw[3] << 8) | raw[2]);
  int16_t rawZ = (int16_t)((raw[5] << 8) | raw[4]);

  float ax = (rawX / ACC_LSB_PER_G) * GRAVITY;
  float ay = (rawY / ACC_LSB_PER_G) * GRAVITY;
  float az = (rawZ / ACC_LSB_PER_G) * GRAVITY;

  Serial.print("Accel (m/s^2): ");
  Serial.print(ax, 3);
  Serial.print(" ");
  Serial.print(ay, 3);
  Serial.print(" ");
  Serial.println(az, 3);

  delay(100);
}
