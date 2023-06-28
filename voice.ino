String voice;
int RED = 2;
int GREEN = 3;
int BLUE = 4;
int MOTOR_PIN = 7; // Relay pin connected to the DC motor

void RedOn() {
  digitalWrite(RED, HIGH);
}

void RedOff() {
  digitalWrite(RED, LOW);
}

void GreenOn() {
  digitalWrite(GREEN, HIGH);
}

void GreenOff() {
  digitalWrite(GREEN, LOW);
}

void BlueOn() {
  digitalWrite(BLUE, HIGH);
}

void BlueOff() {
  digitalWrite(BLUE, LOW);
}

void motorOn() {
  digitalWrite(MOTOR_PIN, HIGH); // Turn on the relay, activating the DC motor
}

void motorOff() {
  digitalWrite(MOTOR_PIN, LOW); // Turn off the relay, deactivating the DC motor
}

void allOn() {
  RedOn();
  GreenOn();
  BlueOn();
}

void allOff() {
  RedOff();
  GreenOff();
  BlueOff();
}

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(10);
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);
    if (voice == "red" || voice == "red on") {
      RedOn();
    } else if (voice == "red off" || voice == "red of") {
      RedOff();
    } else if (voice == "green" || voice == "green on") {
      GreenOn();
    } else if (voice == "green off" || voice == "green of") {
      GreenOff();
    } else if (voice == "blue" || voice == "blue on") {
      BlueOn();
    } else if (voice == "blue off" || voice == "blue of") {
      BlueOff();
    } else if (voice == "on" || voice == "all") {
      allOn();
    } else if (voice == "off" || voice == "all off" || voice == "of" || voice == "all of") {
      allOff();
    } else if (voice == "motor on") {
      motorOn();
    } else if (voice == "motor off" || voice == "motor of") {
      motorOff();
    }
    voice = "";
  }
}