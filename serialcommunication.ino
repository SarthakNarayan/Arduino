int  led0 = 0;
int  led1 = 0;
int  led2 = 0;
int  led3 = 0;
int analog = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.println("Hi!, I am Arduino");
}

void ser()
{
  while(!Serial.available());
  led0=Serial.readStringUntil('\t').toInt();
  led1=Serial.readStringUntil('\t').toInt();
  led2=Serial.readStringUntil('\t').toInt();
  led3=Serial.readStringUntil('\t').toInt();
  analog=Serial.readStringUntil('\n').toInt();
  analog=map(analog,-1,1,0,1023);
}


// the loop function runs over and over again forever
void loop() {
  ser();
  digitalWrite(2, led0);     
  digitalWrite(3, led1); 
  digitalWrite(4, led2);     
  //digitalWrite(5, led3);     
    
   analogWrite(5, analog);    
}

