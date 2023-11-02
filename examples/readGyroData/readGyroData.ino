/*!
 * @file readGyroData.ino
 * @brief Through the example, you can get the sensor data by using getAllData:
 * @n     get gyroscope data of sensor.
 * @n     With the rotation of the sensor, data changes are visible.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [luoyufeng] (yufeng.luo@dfrobot.com)
 * @maintainer [Fary](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-10-20
 * @url https://github.com/DFRobot/DFRobot_BMX160
 */
#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx160;
void setup(){
  // creates connection between the arduino and device
  // arg is baud rate --> rate at which data travels (must be the same baud rate as device)
  Serial.begin(115200);
  // pauses all running tasks for num of ms passed in
  delay(100);
  
  //init the hardware bmx160  
  // if the arduino does not begin, prints "init false", and creates an infinite loop until it begins (not sure - anshika agarwal)
  if (bmx160.begin() != true){
    Serial.println("init false");
    while(1);
  }
  
  /**
   * enum{eGyroRange_2000DPS,
   *      eGyroRange_1000DPS,
   *      eGyroRange_500DPS,
   *      eGyroRange_250DPS,
   *      eGyroRange_125DPS
   *      }eGyroRange_t;
   */
  //bmx160.setGyroRange(eGyroRange_500DPS);
  
  delay(100);
}

void loop(){
  // sensor data type? - anshika needs to figure this out
  sBmx160SensorData_t Ogyro;

  /* Get a new sensor event */
  // built in function to get all data (only used for gyro in this file)
  // gyro is rotation and direction
  bmx160.getAllData(NULL, &Ogyro, NULL);


  /* Display the gyroscope results (gyroscope data is in g) */
  // struct 0gyro has 3 instance vars -> x, y, z
  Serial.print("G ");
  Serial.print("X: "); Serial.print(Ogyro.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(Ogyro.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(Ogyro.z); Serial.print("  ");
  Serial.println("g");

  Serial.println("");

  delay(500);
}










