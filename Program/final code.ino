#define trigPin 9            //sensor A
#define echoPin 10          //sensor A
#define btrigPin 7          //sensor B
#define bechoPin 8         //sensor B
#define LED 11
#define LED2 12

unsigned long blinkTime = 0;

void blink(void)
{  static int x = 0;                   /* Current LED state 0=>off, 1=>on     */
   digitalWrite(LED,x ^= 1);           /* Set LED to opposite state           */
   blinkTime = millis();               /* Schedule next state change          */
}
void watch(void)
{  if (millis() - blinkTime >= 1)    /* If it's time to change state        */
      blink();                         /*  then go do it                      */
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(btrigPin, OUTPUT);
  pinMode(bechoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  int bduration, bdistance;
  digitalWrite(btrigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(btrigPin, LOW);
  bduration = pulseIn(bechoPin, HIGH);
  bdistance = (bduration/2) / 29.1;
  
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance >= 3 && distance <= 40)
  {
 
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(LED, HIGH);
  }
  
   if (bdistance >= 3 && bdistance <= 40)
  {
 
   
    digitalWrite(LED2, HIGH);
  }
  
  else {
     Serial.println("Out of range");
     digitalWrite(LED, LOW);
     digitalWrite(LED2, LOW);
  }
  delay(500);
}