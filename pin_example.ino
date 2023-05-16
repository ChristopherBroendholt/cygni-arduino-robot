//PINS
#define MOTOR_RIGHT_FORWARD_PIN 5
#define MOTOR_RIGHT_BACKWARD_PIN 6

#define MOTOR_LEFT_FORWARD_PIN 9
#define MOTOR_LEFT_BACKWARD_PIN 10

#define LINE_SENSOR_RIGHT_PIN A4
#define LINE_SENSOR_LEFT_PIN A5
//END PINS

#define MOTOR_LEFT_OFFSET 0
#define MOTOR_RIGHT_OFFSET 0

#define LINE_SENSOR_LEFT_THRESH 0
#define LINE_SENSOR_RIGHT_THRESH 0

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_RIGHT_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD_PIN, OUTPUT);

  pinMode(MOTOR_LEFT_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD_PIN, OUTPUT)

  pinMode(LINE_SENSOR_RIGHT_PIN, INPUT);
  pinMode(LINE_SENSOR_LEFT_PIN, INPUT);
}