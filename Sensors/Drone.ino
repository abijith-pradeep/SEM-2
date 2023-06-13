#include <Servo.h>
int trigPin = 5;
int echoPin1 = 3;
int echoPin2 = 2;
long duration, cm1, cm2;
Servo myservo;
int pos = 0;

void setup()
{
  	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin1, INPUT);
	pinMode(echoPin2, INPUT);
	myservo.attach(A2);
}

void loop()
{
	// Code for UltraSonic Sensor 1
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	pinMode(echoPin1, INPUT);
	duration = pulseIn(echoPin1, HIGH);
	cm1 = duration * 17050;
	delay(100);

// Code for UltraSonic Sensor 2
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(trigPin, HIGH);
 	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	pinMode(echoPin2, INPUT);
	duration = pulseIn(echoPin2, HIGH);
	cm2 = duration * 17050;
	delay(100);
  
// Code for rotating the Servo Motor
  for (pos = 0; pos <= 180; pos += 1) {
		myservo.write(pos);
		delay(10);
	}
	for (pos = 180; pos >= 0; pos -= 1) {
		myservo.write(pos);
		delay(10);
	}
  
}
