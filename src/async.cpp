#include "main.h"

using namespace okapi;
using namespace pros;
namespace global{
  bool drive_complete = true;
  Task *drive_task = NULL;
  unsigned int withMogos = 0;
  QLength target_distance = 0_in;
  QAngle target_angle = 0_deg;
  bool direction = true;
  bool isDriveComplete(){
    return drive_complete;
  }
  void waitUntilDriveComplete()
  {
    while(!isDriveComplete())
    {
      delay(10);
    }
  }
  void waitUntilTravel(QLength distance)
  {
    double target = distance.convert(centimeter) / circumference * 360.0;
    bool sign = target_distance.convert(centimeter) > 0;
    while(!isDriveComplete() && (sign ? (encoder_right.controllerGet() < target) : (encoder_right.controllerGet() > target)))
    {
      delay(10);
    }
  }
  void waitUntilReach(QLength distance, bool top)
  {
    pros::Distance* encoder = top ? &distance_top : &distance_bottom;
    double target = distance.convert(centimeter) * 10;
    bool sign = target > 0;
    while(!isDriveComplete() && encoder->get()> target)
    {
      delay(10);
    }
  }
  void drive_async(void* param)
  {
    while (true)
    {
      if(!isDriveComplete())
      {
        drive(target_distance, withMogos);
        drive_complete = true;
      }
      pros::delay(20);
    }
  }

  void asyncDrive(QLength distance, unsigned int drive_options){
    target_distance = distance;
    withMogos = drive_options;
    if(drive_task == NULL)
    {
      drive_task = new pros::Task(drive_async, (void*)"PROSDRIVE", TASK_PRIORITY_DEFAULT,
                                             TASK_STACK_DEPTH_DEFAULT, "Async Drive Task");
    }
    drive_complete = false;
  }

  void turn_async(void* param)
  {
    while (true)
    {
      if(!isDriveComplete())
      {
        turn(target_angle);
        drive_complete = true;
      }
      pros::delay(20);
    }
  }
  void asyncTurn(QAngle angle)
  {
    target_angle = angle;
    if(drive_task == NULL)
    {
      drive_task = new pros::Task(turn_async, (void*)"PROSDRIVE", TASK_PRIORITY_DEFAULT,
                                             TASK_STACK_DEPTH_DEFAULT, "Async Turn Task");
    }
    drive_complete = false;
  }
  void turn_to_async(void* param)
  {
    while (true)
    {
      if(!isDriveComplete())
      {
        turnTo(target_angle, direction);
        drive_complete = true;
      }
      pros::delay(20);
    }
  }
  void asyncTurnTo(QAngle angle, bool clockwise)
  {
    target_angle = angle;
    direction = clockwise;
    if(drive_task == NULL)
    {
      drive_task = new pros::Task(turn_to_async, (void*)"PROSDRIVE", TASK_PRIORITY_DEFAULT,
                                             TASK_STACK_DEPTH_DEFAULT, "Async Turn To Task");
    }
    drive_complete = false;
  }
}
