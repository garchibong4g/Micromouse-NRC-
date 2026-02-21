#include <Wire.h>
#include <VL53L4CD.h>
#include <DFRobot_I2C_Multiplexer.h>

VL53L4CD distanceSensor;

DFRobot_I2C_Multiplexer I2CMulti(0x70);

int distance_right = 0;
int distance_center = 0;
int distance_left = 0;

// Motor PINs
#define INT1 23
#define INT2 5
#define INT3 13
#define INT4 12

int wheelspeed = 80;


void setup() {
  Serial.begin(115200);
  //Wire.begin();
  I2CMulti.selectPort(0);
  sensor_setup();
  Serial.println("Right Sensor online!");
  
  I2CMulti.selectPort(1);
  sensor_setup();
  Serial.println("Center Sensor online!");

  I2CMulti.selectPort(2);
  sensor_setup();
  Serial.println("Left Sensor online!");

  //initial motor pins
  pinMode(INT1, OUTPUT); // controls left wheel forward
  pinMode(INT2, OUTPUT); // controls left wheel backwards 
  pinMode(INT3, OUTPUT); // controls right wheel backwards
  pinMode(INT4, OUTPUT); // controls right wheel forwards
}

void loop() {
  Wire.begin();
  Wire.setClock(400000); //use 400 kHz I2C

  I2CMulti.selectPort(0);
  distance_right = get_distance();
  delay(2);
  
  I2CMulti.selectPort(1); 
  distance_center = get_distance();
  delay(2);

  I2CMulti.selectPort(2); 
  distance_left = get_distance();
  delay(2);
  
  //print_sensors();
  // command to move 
  if (distance_center > 100 || 50 >= distance_center) {
    forward();
    Serial.println("Forward");
    //delay(50);
  }
  else if (distance_right > distance_left || 50 >= distance_right) {
    right();
    Serial.println("Right");
  }
  else if (distance_left > distance_right || 50 >= distance_left){
    left();
    Serial.println("Left");
  }
  else {
    stop();
    Serial.println("Stop");
  }
}

//*********Sensor functions************//
void sensor_setup() {
  distanceSensor.setTimeout(500);
  if (!distanceSensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  // The sensor is configured with a default timing budget of 50 ms and
  // inter-measurement period of 0 (continuous ranging). You can optionally
  // uncomment one of the following lines to use one of the example
  // configurations listed in ST's VL53L4CD ULD user manual UM2931 (section 2.4,
  // Example of configurations) or call setRangeTiming() with your own values.
  //
  // According to UM2931 table 4, Minimum and maximum range timing (in section
  // 3.2, Range timing):
  // - Timing budget can be 10 to 200 ms.
  // - Inter-measurement can be 0 for continuous ranging (as often as the timing
  //   budget allows) or else must be greater than the timing budget, up to a
  //   maximum of 5000 ms.
  distanceSensor.setRangeTiming(10, 0); // fast ranging (10 ms budget continuously)
  //sensor.setRangeTiming(200, 0); // high accuracy (200 ms budget continuously)
  //sensor.setRangeTiming(50, 1000); // autonomous low power (50 ms budget, 1 reading every second)

  // Start continuous readings.
  distanceSensor.startContinuous();
}

// computer distance from sensor in millimeters
int get_distance() {
  int distance = distanceSensor.read();
  if (distanceSensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  return distance;
}

// print the results for all three sensors
void print_sensors() {
  Serial.print("Right(mm): ");
  Serial.print(distance_right);
  Serial.print("; ");
  Serial.print("Center(mm): ");
  Serial.print(distance_center);
  Serial.print("; ");
  Serial.print("Left(mm): ");
  Serial.println(distance_left);
}

// Motor Commands
void forward() {
  analogWrite(INT1, wheelspeed); // left forwards at max speed which is 100
  analogWrite(INT2, 0); // so left wont move back wards 
  analogWrite(INT3, 0);
  analogWrite(INT4, wheelspeed);
}

void backward() {
  analogWrite(INT1, 0);
  analogWrite(INT2, wheelspeed);
  analogWrite(INT3, wheelspeed);
  analogWrite(INT4, 0);
}

void stop() {
  analogWrite(INT1, 0);
  analogWrite(INT2, 0);
  analogWrite(INT3, 0);
  analogWrite(INT4, 0);
}
 void right() { // makes right turn in place 
  analogWrite(INT1, wheelspeed); // left wheel forward
  analogWrite(INT2, 0); 
  analogWrite(INT3, wheelspeed); // right wheel backwards
  analogWrite(INT4, 0);
  delay(1000);
}

void left() {  // makes left turn in place 
  analogWrite(INT1, 0); 
  analogWrite(INT2, wheelspeed); // left wheel backwords 
  analogWrite(INT3, 0); 
  analogWrite(INT4, wheelspeed); // right wheel forwards
  delay(1000);
}