const int ldrLeftPin = A0;    // Pino do sensor LDR do lado esquerdo
const int ldrRightPin = A1;   // Pino do sensor LDR do lado direito
const int leftMotorPin1 = 9;  // Pinos do motor esquerdo
const int leftMotorPin2 = 10;
const int rightMotorPin1 = 5; // Pinos do motor direito
const int rightMotorPin2 = 6;
const int limiar = 100;       // Valor do limiar para detecção de LEDs

void setup() {
  pinMode(ldrLeftPin, INPUT);
  pinMode(ldrRightPin, INPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  // Inicia a comunicação serial com uma taxa de 9600 bps
  Serial.begin(9600);
}

void loop() {
  int ldrLeftValue = constrain(analogRead(ldrLeftPin), 0, 255);
  int ldrRightValue = constrain(analogRead(ldrRightPin), 0, 255);

  // Imprime os valores dos LDRs no monitor serial
  Serial.print("LDR Esquerdo: ");
  Serial.print(ldrLeftValue);
  Serial.print("\tLDR Direito: ");
  Serial.println(ldrRightValue);

  // Verifica se há LEDs do lado direito
  if (ldrRightValue < limiar) {
    moveRight();
    delay(3000);  // Atraso de 3 segundos
    stopMotors();
  }
  // Verifica se há LEDs do lado esquerdo
  else if (ldrLeftValue < limiar) {
    moveLeft();
    delay(3000);  // Atraso de 3 segundos
    stopMotors();
  }
  // Caso contrário, continua para frente
  else {
    moveForward();
  }
}

void moveForward() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void moveLeft() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void moveRight() {
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void stopMotors() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}
