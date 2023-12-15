//MOTOR 1   
int motor1H = 2; //Controle de acionamento do motor
int motor1L = 3; //Controle de acionamento do motor

//MOTOR 2
int motor2H = 12; //Controle de acionamento do motor
int motor2L = 13; //Controle de acionamento do motor

//Sensor reflexivo - o sensor da zero quando recebe luz
int reflexD=6;//sensor lado direito
int reflexE=7;//sensor lado esquerdo

int tmp = 50;
   
void setup()  
{  
  //Define os pinos como saida  
  pinMode(motor1H, OUTPUT);  
  pinMode(motor1L, OUTPUT);
  pinMode(motor2H, OUTPUT);
  pinMode(motor2L, OUTPUT);
  pinMode(reflexD, INPUT);
  pinMode(reflexE, INPUT);
}  
   
void loop()  
{ 
  if (digitalRead(reflexD)==LOW && digitalRead(reflexE)==LOW)
  {
  frente();
 
  }
  
  if (digitalRead(reflexD)==HIGH && digitalRead(reflexE)==LOW)
  {
  direita();
  
  }
  
  if (digitalRead(reflexD)==LOW && digitalRead(reflexE)==HIGH)
  {
  esquerda();
 
  }
  
  
  pare();
}  
    
void pare()  
{  
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, LOW);
  delay(tmp);  
}  

void frente()
{
  digitalWrite(motor1H, HIGH);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, HIGH);  
  digitalWrite(motor2L, LOW); 
  delay(tmp);  
}


void re()
{
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, HIGH);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, HIGH);  
  delay(tmp); 
}


void esquerda()
{
  digitalWrite(motor1H, HIGH);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, LOW);  
  delay(tmp); 
}

void direita()
{
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, HIGH);  
  digitalWrite(motor2L, LOW);  
  delay(tmp); 
}
