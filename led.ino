const int potPin1 = A0;   // Pino analógico conectado ao primeiro potenciômetro
const int potPin2 = A1;   // Pino analógico conectado ao segundo potenciômetro
const int ledPin1 = 9;    // Pino digital conectado ao primeiro LED
const int ledPin2 = 10;   // Pino digital conectado ao segundo LED

int brightness1 = 0;      // Variável para armazenar a luminosidade do primeiro LED
int brightness2 = 0;      // Variável para armazenar a luminosidade do segundo LED

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Inicia a comunicação serial com uma taxa de 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do primeiro potenciômetro e ajusta a luminosidade do primeiro LED
  int potValue1 = analogRead(potPin1);
  brightness1 = map(potValue1, 0, 1023, 0, 255);

  // Lê o valor do segundo potenciômetro e ajusta a luminosidade do segundo LED
  int potValue2 = analogRead(potPin2);
  brightness2 = map(potValue2, 0, 1023, 0, 255);

  // Imprime os valores de brightness1 e brightness2 no monitor serial
  Serial.print("LED 1: ");
  Serial.print(brightness1);
  Serial.print("\tLED 2: ");
  Serial.println(brightness2);

  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);
  delay(10);  // Pequeno atraso para estabilidade
}
