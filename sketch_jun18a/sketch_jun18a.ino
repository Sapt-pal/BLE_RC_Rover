/*int ledState1 = LOW;
unsigned long prev1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);
  unsigned long now1 = millis();
  if (now1 - prev1 >= 1000) {
    int c = 0;unsigned long prev1_1 = now1;
    while (true) {
      now1 = millis();
      if (now1 - prev1_1 > 1100) {
        if (ledState1 == LOW) {
          ledState1 = HIGH;
        }
        else {
          ledState1 = LOW;
        }
        digitalWrite(LED_BUILTIN, ledState1);
        prev1_1 = now1;c++;
      }
      if (c >= 2) {
        break;
      }
    }
    prev1 = now1;
  }
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  


}
*/

unsigned long previousMillis = 0; // will store last time LED was updated
long interval = 100;           // interval at which to blink (milliseconds)
const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
byte counter = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    if(interval == 1000)
    {
      interval = 100;
      counter = 0;
    }
    previousMillis = currentMillis;
    if (ledState == LOW)
    {
      ledState = HIGH;  //ON
    }
    else
    {
      ledState = LOW; //OFF
    }
    counter++;
    digitalWrite(ledPin, ledState);
    if (counter == 4)
    {
      interval = 1000;
    } 
  }
}
