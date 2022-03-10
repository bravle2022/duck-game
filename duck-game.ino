#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_B 3

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

int buttonPushed = LOW;
int numbers[2][16]
{
  {0, 0, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0}
};
int timelast = millis();
int timeNow = millis();

int nowState = 0;
int lastState = 0;
int counter = 0;
int xCoor = 0;

uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();

  lcd.createChar(2, clock);
  lcd.createChar(1, bell);
  lcd.backlight();
  lcd.createChar(4, duck);
  lcd.setCursor(1, 14);
  lcd.printByte(4);
};

void loop() {
  
  buttonPushed = digitalRead(3);
  if (buttonPushed == HIGH) {
    lcd.clear();
    lcd.setCursor(14, 0);
    lcd.printByte(4);
  }

  if (buttonPushed == LOW) {
    lcd.clear();
    lcd.setCursor(14, 1);
    lcd.printByte(4);
  }
  
  if (xCoor < 16) {
    lcd.setCursor(xCoor, 1);
    lcd.printByte(1);
    xCoor++;
  }

  delay(100);
}
