#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
//time duration definition
#define minutes_25 1500000
#define minutes_5   300000
#define minutes_15  900000
//output pins 
#define red 8
#define yellow 9
#define green 10
#define blue 11
//input pin 
#define show 12
//buzzer
#define buzzer 3
#define start 7
//some variables 
int adress=0;
int hmd,rd;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  setting_of_io();
  hmd=rad(adress); 
	// initialize the LCD
	lcd.begin();
	lcd.backlight();
}

void loop()
{  lcd.setCursor(0,0);
   lcd.print("Are you ready           ");
   lcd.setCursor(0,1);
   lcd.print("Let's do this            ");
   if(!digitalRead(start)){
    three_times();
   }
   while(!digitalRead(show)){
   lcd.setCursor(0,0);
   lcd.print("Your score is:");
   lcd.print(hmd);
   lcd.print("                    ");
   lcd.setCursor(0,1);
   lcd.print("Keep doing          ");
 }
}




void store(int data){
  EEPROM.write(adress,data);
  
}
int rad(int adress){
  rd=EEPROM.read(adress);
  return rd;
}

void three_times(){
  
  music();
  digitalWrite(red,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   25 MINUTES        ");
  delay(minutes_25);
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   5 MINUTES          ");
  delay(minutes_5);
  digitalWrite(blue,LOW);


  music();
  digitalWrite(yellow,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   25 MINUTES         ");
  delay(minutes_25);
  digitalWrite(yellow,LOW);
  digitalWrite(blue,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   5 MINUTES           ");
  delay(minutes_5);
  digitalWrite(blue,LOW);



  music();
  digitalWrite(green,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   25 MINUTES        ");
  delay(minutes_25);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  lcd.setCursor(0,0);
  lcd.print("   15 MINUTES          ");
  delay(minutes_15);
  digitalWrite(blue,LOW);
  int increment=rad(adress);
  increment++;
  store(increment);
  hmd=increment;

  music();
  lcd.setCursor(0,0);
  lcd.print("YOU SUCCESSFULLY DONE        ");
  lcd.setCursor(0,1);
  lcd.print("TO BE OR NOT TO BE           ") ;
  int i;
  for(i=0;i<10;i++){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);

    delay(500);
    
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay(500);
  }
  

  
}
void setting_of_io(){
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(show,INPUT_PULLUP);
  pinMode(start,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
 
}

void music(){
      tone(buzzer,2000);
      delay(500);
      noTone(buzzer);
}
