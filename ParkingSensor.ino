int trig=6;                                                   //Trig pin is D6
int echo=5;                                                   //Echo pin is D5
int buzzer=13;                                                //buzzer attached to pin 13
int ledPin=10;                                                //LED attached to pin 10
float distance;
float speedOfSound=340.;                                      //speed of sound in m/s

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);                                         //Start the serial port
}

void loop() {
  // put your main code here, to run repeatedly:
  //Creating the outgoing Pulse through the trig Pin
  digitalWrite(trig,LOW);
  delayMicroseconds(2000);                                    //Allow the low sinal to settle
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);                                      //Allow the high signal to settle
  digitalWrite(trig,LOW);
  delayMicroseconds(10);

  float pingTime=pulseIn(echo,HIGH);                          //Time taken by pulse to return in microseconds
  speedOfSound=340./25000.;                                   //speed of sound in inches/microseconds
  distance=(speedOfSound*pingTime)/2.0;                       //This gives the distance

  Serial.print(distance);
  Serial.println(" inches");

  if(distance>=50.0)                                          //Object more than 50 inches away from the obstacle and less rapid buzzing
  {
    tone(buzzer,1000);
    digitalWrite(ledPin,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(ledPin,LOW);
    delay(1000);
  }

   if(distance>=25.0 && distance<50.0)                        //Object more than 25 inches away but less than 50 inches from the obstacle and more rapid buzzing
  {
    tone(buzzer,1000);
    digitalWrite(ledPin,HIGH);
    delay(500);
    noTone(buzzer);
    digitalWrite(ledPin,LOW);
    delay(500);
  }

   if(distance<25.0 && distance>=5.0)                        //Object more than 5 inches away but less than 25 inches from the obstacle and very rapid buzzing
  {
    tone(buzzer,1000);
    digitalWrite(ledPin,HIGH);
    delay(200);
    noTone(buzzer);
    digitalWrite(ledPin,LOW);
    delay(200);
  }

  if(distance<5.0)                                           //Object less than 5 inches away from the obstacle and constant buzzing
  {
    tone(buzzer,1000);
    digitalWrite(ledPin,HIGH);
  }

  if(distance==0.0)
  {
    noTone(buzzer);
    digitalWrite(ledPin,LOW);
  }

}
