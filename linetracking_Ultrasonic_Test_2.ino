#define LS 2 // left sensor
#define RS 3 // right sensor
#define LM1 4 // left motor M1a
#define LM2 5 // left motor M2a
#define RM1 6 // right motor M2a
#define RM2 7 // right motor M2b

const int trigPin1 =A4; //Front
const int echoPin1 = A5;
const int trigPin2 = A2; //Right
const int echoPin2 = A3;
const int trigPin3 = A0;//Left
const int echoPin3 = A1;


const int enA = 8;
const int enB = 9;

#define red_1        10
#define yellow_1     11
#define green_1      12
#define blue_1      13



#define LS 2 // left sensor
#define RS 3 // right sensor

#define PWM 130
#define DIS 40


void setup()
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
pinMode(red_1,OUTPUT);
pinMode(yellow_1,OUTPUT);
pinMode(green_1,OUTPUT);
pinMode(blue_1,OUTPUT);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);

}
void loop()
{

if ( FrontSensor() < DIS )

{
stop_Car();
digitalWrite(red_1, HIGH);
 delay(100); 
 digitalWrite(yellow_1, LOW);
 digitalWrite(green_1, LOW);
 digitalWrite(blue_1, LOW);
 digitalWrite(red_1, LOW);
}
 /*
else if (RightSensor ()<DIS)
{
stop_Car();
digitalWrite(yellow_1, HIGH);
  delay(5000);
  digitalWrite(red_1, LOW);
 digitalWrite(green_1, LOW);
 digitalWrite(blue_1, LOW);
}
else if (LeftSensor ()<DIS)
{
stop_Car();
digitalWrite(blue_1, HIGH);
  delay(5000);
  digitalWrite(yellow_1, LOW);
 digitalWrite(green_1, LOW);
 digitalWrite(red_1, LOW);
}
*/
else
{


if(!(digitalRead(LS)) && !(digitalRead(RS))) // Move Forward on line
{
forward ();
}
if(digitalRead(LS) && !(digitalRead(RS))) // turn left by rotationg left motors in forward and right ones in backward direction
{
turn_left ();
}
if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right by rotating right motors in forward and left ones in backward direction
{
turn_right ();
}

if(digitalRead(LS) && digitalRead(RS)) // Finish line, stop both the motors
{
stop_Car();
}

}


 /*
 if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor 
()<DIS) // obstacle infront of all 3 sides
 {
turn_right (); 
delay(3000);//then reverse
}

 
 else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor 
()>DIS) // obstacle on right and front sides
 {
 turn_left (); // turn left side
 }


 
 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 
()<DIS) // obstacle on left and front sides
    {
 turn_right (); // turn right side
 }


 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 
()>DIS) // obstacle on front sides
 {
 turn_right (); // then turn right
 }


 else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor 
()<DIS) // obstacle on left sides
 {
 turn_right (); // then turn right and then forward
 delay(180);
 forward();
 }

 
 else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor 
()>DIS) // obstacle on right sides
 {
 turn_left (); // then turn left and then right
 delay(180);
 forward();
 }

 
 else 
 {
 forward();
 }
*/




}



void forward ()

{

 digitalWrite(LM1, HIGH);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, HIGH);
 digitalWrite(RM2, LOW);
 analogWrite(enA, PWM); 
 analogWrite(enB, PWM);

}

void turn_left () 

{
 digitalWrite(LM1, HIGH);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, LOW);
 digitalWrite(RM2, HIGH);
 analogWrite(enA, PWM); 
 analogWrite(enB, PWM);

}

void turn_right () 

{
 digitalWrite(LM1, LOW); 
 digitalWrite(LM2, HIGH);
 digitalWrite(RM1, HIGH);
 digitalWrite(RM2, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}

void reverse ()

{
 digitalWrite(LM1, LOW);
 digitalWrite(LM2, HIGH);
 digitalWrite(RM1, LOW);
 digitalWrite(RM2, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}

void stop_Car()

{
 digitalWrite(LM1, LOW);
 digitalWrite(LM2, LOW);
 digitalWrite(RM1, LOW);
 digitalWrite(RM2, LOW);
 analogWrite(enA, LOW);
 analogWrite(enB, LOW);
}

long FrontSensor ()

{
long dur;
 digitalWrite(trigPin1, LOW); 
 delayMicroseconds(5); // delays are required for a succesful sensor operation.
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin1, LOW);
 dur = pulseIn(echoPin1, HIGH);
 return (dur/30);// convert the distance to centimeters.
}

long RightSensor () 

{
long dur;
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor operation.
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin2, LOW);
 dur = pulseIn(echoPin2, HIGH);
 return (dur/62);// convert the distance to centimeters.
}

long LeftSensor ()    
{
long dur;
 digitalWrite(trigPin3, LOW); 
 delayMicroseconds(5); // delays are required for a succesful sensor operation.
 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPin3, LOW);
 dur = pulseIn(echoPin3, HIGH);
 return (dur/50);// convert the distance to centimeters.
}
