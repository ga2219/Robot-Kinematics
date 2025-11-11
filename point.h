#include <iostream>
#include <cmath>//include cmath library
using namespace std;

class Point 
{

private:
    int pointID;//declare pointID as integer
    double x;//declare x as double
    double y;//declare y as double
    static int ctr;//declare counter as static integer

public:
    Point()
    {
        pointID = ctr;//initialize pointID with ctr
        x = 0;//initialize x as 0
        y = 0;//initialize y as 0
        ctr++;//increment counter
    }
    Point(double X, double Y) 
    {
        pointID = ctr;//assign counter to pointID
        x = X;//assign X to x
        y = Y;//assign Y to y
        ctr++;//increment counter
    }

    static int getNumPoints()//get number of points 
    {
        return ctr;
    }
    double getX()//get x
    {
        return x;
    }
    double getY()//get y
    {
        return y;
    }
};