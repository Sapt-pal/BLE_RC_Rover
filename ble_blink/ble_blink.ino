void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char data = Serial.read();
    switch (data) {
      case '0': 
        analogWrite(A0, 200); 
        break;
      case '1': 
        analogWrite(A1, 200);
        break;
      case '2': 
        analogWrite(A2, 200);
        break;
      case '3': 
        analogWrite(A3, 200);
        break;
      default: 
        break;
    }
    Serial.println(data);
  }


}
