#include <LiquidCrystal.h>
#define RS A5
#define E1 A4
#define E2 A0
#define D4 7
#define D5 8
#define D6 9
#define D7 10

LiquidCrystal lcd1(RS, E1, D4, D5, D6, D7);
LiquidCrystal lcd2(RS, E2, D4, D5, D6, D7);
const int BEAM = 4;   

void drawOnLcd1(int p, bool on) {
  if (p < 0 || p >= 32) return;      
  byte ch = on ? 255 : ' ';
  if (p < 16) {
    lcd1.setCursor(p, 1);
    lcd1.write(ch);
  } else {
    lcd1.setCursor(p - 16, 0);
    lcd1.write(ch);
  }
}

void drawOnLcd2(int p, bool on) {
  if (p < 0 || p >= 16) return;      
  byte ch = on ? 255 : ' ';
  if (p < 8) {
    lcd2.setCursor(p, 0);
    lcd2.write(ch);
  } else {
    lcd2.setCursor(p - 8, 1);
    lcd2.write(ch);
  }
}

void setup() {
  lcd1.begin(16, 2);
  lcd2.begin(8, 2);
  lcd2.setCursor(0, 0);
  lcd2.print("GELLO");
  delay(200);
  lcd1.clear();
  lcd2.clear();
}

void loop() {
  for (int head = 0; head < 32 + BEAM; head++) {
    drawOnLcd1(head, true);          
    drawOnLcd1(head - BEAM, false);  
    delay(80);
  }
  for (int head = 0; head < 16 + BEAM; head++) {
    drawOnLcd2(head, true);
    drawOnLcd2(head - BEAM, false);
    delay(80);
  }
}
