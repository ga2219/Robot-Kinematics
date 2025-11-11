#include "segment.h"//include segment class
#include "pbPlots.hpp"//include plotting library
#include "supportLib.hpp"//include support library for plotting

class Robot
{

private:
    int ID;//declare ID as integer
    Segment* S;//dynamic array
    static int realSegments;//declare the number of segments as static integer 
public:
    Robot(int numSegments)
    {
        realSegments = realSegments + numSegments;//calculate real number of segments 
        S = new Segment[realSegments];//assign new size to the dynamic array
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times 
        {
            double angle, length;//declare angle and length as double
            cout << "Please, enter the length for the new segment" << endl;//print message
            cin >> length;//enter the answer to the length
            while(length<0)//while value is negative do
            {
                cout << "Please, enter the positive value for the length for the new segment" << endl;//print message
                cin >> length;//enter the answer to the length
            }
           
            cout << "Please, enter the angle for the new segment" << endl;//print message
            cin >> angle;//enter the answer to the angle1
            while (angle < 0)//while value is negative do
            {
                cout << "Please, enter the positive value for the angle for the new segment" << endl;//print message
                cin >> angle;//enter the answer to the angle
            }
            S[i].setAngle(angle);//set angle in the segment class as the entered value 
            S[i].setLength(length);//set length in the segment class as the entered value 
            S[i].setStartXY(S[i - 1].getEndX(), S[i - 1].getEndY());//set start point coordinates 
        }
    }

    //function for the additional segments
    void add()
    {
        int addition;//declare addition as integer
        cout << "Please, enter the number of segments to add " << endl;//print message for additional segment numbers
        cin >> addition;//read into additon
        while (addition < 0)//while value is negative do
        {
            cout << "Please, enter the positive value" << endl;//print message
            cin >> addition;//enter the answer to the addition
        }
        int addNumSegments = realSegments + addition;//new number of segments with added segments
        Segment* S1;//dynamic array
        S1 = new Segment[addNumSegments];//assign new size to the dynamic array
        for (int i = 0; i < addNumSegments; i++)//loop that repeats number of segment times 
        {
            S1[i] = S[i];//assign prevoius array of segments to new array
        }
        delete[] S;//delete array of segments
        S = new Segment[addNumSegments];//assign new size to the dynamic array
        for (int i = 0; i < addNumSegments; i++)//loop that repeats number of segment times
        {
            S[i] = S1[i];//assign S1 array to S array
        }
        delete[] S1;//delete S1 array
        for (int i = 0; i < addition; i++)//loop that repeats additional number of segment times
        {
            double angle, length;//declare angle and length as double
            cout << "Please, enter the angle for the " << i + 1 << " additional segment" << endl;//print the message
            cin >> angle;//read into angle
            while (angle < 0)//while value is negative do
            {
                cout << "Please, enter the positive value for the angle " << endl;//print message
                cin >> angle;//enter the answer to the angle
            }
            cout << "Please, enter the length for the " << i + 1 << " additional segment" << endl;//print the message
            cin >> length;//read into length
            while (length < 0)//while value is negative do
            {
                cout << "Please, enter the positive value for the length" << endl;//print message
                cin >> length;//enter the answer to the length
            }
            S[realSegments + i].setAngle(angle);//set angle in the segment class as the entered value 
            S[realSegments + i].setLength(length);//set length in the segment class as the entered value 
            S[realSegments + i].setStartXY(S[realSegments + i - 1].getEndX(), S[realSegments + i - 1].getEndY());//set start point coordinates
        }
        realSegments = addNumSegments;//assign number of segments with additional segments to realSegments
    }

    void remove()
    {
        int del;//declare del as integer
        cout << "Please, enter the number of segments you would like to remove" << endl;//print message
        cin >> del;//read value into del
        while (del < 0)//while value is negative do
        {
            cout << "Please, enter the positive value" << endl;//print message
            cin >> del;//enter the answer to the del
        }
        int addNumSegments = realSegments - del;//calculate number of segments
        Segment* S1;//dynamic array
        S1 = new Segment[addNumSegments];//assign new size to dynamic array
        for (int i = 0; i < addNumSegments; i++)//loop that repeats number of segment times
        {
            S1[i] = S[i];//assign prevoius array of segments to new array
        }
        delete[] S;//delete array of segments
        S = new Segment[addNumSegments];//assign new size to the dynamic array
        for (int i = 0; i < addNumSegments; i++)//loop that repeats number of segment times
        {
            S[i] = S1[i];//assign S1 array to S array
        }
        delete[] S1;//delete S1 array
        realSegments = addNumSegments;//assign new number of segments with segments to realSegments
    }

    //function to reset to default
    void Default() 
    {
        cout << "The program will be set to the default position" << endl;//print the message
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times
        {
            S[i].setAngle(0);//set angle to 0
            S[i].setStartXY(S[i - 1].getEndX(), S[i - 1].getEndY());//set the start coordinates
        }
    }
    //function to perform kinematics
    void Kinematics() 
    {
        double* angle;//dynamic array
        angle = new double[realSegments];//assign new size to dynamic array
        Segment* S1;//dynamic array
        S1 = new Segment[realSegments];//assign new size to dynamic array
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times
        {
            S1[i] = S[i];//assign prevoius array of segments to new array
        }
        delete[] S;//delete S array
        S = new Segment[realSegments];//assign new size to dynamic array
        cout << "Please enter the values for angles to be updated " << endl;//print the message
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times 
        {
            cin >> angle[i];//read into angle array
        }
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times 
        {
            S[i].setAngle(angle[i]);//set read angles
            S[i].setLength(S1[i].getLength());//set length
            S[i].setStartXY(S[i - 1].getEndX(), S[i - 1].getEndY());//set start point coordinates
        }
        delete[] S1;//delete S1 array
        cout << "Forward Kinematics has taken place" << endl;//print message
    }

    static int getNumberOfSegments()//fumction to get a number of segments
    {
        return realSegments;
    }

    void printRobotInfo()//function to print robot info 
    {
        for (int i = 0; i < realSegments; i++)//loop that repeats number of segment times
        {
            S[i].printS();//call printS
        }
    }
    //function to plot the graph
    void plot()//function sample is taken from internet sources, references are given in the lab report
    {
        vector<double> xs;
        vector<double> ys;
        for (int i = 0; i < realSegments; i++)
        {
            xs.push_back(S[i].getStartX());
            xs.push_back(S[i].getEndX());
            ys.push_back(S[i].getStartY());
            ys.push_back(S[i].getEndY());
        }
        bool success;
        StringReference* errorMessage = new StringReference();
        RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();
        success = DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
        if (success)
        {
            vector<double>* pngdata = ConvertToPNG(imageReference->image);
            WriteToFile(pngdata, "example1.png");
            DeleteImage(imageReference->image);
        }
        else
        {
            cerr << "Error: ";
            for (wchar_t c : *errorMessage->string)
            {
                wcerr << c;
            }
            cerr << endl;
        }
    }
};