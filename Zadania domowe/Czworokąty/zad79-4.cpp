#include <iostream>
#include <fstream>
#include <math.h>

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
};

class Triangle
{
    public:
        Point a, b, c;

        Triangle() {}

        Triangle( Point _a, Point _b, Point _c)
        {
            a = _a;
            b = _b;
            c = _c;
        }

        bool isRight();
};

float pointsDistancePower(Point a, Point b)
{
    return pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
}

bool Triangle::isRight()
{
    float x = pointsDistancePower(a, b);
    float y = pointsDistancePower(b, c);
    float z = pointsDistancePower(c, a);

    if(
        x + y == z ||
        y + z == x ||
        x + z == y
    )
        return true;
    else
        return false;
}

int main()
{
    ifstream data_input("wspolrzedneTR.txt");

    int right_triangles_count = 0;

    for(int i=0; i<DATA_SIZE; i++)
    {
        Point pointsIMPL[3];

        for(int j=0; j<3; j++)
        {
            data_input >> pointsIMPL[j].x;
            data_input >> pointsIMPL[j].y;
        }

        Triangle current_triangle(pointsIMPL[0], pointsIMPL[1], pointsIMPL[2]);
        
        if( current_triangle.isRight() )
            right_triangles_count++;
    }


    cout << right_triangles_count << endl;

    return 0;
}