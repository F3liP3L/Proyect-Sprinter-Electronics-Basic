int MOTOR_A = 10; // Motor en si, Aqui se juega con la velocidad del motor. PIN ENA
int MOTOR_B = 3; // PIN ENB estos pines estan conectado a los jumpers que controlan la

int MOTOR_A_IZQ = 8; // IN1
int MOTOR_A_DER = 9; // IN2

int MOTOR_B_DER = 5; // IN3
int MOTOR_B_IZQ = 4; // IN4

int speedInitial = 120;
int SPEED_MAX = 255;


void setup() {

  Serial.begin(9600);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  pinMode(MOTOR_A_DER, OUTPUT);
  pinMode(MOTOR_A_IZQ, OUTPUT);
  pinMode(MOTOR_B_DER, OUTPUT);
  pinMode(MOTOR_B_IZQ, OUTPUT);

}

void loop() {

  analogWrite(MOTOR_A, speedInitial);
  analogWrite(MOTOR_B, speedInitial);
  digitalWrite(MOTOR_A_DER, LOW);
  digitalWrite(MOTOR_A_IZQ, HIGH);
  digitalWrite(MOTOR_B_DER, LOW);
  digitalWrite(MOTOR_B_IZQ, HIGH);

  delay(2000);
  
  digitalWrite(MOTOR_A_DER, HIGH);
  digitalWrite(MOTOR_A_IZQ, LOW);
  digitalWrite(MOTOR_B_DER, HIGH);
  digitalWrite(MOTOR_B_IZQ, LOW);

  accelerator();

  delay(2000);

  speedInitial = 0;
  analogWrite(MOTOR_A, speedInitial);
  analogWrite(MOTOR_B, speedInitial);
  digitalWrite(MOTOR_A_DER, LOW);
  digitalWrite(MOTOR_A_IZQ, LOW);
  digitalWrite(MOTOR_B_DER, LOW);
  digitalWrite(MOTOR_B_IZQ, LOW);

  delay(1000);

  speedInitial = 120;


}

void accelerator() {
  for (int i = speedInitial; i <= SPEED_MAX; i++) {
    if (speedInitial + 20 > SPEED_MAX) {
      break;
    }
    speedInitial += 20;
    analogWrite(MOTOR_A, speedInitial);
    analogWrite(MOTOR_B, speedInitial);
    delay(3000);
  }
}

  void travelAsSen(){
    // Se crea el ciclo para simular el recorrido en seno.
  }
