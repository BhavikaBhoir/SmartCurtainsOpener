// C++ code
//

//sets the value of morning to be true
//when morning = 0 it is night
int morning = 1;

void setup() 
{
  	//sets input pins and output pins for different sensors
  	//and motors
	pinMode(13, OUTPUT);
    pinMode(12, INPUT_PULLUP);
  	pinMode(11, OUTPUT);
}

void loop()
{
  //while morning is true
  while (morning == 1){
    //if the photo diode reads sunlight
  	if (digitalRead(12) == LOW){
        //sets the motor to run 
      	digitalWrite(13, HIGH);
    	//time for the motor to open to curtains
    	delay(3000);
      	//turns motor off and sets time to night
      	digitalWrite(13, LOW);
      	morning = 0;
 	 }
  	else{
	morning = 1;
    }
  }
  //when night time
  while (morning == 0){
    //if no sun is detected
    if (digitalRead(12) == HIGH){
      //sets motor running in opposite direction 
      digitalWrite(11, HIGH);
      //time for the motor to open the curtains
      delay(3000);
      digitalWrite(11, LOW);
      morning = 1;
    }
    else{
      morning = 0;
    }
  }
}

