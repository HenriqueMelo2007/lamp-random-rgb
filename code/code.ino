#define PORTELEVEN 11
#define PORTTEN 10
#define PORTNINE 9
#define BTN 7

int firstRandom;
int secondRandom;
int thirdRandom;

int lastValue = 0;

void newRandomNumbers();

void setup() {
  randomSeed(analogRead(0));
  firstRandom = random(0, 256);
  secondRandom = random(0, 256);
  thirdRandom = random(0, 256);

  pinMode(PORTELEVEN, OUTPUT);
  pinMode(PORTTEN, OUTPUT);
  pinMode(PORTNINE, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  analogWrite(PORTELEVEN, firstRandom);
  analogWrite(PORTTEN, secondRandom);
  analogWrite(PORTNINE, thirdRandom);
  
  newRandomNumbers();
}

void newRandomNumbers()
{
  int input = digitalRead(BTN);

  if (input == 1 && lastValue == 0) {
    firstRandom = random(0, 256);
    secondRandom = random(0, 256);
    thirdRandom = random(0, 256);
  }

  lastValue = input;
}