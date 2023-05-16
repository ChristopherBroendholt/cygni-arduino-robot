#define MOTOR_RIGHT_ENCODER_PIN 3
#define MOTOR_LEFT_ENCODER_PIN 2

//Count the motor encoder wheel (black ring on the opposite site of wheel)
volatile unsigned long left_encoder_count = 0;
volatile unsigned long right_encoder_count = 0;

void setup(){
  pinMode(MOTOR_RIGHT_ENCODER_PIN, INPUT);
  pinMode(MOTOR_LEFT_ENCODER_PIN, INPUT);
  
  //https://reference.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt(digitalPinToInterrupt(MOTOR_LEFT_ENCODER_PIN), encoder_left_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_RIGHT_ENCODER_PIN), encoder_right_interrupt, CHANGE);
}

void encoder_left_interrupt(){
  right_encoder_count++;
}

void encoder_right_interrupt(){
  left_encoder_count++;
}
