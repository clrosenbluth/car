int purple = 2;             //left wheel back
int blue = 12;               //left wheel front
int yellow = 4;             //right wheel back
int orange = 8;             //right wheel front
int proxButton = 7;         //the button that works as a proximity sensor


void setup() {
pinMode(purple, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(orange, OUTPUT);
pinMode(proxButton, INPUT);
}


void loop(){
  forward();
  if (proxButton==HIGH) turnBack();
  }


void forward(){
  digitalWrite(blue, HIGH);
  digitalWrite(purple, LOW);
  digitalWrite(orange, HIGH);
  digitalWrite(yellow, LOW);
  }


void turnBack(){
  digitalWrite(yellow, HIGH);
  digitalWrite(orange, LOW);
  digitalWrite(purple, LOW);
  digitalWrite(blue, LOW);
  }
