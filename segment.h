
#include "point.h"//include point class
class Segment
{

private:
    int sID;
    double angle;
    double length;
    static int ctr;
    Point start;
    Point end;
    Segment* childSegment;

    //function for calculating end point
    void endPoint()
    {
        double x1 = start.getX() + (getLength() * cos(getAngle()));//calculate coordnate for x
        double y1 = start.getY() + (getLength() * sin(getAngle()));//calculate coordinate for y
        end = Point(x1, y1);//assign end coordinates to end 
    }

public:

    Segment()
    {
        sID = ctr;//initialize sID with counter
        angle = 0.0;//initialize angle with 0
        length = 0.0;//initialize length with 0
        start = Point(0, 0);//initialize starting point's coordinates with 0
        end = getEnd();//function to calculate the end point
        ctr++;//increment counter
    }

    Segment(double A, double L)
    {
        sID = ctr;//assign counter to sID
        angle = A;//assign A to angle
        length = L;//assign L to length
        start = Point(0, 0);//assign 0 coordinates to start point
        end = getEnd();//assign getEnd function to end 
        ctr++;//increment counter
    }

    static int getNumSegments()//get number of segments
    {
        return ctr;
    }

    Point getStart()//get start point
    {
        return start;
    }

    double getAngle()//get angle
    {
        return angle;
    }

    void setChildSegment(Segment* previousSegment)//set child segment
    {
        childSegment = previousSegment;
    }

    Segment getChildSegment()//get child segment
    {
        return *childSegment;
    }

    double getSegmentLength()//get length
    {
        return length;
    }

    Point getEnd()//get end point
    {
        endPoint();//function to calculate the end point
        return end;
    }

    double getStartX()//get start coordinate of x
    {
        return start.getX();
    }

    double getEndX()//get end coordinate of x
    {
        return end.getX();
    }

    double getStartY()//get start coordinates of y
    {
        return start.getY();
    }



    double getEndY()//get end coordinates of y
    {
        return end.getY();
    }

    void setStartXY(double newX, double newY)//get start point coordinates
    {
        start = Point(newX, newY);
        endPoint();
    }

    double getLength()//get length
    {
        return length;
    }

    int getsID()//get sID
    {
        return sID;
    }

    static int getCtr()//get the counter
    {
        return ctr;
    }

    void printS()//function to print to the output screen
    {
        cout << "The length is: " << getLength() << endl;//print length
        cout << "The angle is: " << getAngle() << endl;//print angle
        cout << "The start point " << "(" << getStartX() << "; " << getStartY() << ")" << endl;//print start point
        cout << "The end point " << "(" << getEndX() << "; " << getEndY() << ")" << endl;//print end point
    }

    void setAngle(double A)//set angle 
    {
        angle = A;
        endPoint();//calculates end point
    }

    void setLength(double L)//set length 
    {
        length = L;
        endPoint();//calculates end point
    }

};