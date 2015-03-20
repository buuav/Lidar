#include <PID_v1.h>

const int echoPin1 = A0, trigPin1 = 10, echoPin2 = A5, trigPin2 = 8;
double dist1 = 0, dist2 = 0, setDist = 100, thrVal = 0;
const int sampleTime = 500;  // Sample time in ms


void setup(){
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
}

void loop(){
  readSensor1();
  readSensor2(); 
   
  delay(sampleTime);
}

long readSensor1(){

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  dist1 = pulseIn(echoPin1, HIGH, 25000)/29/2*10/9;
  
  Serial.print("dist1:");Serial.print(dist1);Serial.print("\t");

}

long readSensor2(){

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  dist2 = pulseIn(echoPin2, HIGH, 25000)/29/2*10/9;

  Serial.print("dist2:");Serial.print(dist2);Serial.print("\n");

}
