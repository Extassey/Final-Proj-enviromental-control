/*
 * James Perrin GE 102
 * Final Project
 */




//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is connected to
//LED Pin
int ledPin2 = 10;   //the pin the LED is connected to
                  //we are controlling brightness so
                  //we use one of the PWM (pulse width
                  // modulation pins)




#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


//LED Pin
int ledPin = 9;   //the pin the LED is connected to
                  //we are controlling brightness so
                  //we use one of the PWM (pulse width
                  // modulation pins)
void setup()
{
  myservo.attach(5);                                            // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);                                          // needed for debugging                              
  pinMode(ledPin, OUTPUT);                         //sets the led pin to output
  pinMode(ledPin2, OUTPUT);                        //sets the led pin to output
}

/*
 * loop() - this function will start after setup
 * finishes and then repeat
 */
void loop()
{
  
  // me marking blocks for personal reasons ****************************************************    
  
   int lightLevel2 = analogRead(lightPin); //Read the light level
   Serial.print(lightLevel2);
    Serial.println(" LightLevel Raw");
        //the photoresistor is not calibrated to any units so
        //this is simply a raw sensor value (relative light)
  lightLevel2 = map(lightLevel2, 340, 850, 200, 600);             // 200 is max light 600 is ambient max darkness
        //adjust the value 0 to 900 to
        //span 0 to 255

  lightLevel2 = constrain(lightLevel2, 200, 600);   //makes sure the
                                                    //value is between
                                                    //200 and 600
  
Serial.print(lightLevel2);                 // these help me track my true sensor value and my digital mapped value based on the true analog input
Serial.println(" LightLevel Mapped");

    // marking blocks ***************************************************

 if (lightLevel2 < 250) {                  // 250 means bright, 450 means dark

     if(pos >= 0; pos -= 10) {             // moves servo -10 untill desired shade is attained
  
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15 ms for the servo to reach the position

    
    
    Serial.print(lightLevel2);
    Serial.println(" LightLevel Mapped");
    Serial.println(pos);

         if (pos < 0) {                        // helps the servo not get stuck at the "0" pos when searching for shade angle
          pos = 180;
          myservo.write(pos);
         }
  }
 }

if (lightLevel2 > 450) {                 // first if statement, if light is too dark will proceed to next if

    if(pos <= 180; pos += 10) {         // if servo is equal to or less than pos 180, servo will increase pos by a value of 10
  
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15 ms for the servo to reach the position
    
     Serial.print(lightLevel2);
     Serial.println(" LightLevel Mapped");
     Serial.println(pos);
      
  }
}

/*
 * These next blocks control the auxilary light which is activated when the ambient light available is not
 * great enough to maintain a mapped light value of less than 450
 */
  if (lightLevel2 > 500) {
        digitalWrite(ledPin2, HIGH);
      
  }
  if (lightLevel2 < 220) {
        digitalWrite(ledPin2, LOW);
      
  }
  delay(50); // so that the sensor updates in 0.050 sec intervals

 
                                 
}
