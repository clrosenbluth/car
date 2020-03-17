int purple = 2;             //left wheel back
int blue = 12;               //left wheel front
int yellow = 4;             //right wheel back
int orange = 8;             //right wheel front
int proxButton = A1;         //the button that works as a proximity sensor
int blueTrig = 9;           //us trigger
int yellowEcho = 10;        //us reciever
long duration, inches;
int safe = 3;
int buttonStatus;

void setup() {
Serial.begin(9600);
pinMode(purple, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(orange, OUTPUT);
pinMode(proxButton, INPUT);
pinMode(blueTrig, OUTPUT);
pinMode(yellowEcho, INPUT);
}

void loop() {

ultrasonic();
Serial.print(inches);
Serial.println(" inches");
buttonStatus = analogRead(proxButton);
Serial.print("Button: ");
Serial.println(buttonStatus);


if (inches >= 3){
  Serial.print(inches);
  Serial.println(" inches, going forward");
  forward();
  ultrasonic();
  buttonStatus = analogRead(proxButton);
  }

else if (inches < 3 && buttonStatus < 1000){    //ultrasonic bad button good
  Serial.print(inches);
  Serial.println(" inches, turning back");
  turnForward();                                 //left wheel back right wheel forward
  ultrasonic();
  buttonStatus = analogRead(proxButton);
  }

else if (inches < 3 && buttonStatus > 1000){    //ultrasonic bad button bad
  Serial.print(inches);
  Serial.println(" inches, something is behind me, turning backward");
  turnBack();                                //right wheel forward left wheel back
  ultrasonic();
  buttonStatus = analogRead(proxButton);
  }

}

void ultrasonic(){
  digitalWrite(blueTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(blueTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(blueTrig, LOW);

  duration = pulseIn(yellowEcho, HIGH);
  inches = duration / 74 / 2;
  }

void forward(){             //left wheel forward, right wheel forward
  digitalWrite(blue, HIGH); //left
  digitalWrite(purple, LOW);
  digitalWrite(orange, HIGH); //right
  digitalWrite(yellow, LOW);
  }

void turnBack(){            //left wheel goes backward, right wheel forward
  //go back for 1 sec
  digitalWrite(yellow, HIGH);  //right
  digitalWrite(orange, LOW);
  digitalWrite(purple, HIGH); //left
  digitalWrite(blue, LOW);
  delay(1000);
  
  digitalWrite(yellow, LOW);  //right
  digitalWrite(orange, HIGH);
  digitalWrite(purple, HIGH); //left
  digitalWrite(blue, LOW);

  //go back for 1 sec
  digitalWrite(yellow, HIGH);  //right
  digitalWrite(orange, LOW);
  digitalWrite(purple, HIGH); //left
  digitalWrite(blue, LOW);
  delay(1000);
  }

void turnForward(){       //left wheel goes forward, right wheel backward
  //go back for 1 sec
  digitalWrite(yellow, HIGH);  //right
  digitalWrite(orange, LOW);
  digitalWrite(purple, HIGH); //left
  digitalWrite(blue, LOW);
  delay(1000);
  
  digitalWrite(yellow, HIGH);  //right
  digitalWrite(orange, LOW);
  digitalWrite(purple, LOW);  //left
  digitalWrite(blue, HIGH);

  //go back for 1 sec
  digitalWrite(yellow, HIGH);  //right
  digitalWrite(orange, LOW);
  digitalWrite(purple, HIGH); //left
  digitalWrite(blue, LOW);
  delay(1000);
  }
