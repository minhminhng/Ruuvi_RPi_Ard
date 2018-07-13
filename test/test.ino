void lightLED();
void recvInfor();
char msg[6];
int temp = 0;
int humid = 0;

void setup() {

  Serial.begin(9600);

  pinMode(3, OUTPUT);  
}

void loop() {

  recvInfo();
 // lightLED();
  
}

void recvInfo() {
  int av = Serial.available();
    
  if (av >= 6) {
    for (int i = 0; i < 6; i++){
      msg[i] = Serial.read();
    }
    for (int i = 0; i < 6; i++){
      if (msg[i] == 't'){
        temp = (msg[i+1] - '0')*10 + (msg[i+2]- '0');
       
       }
       if (msg[i] == 'h'){
         humid = (msg[i+1] - '0')*10 + (msg[i+2]- '0');
       }
     }
      lightLED(3);
  }
  
}

void lightLED(int led) {


    Serial.print("Temperature ");
    Serial.println(temp);
    Serial.print("Humidity ");
    Serial.println(humid);
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
  
}
