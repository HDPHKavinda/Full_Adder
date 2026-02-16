#include <LogicGates.h>

const int ipinA = 7;
const int ipinB = 6;
const int ipinC = 5; 
const int opinS = 12;
const int opinC = 13;
bool S1;
bool S;
bool C1;
bool C2;
bool Cout;

void setup() {
  pinMode(ipinA,INPUT);
  pinMode(ipinB,INPUT);
  pinMode(ipinC,INPUT);

  pinMode(opinS,OUTPUT);
  pinMode(opinC,OUTPUT);
  Serial.begin(9600);

  digitalWrite(opinS,LOW);
  digitalWrite(opinC,LOW);
}

bool fxor( bool X ,bool Y){
  bool Sum = XorGate(X,Y);
  return Sum;
}
bool fand( bool X ,bool Y){
  bool carry = AndGate(X,Y);
  return carry;
}
void loop() {
  bool A = digitalRead(ipinA);
  bool B = digitalRead(ipinB);
  bool Cin = digitalRead(ipinC);
  Serial.print(A);
  Serial.print(B);
  Serial.print(Cin);

  Serial.print("---");
  
  //S1, C1 = halfAdder(A, B);
  S1 = fxor(A,B);
  C1 = fand(A,B);
  Serial.print("S1--");
  Serial.print(S1);
  Serial.print("C1--");
  Serial.print(C1);

  //S, C2 = halfAdder(Cin, S1);
  S = fxor(S1,Cin);
  C2 = fand(S1,Cin);
  Serial.print("S--");
  Serial.print(S);
  Serial.print("C2--");
  Serial.print(C2);

  Cout = OrGate(C1, C2);
  Serial.print(Cout);
  Serial.print("---");

  Serial.println();

  digitalWrite(opinS, S);
  digitalWrite(opinC, Cout);
  

}
