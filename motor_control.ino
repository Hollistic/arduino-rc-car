#include <SoftwareSerial.h>
#include <Servo.h>

//define pins for L298N
#define EnA 10
#define EnB 5
#define In1 9
#define In2 8
#define In3 7
#define In4 6


// TX to pin 11 and RX to pin 12 (for bluetooth control)
int TX = 11;
int RX = 12;
SoftwareSerial hc06(TX, RX);

//define servo
Servo steering;

//define state
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  
  //set servo control pin
  steering.attach(2);

  //start bluetooth connection
  Serial.begin(9600);
  hc06.begin(9600);
  hc06.println("test message");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (hc06.available() > 0) {
    state = hc06.read();
    rest();
    switch (state) {
      case 'F':
        forward();
        hc06.println("forward");
        break;
      case 'B':
        reverse();
        hc06.println("reverse");
        break;
      case 'R':
        right();
        hc06.println("forward right");
        break;
      case 'L':
        left();
        hc06.println("forward left");
        break;
      case 'S':
        rest();
        hc06.println("stopped");
        break;
    }
  }
//  forward();
}

//car doesn't move
void rest() {
  steering.write(90);
  analogWrite(In1, 0);
  analogWrite(In2, 0);
  analogWrite(In3, 0);
  analogWrite(In4, 0);
}

//car moves forward
void forward() {
  //set steering
  steering.write(90);
  
  //turn on motor a
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 255);

  //turn on motor b
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnB, 255);
  
}

//car moves in reverse
void reverse() {
  //set steering
  steering.write(90);
  
  //turn on motor a
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(EnA, 255);

  //turn on motor b
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnB, 255);
}

//car moves forward and turns right
void right() {
  //set servo position
  steering.write(180);
  
  //turn on motor a
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 255);

  //turn on motor b
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnB, 255);

}

//car moves forward and turns left
void left() {
  //set servo position
  steering.write(0);
  
  //turn on motor a
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 255);

  //turn on motor b
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnB, 255);
}
