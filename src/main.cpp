#include <Arduino.h>

// put function declarations here:
int sumNum(int x, int y);
void blink();
void menu();

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  blink();
  menu();
}

//sum function
int sumNum(int x, int y) 
{
  return x + y;
}

//turns led on and off
void blink()
{
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}

//function to do either sum or multi
void menu()
{
  int userAnswer=0;
  Serial.print("1=Sum calculation\t2=Multiplication:\n");
  while(Serial.available() == 0);
    userAnswer = Serial.parseInt();
  if(userAnswer == 1)
  {
    int num1=0;
    int num2=0;
    Serial.print("Enter digit 1:\n");
    while(Serial.available() == 0);
      num1 = Serial.parseInt();
    Serial.print("Enter digit 2:\n");
    while(Serial.available() == 0);
      num2 = Serial.parseInt();
    //gets the sum and displays it
    int sum = sumNum(num1, num2);
    Serial.print("Sum of ");
    Serial.print(num1);
    Serial.print(" + ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.print(sum);

  } 
  else if(userAnswer == 2)
  {
    int num1=0;
    int num2=0;
    Serial.print("Enter digit 1:\n");
    while(Serial.available() == 0);
      num1 = Serial.parseInt();
    Serial.print("Enter digit 2:\n");
    while(Serial.available() == 0);
      num2 = Serial.parseInt();

    //add function to multiply
  }
  else
  {
    Serial.print("ERROR! Type either 1 or 2.\n");
  }
}