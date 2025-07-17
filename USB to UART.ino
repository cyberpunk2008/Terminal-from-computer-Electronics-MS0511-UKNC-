#include <SoftwareSerial.h>

SoftwareSerial softSerial(10, 11); // RX, TX пины для софтварного UART

void setup() {
  // Инициализация серийного порта
  Serial.begin(9600); // Аппаратный UART
  softSerial.begin(9600); // Софтварный UART
}

void loop() {
  // Если данные пришли на софтварный UART, отправляем их на аппаратный
  if (softSerial.available()) {
    char c = softSerial.read();
    Serial.write(c);
  }

  // Если данные пришли на аппаратный UART, отправляем их на софтварный
  if (Serial.available()) {
    char c = Serial.read();
    softSerial.write(c);
  }
}

