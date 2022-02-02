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

        float getPerimeter();
};

float pointsDistance(Point a, Point b)
{
    return sqrt( pow(b.x - a.x, 2) + pow(b.y - a.y, 2) );
}

float Triangle::getPerimeter()
{
    return pointsDistance(a, b) + pointsDistance(b, c) + pointsDistance(c, a);
}

int main()
{
    ifstream data_input("wspolrzedneTR.txt");

    Triangle maximal_triangle;

    for(int i=0; i<DATA_SIZE; i++)
    {
        Point pointsIMPL[3];

        for(int j=0; j<3; j++)
        {
            data_input >> pointsIMPL[j].x;
            data_input >> pointsIMPL[j].y;
        }

        Triangle current_triangle(pointsIMPL[0], pointsIMPL[1], pointsIMPL[2]);
        
        if( current_triangle.getPerimeter() > maximal_triangle.getPerimeter() )
            maximal_triangle = current_triangle;
    }


    cout << maximal_triangle.a.y << ", " << maximal_triangle.a.y << '\t' << maximal_triangle.b.x << ", " << maximal_triangle.b.y << '\t' << maximal_triangle.c.x << ", " << maximal_triangle.c.y << endl;
    cout << round(maximal_triangle.getPerimeter()*100)/100 << endl;

    return 0;
}