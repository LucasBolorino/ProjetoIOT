#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
int tempPadrao = 24;
byte a[8]= {B00110,B01001,B00110,B00000,B00000,B00000,B00000,B00000,}; 
const int sensorLM35 = A0;      
int i;
float temperaturaC = 0;

void setup() {

  Serial.begin(9600);

  for(i=8; i<12; i++){
    pinMode(i, OUTPUT);
  }

  lcd.begin(16, 2);
  lcd.print("Temp: ");
  lcd.setCursor(0, 2);
  lcd.print("Tensao: ");
  lcd.setCursor(12, 2);
  lcd.print("V");
  lcd.createChar(1, a);
  lcd.setCursor(10,0); 
  lcd.write(1);
}            
void loop() {

  int valorSensor = analogRead(sensorLM35);

  float tensao = (valorSensor/1024.0)*5.0; 
  

  temperaturaC = (tensao) * 100.0; 

  float temperaturaF = (temperaturaC*9)/5 + 32;

  Serial.print("Valor do sensor: ");       
  Serial. print(valorSensor);
  
  Serial.print(", Tensao (V): ");          
  Serial.print(tensao); 
  
  Serial.print(", Celsius: ");
  Serial.print(temperaturaC);
  
  Serial.print(", Fahrenheit: ");
  Serial.println(temperaturaF);
  delay(100); 
  lcd.setCursor(6, 0);
  
  lcd.print(temperaturaC,1);
  lcd.setCursor(8, 1);
  lcd.print(tensao,2); 
  
  if(temperaturaC > tempPadrao){      
    digitalWrite(10, LOW);            
    digitalWrite(11, HIGH); 

  }else if(temperaturaC < tempPadrao){      
    digitalWrite(10, HIGH);            
    digitalWrite(11, LOW);            
        
  }else if(temperaturaC = tempPadrao){  
    digitalWrite(10, HIGH);           
    digitalWrite(11, HIGH);            
  
  delay(1000);
  }
}
