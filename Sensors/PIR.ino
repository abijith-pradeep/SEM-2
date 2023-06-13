int piezoPin = 7;

int senseValue;
float voltage;
float temperature;

int pir = 12;
int pirState = LOW; // Initial PIR State
int val = 0; // Reads the pin status
int stor = 0; // Stores the pin gesture

void setup() {
	Serial.begin(9600);
	pinMode(piezoPin, OUTPUT);
  
  	pinMode(9, OUTPUT);
  	pinMode(10, OUTPUT);
  	pinMode(11, OUTPUT);
   	Serial.begin(9600);
  	
  	pinMode(pir, INPUT);
  	Serial.begin(9600);
}

void loop() {
	//Temperature Sensor
  	senseValue = analogRead(A0);
	voltage = ((senseValue/1023.0)*5.0);
	temperature = (voltage-0.5)*100;
	Serial.print(temperature);
  	Serial.print(" degree Celcius");
  	Serial.println();
	delay(100);

//LED Temperature Indication
if (temperature <=10 || temperature >=100) {
 		digitalWrite(11, HIGH);
 		delay(500);
   	digitalWrite(11, LOW);
 		delay(200);
  }
else if (temperature >=50 && temperature <100) {
    digitalWrite(10, HIGH);
  	delay(500);
    digitalWrite(10, LOW);
  	delay(200);
  }
else {
  	digitalWrite(9, HIGH);
  	delay(500);
    digitalWrite(9, LOW);
  	delay(200); 
 }
  
//PIR Sensor Code for Gesture Control
	// Code for varied buzz frequencies from buzzer
	// in different conditions
  	val = digitalRead(pir);
  	if (val == LOW){
    	Serial.print("Gesture 1 detected!");
        tone(piezoPin, 5000);
		delay(250);
		noTone(piezoPin);
		delay(250);
        Serial.print("\t"); Serial.print("Person is Safe!");
      	Serial.println();
    }
 
 	else if (val == HIGH){
    	Serial.print("Gesture 2 detected!");
        tone(piezoPin, 1000);
		delay(250);
		noTone(piezoPin);
		delay(250);
        Serial.print("\t"); Serial.print("Person needs Medical Attention!");
      	Serial.println();
    }
}
