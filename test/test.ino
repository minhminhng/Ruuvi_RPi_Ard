void lightLED();
void recvInfor();
int receivedChar = 0;
int receivedCom = 0;
boolean newData = false;
byte msg[2];

void setup() {

  Serial.begin(9600);

  pinMode(3, OUTPUT);
//  pinMode(5, OUTPUT);
 // pinMode(6, OUTPUT);
  
}

void loop() {

  recvInfo();
  lightLED();
  
}

void recvInfo() {
  int av = Serial.available();

  if (av > 0) {
    //byte msg[2] = {0};
    for (int i = 0; i < 2; i++){
      msg[i] = Serial.read();
      newData = true;
      Serial.read();
    }
  }
  
}

void lightLED() {


  while(newData == true) {
    Serial.print("Temperature ");
    Serial.println(msg[0]);
    Serial.print("Humidity ");
    Serial.println(msg[1]);
    digitalWrite(7, HIGH);
   // delay(2000);
   // digitalWrite(7, LOW);
   newData = false;
  }
  
}
