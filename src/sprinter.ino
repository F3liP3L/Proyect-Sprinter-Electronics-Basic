int MOTOR_A = 10; // Motor en si, Aqui se juega con la velocidad del motor. PIN ENA
int MOTOR_B = 3; // PIN ENB estos pines estan conectado a los jumpers que controlan la

int MOTOR_A_IZQ = 8; // IN1
int MOTOR_A_DER = 9; // IN2

int MOTOR_B_DER = 5; // IN3
int MOTOR_B_IZQ = 4; // IN4

int speedInitial = 140;
int speedInitialB =  150;
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
  analogWrite(MOTOR_B, speedInitialB);

  /*backTo();

  delay(2000);*/
  
  digitalWrite(MOTOR_A_DER, HIGH);
  digitalWrite(MOTOR_A_IZQ, LOW);
  digitalWrite(MOTOR_B_DER, HIGH);
  digitalWrite(MOTOR_B_IZQ, LOW);
  
  delay(2000);

  accelerator(1000);

  delay(2000);

  stopMotors();

  delay(500);

  travelAsSen(6);

  delay(500);

  speedInitial = 140;
  speedInitialB = 180;
  //delay(200);


}

/**
 * Aumenta gradualmente la velocidad inicial de los motores.
 * 
 * Esta función se encarga de incrementar la velocidad inicial de los motores de manera gradual
 * durante un intervalo de tiempo especificado.
 * 
 * @param int timeAccelerator - El tiempo en milisegundos entre cada incremento de velocidad.
 * 
 * La función utiliza la velocidad inicial actual y la aumenta en incrementos de 20 hasta
 * alcanzar la velocidad máxima permitida. La velocidad se ajusta tanto en el motor A como
 * en el motor B.
 *
 */
void accelerator(int timeAccelerator) {
  for (int i = speedInitial; i <= SPEED_MAX; i += 20) {
    if (speedInitial + 20 > SPEED_MAX) {
      break;
    } 
    if (speedInitialB + 20 > SPEED_MAX) {
      break;
    }
    speedInitial += 20;
    speedInitialB += 20;
    /*if (speedInitial <= 235) {
      analogWrite(MOTOR_A, speedInitial);
    }*/
    analogWrite(MOTOR_A, speedInitial);
    analogWrite(MOTOR_B, speedInitialB);
    delay(timeAccelerator);
  }
}

void stopMotors() {
  digitalWrite(MOTOR_A_DER, LOW);
  digitalWrite(MOTOR_A_IZQ, LOW);
  digitalWrite(MOTOR_B_DER, LOW);
  digitalWrite(MOTOR_B_IZQ, LOW);
}

/**
 * Simula el movimiento de los motores en un patrón similar a un seno.
 * 
 * @param int numberSection - Cantidad de repeticiones de giros del motor.
 */
void travelAsSen(int numberSection) {
    int zigzagDuration = 1000;
    // Realizamos varios tramos del zig zag
    for (int i = 0; i < numberSection; i++) { 

      // Giro a la derecha
      analogWrite(MOTOR_A, 255);
      analogWrite(MOTOR_B, 80);
      digitalWrite(MOTOR_A_DER, HIGH);
      digitalWrite(MOTOR_A_IZQ, LOW);
      digitalWrite(MOTOR_B_DER, HIGH);
      digitalWrite(MOTOR_B_IZQ, LOW);
      /*digitalWrite(MOTOR_A_DER, HIGH);
      digitalWrite(MOTOR_A_IZQ, LOW);
      digitalWrite(MOTOR_B_DER, LOW);
      digitalWrite(MOTOR_B_IZQ, LOW);*/
      delay(zigzagDuration);

      stopMotors();
      delay(100);

      // Giro a la izquierda
      analogWrite(MOTOR_A, 80);
      analogWrite(MOTOR_B, 255);

      digitalWrite(MOTOR_A_DER, HIGH);
      digitalWrite(MOTOR_A_IZQ, LOW);
      digitalWrite(MOTOR_B_DER, HIGH);
      digitalWrite(MOTOR_B_IZQ, LOW);
      /*
      digitalWrite(MOTOR_A_DER, LOW);
      digitalWrite(MOTOR_A_IZQ, LOW);
      digitalWrite(MOTOR_B_DER, HIGH);
      digitalWrite(MOTOR_B_IZQ, LOW);*/
      delay(zigzagDuration);

      stopMotors();
      delay(100);
    }
  }

 /**
  * Función de retroceso.
  */
  void backTo(){
    digitalWrite(MOTOR_A_DER, LOW);
    digitalWrite(MOTOR_A_IZQ, HIGH);
    digitalWrite(MOTOR_B_DER, LOW);
    digitalWrite(MOTOR_B_IZQ, HIGH);
  }
