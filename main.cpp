//***********************************************************//
 
//** Author: Gulsim Azirakhmet                             **//
 
//** Date Created: December 6, 2021                        **//
 
//** Assignment 4: Robot Kinematics                        **//
 
//** UH-1000 Computer Programming for Engineers, NYUAD     **//
 
//** Problem:                                              **//
 
//** Building a Robot                                      **//
 
//** Using Concepts of Forward Kinematics                  **//
 
//***********************************************************//

#include "electrical engineering case_robot.h"
int Point::ctr = 0;
int Segment::ctr = 0;
int Robot::realSegments = 0;

int main() {
    int numOfSegments;
    Segment S1(0.8, 1.0);
    cout << "How many segments do you want to start with?" << endl;
    cin >> numOfSegments;
    Robot R1(numOfSegments);
    R1.printRobotInfo();
    R1.add();
    R1.printRobotInfo();
    R1.remove();
    R1.printRobotInfo();
    R1.Default();
    R1.printRobotInfo();
    R1.Kinematics();
    R1.printRobotInfo();
    cout << "Segment info:" << endl;
    S1.printS();
    R1.plot();
}