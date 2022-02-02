#include <iostream>
#include <fstream>

#define DATA_SIZE 100

using namespace std;

class Point
{
    public:
        int x, y;

        Point(int _x, int _y)
        {
            x = _x;
            y = _y;
        }

        Point()
        {
            x = 0;
            y = 0;
        }

    int getQuarter();
};

int Point::getQuarter()
{
    bool right_side = x > 0;
    bool top = y > 0;

    if( right_side && top ) 
        return 1;
    if( right_side && !top ) 
        return 2;
    if( !right_side && !top ) 
        return 3;
    if( !right_side && top ) 
        return 4;

    return 0;
};

bool isPointInLine(Point a, Point b, Point c)
{
    return ( (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x) );
}

int main()
{
    ifstream data_input("wspolrzedne.txt");

    int counter = 0;

    for(int i=0; i<DATA_SIZE; i++)
    {
        Point pointsIMPL[3];

        for(int j=0; j<3; j++)
        {
            data_input >> pointsIMPL[j].x;
            data_input >> pointsIMPL[j].y;
        }
        
        if( pointsIMPL[0].getQuarter() == 1 &&
            pointsIMPL[1].getQuarter() == 1 &&
            pointsIMPL[2].getQuarter() == 1
        )
            counter++;

    }

    cout << counter << endl;

    return 0;
}