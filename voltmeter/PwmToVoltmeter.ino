#define DEBUG_PRINT
#ifdef DEBUG_PRINT
#define PRINT_INIT(X) Serial.begin((X))
#define PRINT(X) Serial.print(X)
#define PRINTLN(X) Serial.println(X)
#else 
#define PRINT_INIT(X)
#define PRINT(X)
#define PRINTLN(X)
#endif

#define PWM_PIN 5   // D5

#define TEST_MAX_PWM  1

void setup() {
  PRINT_INIT( 9600 );
  PRINTLN("Setup started.");
  
  pinMode(PWM_PIN, OUTPUT);
  delay(5000);

  PRINTLN("Setup complete.");
}

#if TEST_MAX_PWM
// loop up and down at quarter PWM power with 5-second intervals
int pwm_val = 3;
int pwm_step = 63;

void loop() {

  PRINT("m pwm_val = ");
  PRINTLN(pwm_val);

  analogWrite(PWM_PIN, (uint8_t)pwm_val);

  if (pwm_val == 3) {
    pwm_step = 63;
  } else if (pwm_val == 255) {
    pwm_step = -63;
  }
  pwm_val = pwm_val + pwm_step;

  delay(5000);
}

#else
// Loop up and down in 60 increments as if displaying minutes

int pwm_val = 10;
int pwm_step = 4;

void loop() {

  PRINT("pwm_val = ");
  PRINTLN(pwm_val);

  analogWrite(PWM_PIN, (uint8_t)pwm_val);

  if (pwm_val == 10) {
    pwm_step = 4;
  } else if (pwm_val == 250) {
    pwm_step = -4;
  }
  pwm_val = pwm_val + pwm_step;

  delay(1000);
}
#endif
