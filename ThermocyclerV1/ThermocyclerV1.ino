#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

int pinS = 52;

int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5



void setup()
{
  pinMode(pinS, OUTPUT);
  digitalWrite(pinS, HIGH);

  lcd.begin(16, 2); // inicializa a LCD

  //dados iniciais mostrados na LCD
  lcd.setCursor(0, 0);
  lcd.print("TermoC v1");

  Serial.begin(9600);

  delay(2000);

  digitalWrite(pinS, LOW);
}

void loop()
{
  int sensorValue = analogRead(A8);

  Serial.println(sensorValue);

  float paso =  0.00488;

  float svc = (sensorValue * 0.00488) * 10;

  //svc = map(sensorValue,0, 1024, 0, 5000);

  lcd.setCursor(0, 0);
  lcd.print("teste tempeatura");
  lcd.setCursor(0, 1);
  lcd.print(svc);

  delay(300);
  
  for (int i = 0; i <= 10; i++) {
    digitalWrite(pinS, HIGH);
    delay(3000);
    digitalWrite(pinS, LOW);
    delay(3000);
  }



}


// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;
  return btnNONE;
}




