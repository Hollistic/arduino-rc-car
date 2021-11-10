#define EnA 10
#define EnB 5
#define In1 9
#define In2 8
#define In3 7
#define In4 6

void setup() {
  // put your setup code here, to run once:
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  forward();
  reverse();
}

//void controls() {
//  case: "w"  
//}

void forward() {
  //turn on motor a
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 200);

  //turn on motor b
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnB, 200);
  
}

void reverse() {
   //turn on motor a
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(EnA, 105);

  //turn on motor b
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnB, 105);
}
