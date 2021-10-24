//Prateek
//www.prateeks.in

#include <SoftwareSerial.h>
#include <Wire.h> 
SoftwareSerial mySerial(9,8);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int reedPin = 14;
const int ledPin = 13;
const int buzzer = 5;
bool switchState = HIGH;

void setup() 
{
  mySerial.begin(9600); 
  Serial.begin(9600); 
  lcd.init();
  lcd.backlight();
  pinMode(reedPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ledPin, LOW);

  lcd.setCursor(2,0);
  lcd.print ("WELCOME TO  ");
  lcd.setCursor(2,1);
  lcd.print ("JUSTDOELECTRONICS");
  lcd.setCursor(6,2);
  lcd.print ("DESIGN By :-");
  lcd.setCursor(6,3);
  lcd.print ("PRATEEK");
  delay(3000);
  lcd.clear();
  
}

void loop() 
{
 switchState = digitalRead(reedPin);
 if (switchState == LOW) 
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, LOW);
    Serial.println("Reed Switch is Closed. LED is ON");
    //lcd.clear();
    lcd.setCursor(1,1);
    lcd.print("Reed Switch Closed");
    lcd.setCursor(4,2);
    lcd.print("IS Normal");
    lcd.setCursor(10,3);
    lcd.print("........");

  } 
 else
  {
   digitalWrite(ledPin, LOW);
      digitalWrite(buzzer, HIGH);
   Serial.println("Reed Switch Open. LED is OFF");

    lcd.setCursor(1,1);
    lcd.print("Reed Switch Open");
    lcd.setCursor(4,2);
    lcd.print("IS Danger");
    lcd.setCursor(10,3);
    lcd.print("SMS Sent");
    
    

   Serial.println("I am in send");
   mySerial.println("AT+CMGF=1"); 
   delay(1000); 
   mySerial.println("AT+CMGS=\"+919975617490\"\r"); 
   delay(1000);
   mySerial.println("Reed Switch Open IS Danger");
   delay(100);
   mySerial.println((char)26);
   delay(1000);

  } 
}
