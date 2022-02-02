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

float pointsDistance(Point a, Point b)
{
    return sqrt( pow(b.x - a.x, 2) + pow(b.y - a.y, 2) );
}

Point calculateParallelogram(Triangle triangle_IMPL)
{
    Point d;

    float x = pointsDistance(triangle_IMPL.a, triangle_IMPL.b);
    float y = pointsDistance(triangle_IMPL.b, triangle_IMPL.c);
    float z = pointsDistance(triangle_IMPL.c, triangle_IMPL.a);
    float parallelogram;

    parallelogram =  max( x , max(y, z) );
    
    if( x == parallelogram )
    {
        d.x = triangle_IMPL.a.x + triangle_IMPL.b.x - triangle_IMPL.c.x;
        d.y = triangle_IMPL.a.y + triangle_IMPL.b.y - triangle_IMPL.c.y;
    }
    else  if( y == parallelogram )
    {
        d.x = triangle_IMPL.b.x + triangle_IMPL.c.x - triangle_IMPL.a.x;
        d.y = triangle_IMPL.b.y + triangle_IMPL.c.y - triangle_IMPL.a.y;
    }
    else
    {
        d.x = triangle_IMPL.a.x + triangle_IMPL.c.x - triangle_IMPL.b.x;
        d.y = triangle_IMPL.a.y + triangle_IMPL.c.y - triangle_IMPL.b.y;
    }

    return d;
}

int main()
{
    ifstream data_input("wspolrzedneTR.txt");

    int counter = 0;

    for(int i=0; i<DATA_SIZE; i++)
    {
        Point pointsIMPL[4];

        for(int j=0; j<3; j++)
        {
            data_input >> pointsIMPL[j].x;
            data_input >> pointsIMPL[j].y;
        }

        Triangle current_triangle(pointsIMPL[0], pointsIMPL[1], pointsIMPL[2]);
        
        pointsIMPL[3] = calculateParallelogram(current_triangle);

        if(pointsIMPL[3].x == pointsIMPL[3].y)
            cout << pointsIMPL[0].x << " " << pointsIMPL[0].y << '\t' << pointsIMPL[1].x << " " << pointsIMPL[1].y << '\t' << pointsIMPL[2].x << " " << pointsIMPL[2].y << '\t' << pointsIMPL[3].x << " " << pointsIMPL[3].y << endl;
    }

    return 0;
}