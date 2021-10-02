# define ButtonPin 2
# define limswitch1 10 //upstairs
# define limswitch2 13 //top
# define limswitch3 12 //downstairs
# define limswitch4 11 //bottom
# define motorpin 9 //speed
# define directionpin 8 //HIGH downstairs

# define Trig 4
# define Echo 5

//Button for stop/start
bool buttonState;
bool lastbuttonstate;

//State of the motor
bool motorState=LOW;

int pwmspeed = 0;
const int maxspeed = 250; //between 0 and 255

long duration = 1000;
int Ultradistance;   // variable for storing the distance the bar is from an object using the ultrasonics. 
const int distance = 20;

void setup(){           // void setup is only run once at the very beginning. 
  
pinMode(ButtonPin,INPUT);
pinMode(limswitch1,INPUT);
pinMode(limswitch2,INPUT);
pinMode(limswitch3,INPUT);
pinMode(limswitch4,INPUT);

pinMode(directionpin, OUTPUT);
pinMode(motorpin, OUTPUT);

pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);

lastbuttonstate = digitalRead(ButtonPin);

Serial.begin(9600);
}

void loop()
{
  bool switch1 = digitalRead(limswitch1);
  bool switch2 = digitalRead(limswitch2);
  bool switch3 = digitalRead(limswitch3);
  bool switch4 = digitalRead(limswitch4);
  if(switch1==HIGH&&switch2==HIGH){
    digitalWrite(directionpin,HIGH);
    while(switch3==LOW){
      analogWrite(motorpin, 0);
      pwmspeed = 0;
      switch3 = digitalRead(limswitch3);
    }
  } else if(switch3==HIGH&&switch4==HIGH){
    digitalWrite(directionpin,LOW);
    while(switch1==LOW){
      analogWrite(motorpin, 0);
      pwmspeed = 0;
      switch1 = digitalRead(limswitch1);
    }
  }
  
  buttonState = digitalRead(ButtonPin);
  if(buttonState!=lastbuttonstate){
    Buttonfunt();
    lastbuttonstate = buttonState;
  }
  
if(motorState==HIGH){
      Ultrasonics();
}
else {
 analogWrite(motorpin, 0);
}
Serial.println(Ultradistance);
}

void Buttonfunt(){
  if(motorState==HIGH){
    motorState=LOW;
  }
  if(motorState==LOW){
    motorState=HIGH;
  }
}

 long DistanceMeasure(void)
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);    // sends a signal for at least 10 Micros.
  
  digitalWrite(Trig,LOW);
  
  duration = pulseIn(Echo,HIGH);// measures how long it takes for the signal to get back.

  duration = ((duration/2)*340*0.000001*100); // divides that time in two to get the time from the bar to the person. 
             // multiplies it by the speed of sound (340 m/s) then *10^-6 to convert from micro secounds to secounds.
       
  if(duration >=100){
    return distance;
  } else {
  return duration;          // returns the distance. in cm 
  }
}
  
void Ultrasonics(){
   Ultradistance=DistanceMeasure();    //calls the function and stores it 
   delay(10);  

   if (Ultradistance<=distance) {
      pwmspeed+=30;
      if (pwmspeed>=maxspeed){
      pwmspeed=0;      
      //want to lock it up here at a stop until the on button is pressed
      motorState==LOW;
      while(motorState==LOW){
        buttonState = digitalRead(ButtonPin);
        analogWrite(motorpin, 0);
        if(buttonState!=lastbuttonstate){
         Buttonfunt();
         lastbuttonstate = buttonState;
         delay(10);
        }
       }
      }
   else if(Ultradistance>=distance){
      pwmspeed-=40;
      if(pwmspeed<=0)
      pwmspeed=0;
   }
 analogWrite(motorpin, pwmspeed);
   }
}
