#include <Wire.h> 
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <RFID.h>
#define SDA_DIO 9
#define RESET_DIO 8
#define ileriButon 14
#define enterButon 15
#define geriButon 16
#define exitButon 17
#define dolumMotor1 18
int userID;
int dataRead = 0;
int dataWrite = 0;
int writeAdr = 0;
int durum1 = 0;
int durum2 = 0;
int durum3 = 0;
int durum4 = 0;
int sayac1 = 1;
int userTo = 0;
int anaDurum = 0;
RFID RC522(SDA_DIO, RESET_DIO); 
LiquidCrystal_I2C lcd(0x27,16,2);
byte USER1[5] = {10,
                 111,
                 143,
                 35,
                 201};
byte USER2[5] = {250,
                 226,
                 147,
                 34,
                 169};
byte USER3[5] = {17,
                 77,
                 80,
                 46,
                 34};
byte USER4[5] = {17,
                 73,
                 19,
                 46,
                 101};
byte USER5[5] = {225,
                 248,
                 30,
                 45,
                 42};
byte kartID[5];

void setup() {
  SPI.begin(); 
  RC522.init();
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("BASLATILIYOR");
  lcd.setCursor(3,1);
  lcd.print("BEKLEYINIZ");
  pinMode(ileriButon,INPUT);
  pinMode(enterButon,INPUT);
  pinMode(geriButon,INPUT);
  pinMode(exitButon,INPUT);
  pinMode(dolumMotor1,OUTPUT);
  digitalWrite(dolumMotor1,LOW);
  delay(3000);
  lcd.clear();
}
/////////////////////////////////////////******************************* BAKIYE BASLANGIC *///////////////////////////////////////////////
int bakiyeDolum(int money){
  durum4 = digitalRead(exitButon);
  if(durum4 > 0 ){
    sayac1 = 1;
    lcd.clear(); 
    delay(250); 
    anaDurum = 2;
  }  
  if (money == 5){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead <= 145){
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("ONCEKI BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead);
      delay(3000);
      dataWrite = dataRead + 5;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("TOPLAM BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(3,0); 
      lcd.print("BAKIYENIZ"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("BAKIYE 150'DEN"); 
      lcd.setCursor(2,1); 
      lcd.print("FAZLA OLAMAZ"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (money == 10){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead <= 140){
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("ONCEKI BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead);
      delay(3000);
      dataWrite = dataRead + 10;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("TOPLAM BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(3,0); 
      lcd.print("BAKIYENIZ"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("BAKIYE 150'DEN"); 
      lcd.setCursor(2,1); 
      lcd.print("FAZLA OLAMAZ"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (money == 25){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead <= 125){
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("ONCEKI BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead);
      delay(3000);
      dataWrite = dataRead + 25;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("TOPLAM BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(3,0); 
      lcd.print("BAKIYENIZ"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("BAKIYE 150'DEN"); 
      lcd.setCursor(2,1); 
      lcd.print("FAZLA OLAMAZ"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (money == 50){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead <= 100){
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("ONCEKI BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead);
      delay(3000);
      dataWrite = dataRead + 50;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("TOPLAM BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(3,0); 
      lcd.print("BAKIYENIZ"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("BAKIYE 150'DEN"); 
      lcd.setCursor(2,1); 
      lcd.print("FAZLA OLAMAZ"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (money == 100){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead <= 50){
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("ONCEKI BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead);
      delay(3000);
      dataWrite = dataRead + 100;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("TOPLAM BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(3,0); 
      lcd.print("BAKIYENIZ"); 
      lcd.setCursor(6,1); 
      lcd.print(dataRead); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("BAKIYE 150'DEN"); 
      lcd.setCursor(2,1); 
      lcd.print("FAZLA OLAMAZ"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  delay(500);
  anaDurum = 2;
  sayac1 = 1;
  
}

int bakiyeMenu(){
  
sayac1 = 1;
  while (anaDurum == 1){
  durum1 = digitalRead(ileriButon);
  durum2 = digitalRead(geriButon);
  durum3 = digitalRead(enterButon);
  durum4 = digitalRead(exitButon);
  if(durum1 > 0 ){
    sayac1 ++; 
    delay(250); 
    lcd.clear();  
  } 
  if(durum4 > 0 ){
    sayac1 = 1;
    lcd.clear(); 
    delay(250); 
    anaDurum = 2;
  }  
  if(sayac1 > 5){ 
    sayac1=5; 
    delay(250); 
    lcd.clear(); 
  }
  if(sayac1 > 1){ 
    if(durum2 > 0) {
      sayac1 --; 
      delay(250); 
      lcd.clear();  
    } 
  } 
  if(sayac1 < 0) { 
    if(durum2 > 0){ 
      sayac1=1; 
      delay(250); 
      lcd.clear(); 
    }  
  }
      switch(sayac1){
          case 1: 
            lcd.setCursor(5,0); 
            lcd.print("5 TL"); 
            lcd.setCursor(4,1); 
            lcd.print("YUKLEME");
            if(durum3 > 0) {
              delay(500); 
              bakiyeDolum(5);  
              break;
            } 
            else{
              break;
            }
            if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 2: 
            lcd.setCursor(5,0); 
            lcd.print("10 TL"); 
            lcd.setCursor(4,1); 
            lcd.print("YUKLEME");
            if(durum3 > 0) {
              delay(500); 
              bakiyeDolum(10); 
              break;
          } 
          else{
              break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 3: 
            lcd.setCursor(5,0); 
            lcd.print("25 TL"); 
            lcd.setCursor(4,1); 
            lcd.print("YUKLEME");
          if(durum3 > 0) { 
            delay(500); 
            bakiyeDolum(25); 
            break;
          } 
          else{
            break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 4: 
          lcd.setCursor(5,0); 
          lcd.print("50 TL"); 
          lcd.setCursor(4,1); 
          lcd.print("YUKLEME");
          if(durum3 > 0) { 
            delay(500); 
            bakiyeDolum(50); 
            break;
          } 
          else{
            break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 5:
            lcd.setCursor(5,0); 
            lcd.print("100 TL"); 
            lcd.setCursor(4,1); 
            lcd.print("YUKLEME");
          if(durum3 > 0) { 
            delay(500); 
            bakiyeDolum(100); 
            break;
            } 
          else{
              break;
            }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          }  
      }
  }
}
/////////////////////////////////////************************* BAKIYE BITIS *****************************////////////////////////////////////////////////////////////


////////////////////////////////////******************************DOLUM BASLANGIC ***************************//////////////////////////////////////////////

int dolum(float miktar, int icecekID){
  if (miktar == 0.5){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead >= 2){
      dataWrite = dataRead - 2;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("KALAN BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      if(icecekID == 1){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 1"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(15500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      else if(icecekID == 2){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 2"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(15500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1);  
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      miktar = 0;
      icecekID = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(4,0); 
      lcd.print("YETERSIZ"); 
      lcd.setCursor(5,1); 
      lcd.print("BAKIYE"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (miktar == 1.0){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead >= 4){
      dataWrite = dataRead - 4;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("KALAN BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      if(icecekID == 1){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 1"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(31000);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      else if(icecekID == 2){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 2"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(31000);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      miktar = 0;
      icecekID = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(4,0); 
      lcd.print("YETERSIZ"); 
      lcd.setCursor(5,1); 
      lcd.print("BAKIYE"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (miktar == 1.5){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead >= 6){
      dataWrite = dataRead - 6;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("KALAN BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      if(icecekID == 1){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 1"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(46500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      else if(icecekID == 2){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 2"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(46500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      miktar = 0;
      icecekID = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(4,0); 
      lcd.print("YETERSIZ"); 
      lcd.setCursor(5,1); 
      lcd.print("BAKIYE"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (miktar == 2.5){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead >= 10){
      dataWrite = dataRead - 10;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("KALAN BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      if(icecekID == 1){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 1"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(77500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      else if(icecekID == 2){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 2"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(77500);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      miktar = 0;
      icecekID = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(4,0); 
      lcd.print("YETERSIZ"); 
      lcd.setCursor(5,1); 
      lcd.print("BAKIYE"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  if (miktar == 5.0){
    writeAdr = userTo;
    dataRead = EEPROM.read(writeAdr);
    if(dataRead >= 15){
      dataWrite = dataRead - 15;
      EEPROM.write(writeAdr, dataWrite);
      lcd.clear();
      lcd.setCursor(2,0); 
      lcd.print("KALAN BAKIYE"); 
      lcd.setCursor(6,1); 
      lcd.print(dataWrite);
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      if(icecekID == 1){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 1"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(155000);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      else if(icecekID == 2){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(miktar); 
        lcd.setCursor(4,0); 
        lcd.print("LT ICECEK 2"); 
        lcd.setCursor(2,1); 
        lcd.print("DOLDURULUYOR");
        digitalWrite(dolumMotor1, HIGH);
        delay(155000);
        digitalWrite(dolumMotor1, LOW);
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("DOLUM TAMAMLANDI"); 
        lcd.setCursor(1,1); 
        lcd.print("YINE BEKLERIZ.");
        delay(3000);
      }
      miktar = 0;
      icecekID = 0;
      lcd.clear();
    }
    else{
      lcd.clear();
      lcd.setCursor(4,0); 
      lcd.print("YETERSIZ"); 
      lcd.setCursor(5,1); 
      lcd.print("BAKIYE"); 
      delay(3000);
      writeAdr = 0;
      dataRead = 0;
      dataWrite = 0;
      lcd.clear();
    }
  }
  delay(500);
  anaDurum = 0;
  sayac1 = 1;
}
int icecekMenu(float litre){
sayac1 = 1;
while (anaDurum == 1){
  durum1 = digitalRead(ileriButon);
  durum2 = digitalRead(geriButon);
  durum3 = digitalRead(enterButon);
  durum4 = digitalRead(exitButon);
  if(durum1 > 0 ){
    sayac1 ++; 
    delay(250); 
    lcd.clear();  
  }
  if(durum4 > 0 ){
    sayac1 = 1;
    delay(250); 
    lcd.clear(); 
    anaDurum = 2;
  }  
  if(sayac1 > 2){ 
    sayac1=2; 
    delay(250); 
    lcd.clear(); 
  }
  if(sayac1 > 1){ 
    if(durum2 > 0) {
      sayac1 --; 
      delay(250); 
      lcd.clear();  
    } 
  } 
  if(sayac1 < 0) { 
    if(durum2 > 0){ 
      sayac1=1; 
      delay(250); 
      lcd.clear(); 
    }  
  }
      switch(sayac1){
          case 1: 
            lcd.setCursor(5,0); 
            lcd.print("ICECEK"); 
            lcd.setCursor(7,1); 
            lcd.print("1");
            if(durum3 > 0) {
              delay(500); 
              lcd.clear(); 
              dolum(litre,1);
              break;
            } 
            else{
              break;
            }
            if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 2: 
            lcd.setCursor(5,0); 
            lcd.print("ICECEK"); 
            lcd.setCursor(7,1); 
            lcd.print("2");
          if(durum3 > 0) {
            delay(500); 
            lcd.clear();
            dolum(litre,2);
            break;
          } 
          else{
              break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
      }
}
}


int dolumMenu(){
  sayac1 = 1;
while (anaDurum == 1){
  durum1 = digitalRead(ileriButon);
  durum2 = digitalRead(geriButon);
  durum3 = digitalRead(enterButon);
  durum4 = digitalRead(exitButon);
  if(durum1 > 0 ){
    sayac1 ++; 
    delay(250); 
    lcd.clear();  
  }
  if(durum4 > 0 ){
    sayac1 = 1;
    delay(250); 
    lcd.clear(); 
    anaDurum = 2;
  }  
  if(sayac1 > 5){ 
    sayac1=5; 
    delay(250); 
    lcd.clear(); 
  }
  if(sayac1 > 1){ 
    if(durum2 > 0) {
      sayac1 --; 
      delay(250); 
      lcd.clear();  
    } 
  } 
  if(sayac1 < 0) { 
    if(durum2 > 0){ 
      sayac1=1; 
      delay(250); 
      lcd.clear(); 
    }  
  }
      switch(sayac1){
          case 1: 
            lcd.setCursor(4,0); 
            lcd.print("0.5 LT"); 
            lcd.setCursor(3,1); 
            lcd.print("DOLDURMA");
            if(durum3 > 0) {
              delay(500); 
              lcd.clear();
              icecekMenu(0.5);  
              break;
            } 
            else{
              break;
            }
            if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 2: 
            lcd.setCursor(4,0); 
            lcd.print("1.0 LT"); 
            lcd.setCursor(3,1); 
            lcd.print("DOLDURMA");
          if(durum3 > 0) {
            delay(500); 
            lcd.clear();
            icecekMenu(1.0); 
            break;
          } 
          else{
              break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 3: 
            lcd.setCursor(4,0); 
            lcd.print("1.5 LT"); 
            lcd.setCursor(3,1); 
            lcd.print("DOLDURMA");
          if(durum3 > 0) { 
            delay(500); 
            lcd.clear();
            icecekMenu(1.5); 
            break;
          } 
          else{
            break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 4: 
          lcd.setCursor(4,0); 
          lcd.print("2.5 LT"); 
          lcd.setCursor(3,1); 
          lcd.print("DOLDURMA");
          if(durum3 > 0) { 
            delay(500); 
            lcd.clear();
            icecekMenu(2.5); 
            break;
          } 
          else{
            break;
          }
          if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
          case 5:
            lcd.setCursor(4,0); 
            lcd.print("5.0 LT"); 
            lcd.setCursor(3,1); 
            lcd.print("DOLDURMA");
          if(durum3 > 0) { 
            delay(500); 
            lcd.clear();
            icecekMenu(5.0); 
            break;
            } 
            else{
              break;
            }
            if(durum4 > 0 ){
             sayac1 = 1;
             lcd.clear(); 
             delay(250); 
            anaDurum = 2;
          } 
      }
}
}

/////////////////////////////*************************************** DOLUM BITIS ***********************************/////////////////////////////////////////////////////

void loop() {
  if(anaDurum == 0){
      lcd.setCursor(0,0);
      lcd.print("LUTFEN KARTINIZI");
      lcd.setCursor(3,1);
      lcd.print("OKUTUNUZ");
    if (RC522.isCard()) {
      RC522.readCardSerial();
      for(int i=0;i<=5;i++){ 
        kartID[i] = RC522.serNum[i]; 
        RC522.serNum[i] = 0;
      }
      
    if( kartID[0] == USER1[0] && kartID[1] == USER1[1] && kartID[2] == USER1[2] && kartID[3] == USER1[3] && kartID[4] == USER1[4] ) {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("KULLANICI 1");
        userTo = 1;
        delay(3000);
        anaDurum = 1;
        lcd.clear();
    }
    else if( kartID[0] == USER2[0] && kartID[1] == USER2[1] && kartID[2] == USER2[2] && kartID[3] == USER2[3] && kartID[4] == USER2[4] ){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("KULLANICI 2");
        userTo = 2;
        delay(3000);
        anaDurum = 1;
        lcd.clear();
    }
    else if( kartID[0] == USER3[0] && kartID[1] == USER3[1] && kartID[2] == USER3[2] && kartID[3] == USER3[3] && kartID[4] == USER3[4] ){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("KULLANICI 3");
        userTo = 3;
        delay(3000);
        anaDurum = 1;
        lcd.clear();

    }
    else if( kartID[0] == USER4[0] && kartID[1] == USER4[1] && kartID[2] == USER4[2] && kartID[3] == USER4[3] && kartID[4] == USER4[4] ){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("KULLANICI 4");
        userTo = 4;
        delay(3000);
        anaDurum = 1;
        lcd.clear();

    }
    else if( kartID[0] == USER5[0] && kartID[1] == USER5[1] && kartID[2] == USER5[2] && kartID[3] == USER5[3] && kartID[4] == USER5[4] ){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("KULLANICI 5");
        userTo = 5;
        delay(3000);
        anaDurum = 1;
        lcd.clear();

    }
    else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("KAYITLI OLMAYAN");
        lcd.setCursor(4,1);
        lcd.print("KART");
        anaDurum = 0;
        delay(3000);
        lcd.clear();
       }
  }
}
  else if (anaDurum == 1 || anaDurum == 2){
    if(anaDurum ==2){
      lcd.clear();
      delay(50);
      anaDurum = 1;
    }
  anaDurum = 1;
  durum1 = digitalRead(ileriButon);
  durum2 = digitalRead(geriButon);
  durum3 = digitalRead(enterButon);
  durum4 = digitalRead(exitButon);
  if(durum1 > 0){
    sayac1 ++;
    delay(250);
    lcd.clear();
  }
 
  if(sayac1 > 2){ 
    sayac1=2;
    delay(250); 
    lcd.clear();
  }
  if(durum2 > 0){
    sayac1 --; 
    delay(250); 
    lcd.clear(); 
  }
  if(sayac1 < 1){ 
    sayac1=1; 
    delay(250); 
    lcd.clear();
  }
  if(durum4 > 0 ){
    lcd.clear();
    while(digitalRead(enterButon) == 0|| digitalRead(exitButon) == 0){
      delay(200);
      lcd.setCursor(5,0);  
      lcd.print("CIKIS"); 
      lcd.setCursor(2,1); 
      lcd.print("YAPILSIN MI ?"); 
      durum3 = digitalRead(enterButon);
      durum4 = digitalRead(exitButon);
      if(durum3>0){
        delay(150); 
        anaDurum = 0;
        lcd.clear();
        break;
      }
      else if (durum4 >0){
        delay(150); 
        anaDurum = 1;
        lcd.clear();
        break;
      } 
   }    
  }
      switch(sayac1){
          case 1:  
          lcd.setCursor(5,0);  
          lcd.print("DOLUM"); 
          lcd.setCursor(5,1); 
          lcd.print("YAPMA");
          if(durum3 > 0){
             delay(250); 
             lcd.clear();
             dolumMenu(); 
             break;
          } 
          else{
             break;
          }  
          case 2:  
          lcd.setCursor(4,0);  
          lcd.print("BAKIYE"); 
          lcd.setCursor(4,1); 
          lcd.print("YUKLEME");
          if(durum3 > 0){
             delay(250); 
             lcd.clear();
             bakiyeMenu(); 
             break;
          } 
          else{
              break;
          }
            
      }
  }
}
