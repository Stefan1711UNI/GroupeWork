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
  blink();  //function for light to blink
  menu();   //menu function
}

//sum function
int sumNum(int x, int y) 
{
  return x + y;
}

//turns led on and off
void blink()
{
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on 
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 
  delay(1000);                      // wait for a second
}

//function to do either add or multiply
void menu()
{
  int userAnswer=0;
  Serial.print("1=Sum calculation\t2=Multiplication:\n"); //asks user what they will do
  while(Serial.available() == 0);
    userAnswer = Serial.parseInt();

  if(userAnswer == 1)   //1 = Summing 
  {
    int num1=0;   
    int num2=0;

    Serial.print("Enter digit 1:\n");   //user enters first digit
    while(Serial.available() == 0);
      num1 = Serial.parseInt();

    Serial.print("Enter digit 2:\n");   //user enters second digit
    while(Serial.available() == 0);
      num2 = Serial.parseInt();

    //gets the sum and displays it
    int sum = sumNum(num1, num2);   //calls the function to sum

    Serial.print("Sum of ");      //prints "Sum of num1 + num2 = answer"
    Serial.print(num1);
    Serial.print(" + ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.print(sum);
    Serial.print("\n");

  } 
  else if(userAnswer == 2)  //multiply
  {
    int num1=0;
    int num2=0;
    Serial.print("Enter digit 1:\n");   //user enters first digit
    while(Serial.available() == 0);
      num1 = Serial.parseInt();

    Serial.print("Enter digit 2:\n");   //user enters second digit
    while(Serial.available() == 0);
      num2 = Serial.parseInt();

    //TODO
    //add function to multiply, with int value of answer called sum. Like in sum


    //prints "Multiply of num1 * num2 = answer"
    Serial.print("Sum of ");      
    Serial.print(num1);
    Serial.print(" * ");
    Serial.print(num2);
    Serial.print(" = ");
    //Serial.print(sum);
    Serial.print("\n");
  }
  else  //displays error if the user didnt enter 1 or 2
  {
    Serial.print("ERROR! Type either 1 or 2.\n");
  }
}