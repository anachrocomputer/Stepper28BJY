/* testDualStepper -- try out two cheap geared stepper motors 28BYJ                             2017-11-28 */


// http://forum.arduino.cc/index.php?topic=71964.15
// (31*32*26*22)/(11*10*9*9) = 283712/4455 = 25792/405 = 63.68395...
// 1650688/405

#define MIN_DELAY (2000)


void setup(void)
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  setStep(false, 0);
  setStep(true, 0);
}

void loop(void)
{
  int i;

  for (i = 0; i < 4096; i++) {
    setStep(true, i & 7);
    setStep(false, i & 7);
    variableDelay(i);
  }

  delay(1000);
}

void setStep(const bool motor, const int step)
{
  if (motor) {
    switch (step) {
    case 0:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      break;
    case 1:
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      break;
    case 2:
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      break;
    case 3:
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      break;
    case 4:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      break;
    case 5:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      break;
    case 6:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      break;
    case 7:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      break;
    }
  }
  else {
    switch (step) {
    case 0:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;
    case 1:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;
    case 2:
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;
    case 3:
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      break;
    case 4:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      break;
    case 5:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 6:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;
    case 7:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;
    }
  }
}

void variableDelay(const int i)
{
  if (i < 200)
    delayMicroseconds((MIN_DELAY + 10000) - (i * 50));
  else if (i > (4096 - 200))
    delayMicroseconds((MIN_DELAY + 10000) - ((4096 - i) * 50));
  else
    delayMicroseconds(MIN_DELAY);
}

