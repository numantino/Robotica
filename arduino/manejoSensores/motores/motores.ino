const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;
const int pinIN3 = 9;
const int pinIN4 = 10;
const int pinENB = 11;
 
const int waitTime = 2000;   //espera entre fases
const int speed = 200;      //velocidad de giro
 
const int pinMotorA[3] = { pinENA, pinIN1, pinIN2 };
const int pinMotorB[3] = { pinENB, pinIN3, pinIN4 };
 
void setup()
{
   pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA, OUTPUT);
   pinMode(pinIN3, OUTPUT);
   pinMode(pinIN4, OUTPUT);
   pinMode(pinENB, OUTPUT);
}
 
void loop()
{
   moveForward(pinMotorA, 180);
   moveForward(pinMotorB, 180);
   delay(waitTime);
 
   moveBackward(pinMotorA, 180);
   moveBackward(pinMotorB, 180);
   delay(waitTime);
 
   fullStop(pinMotorA);
   fullStop(pinMotorB);
   delay(waitTime);

   //sonar.ping_cm(); // obtener el valor en cm (0 = fuera de rango)
}
 
void moveForward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], HIGH);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], speed);
}
 
void moveBackward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], HIGH);
 
   analogWrite(pinMotor[0], speed);
}
 
void fullStop(const int pinMotor[3])
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], 0);
}
