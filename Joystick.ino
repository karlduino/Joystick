/*
  
  Joystick: basic sketch to read position of parallax 2-axis joystick
      https://www.parallax.com/product/27800
      http://learn.parallax.com/KickStart/27800
  
  How to use:
  
    - counting pins from lower-left (look down from top) and going clockwise:
      - pin 1 to ground
      - pin 2 to A0 (up/down)
      - pin 3 to A1 (left/right)
      - pins 4 and 5 to V5
      - pins 6, 7, and 8 open
 */


// Store the Arduino pin associated with each input
const int PIN_Y = A0;
const int PIN_X = A1;

int minx, maxx, miny, maxy;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);

  minx = maxx = analogRead(PIN_X);
  miny = maxy = analogRead(PIN_Y);
}


void loop() {
  // Print the current values of the inputs
  // as well as min and max
  int x = analogRead(PIN_X);
  if(x < minx) minx = x;
  if(x > maxx) maxx = x;

  int y = analogRead(PIN_Y);
  if(y < miny) miny = y;
  if(y > maxy) maxy = y;

  Serial.print("X:");
  Serial.print(x);
  Serial.print(" (min=");
  Serial.print(minx);
  Serial.print(", max=");
  Serial.print(maxx);
  Serial.print(")    ");

  Serial.print("Y:");
  Serial.print(y);
  Serial.print(" (min=");
  Serial.print(miny);
  Serial.print(", max=");
  Serial.print(maxy);
  Serial.println(")");

  delay(250);
}

