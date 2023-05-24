#include <iostream>
#pragma once

namespace ariel{
    class Point 
    {
    private:
        double x_pos;
        double y_pos;
    public:
        Point(double _x_pos, double _y_pos);
        double distance(Point another);
        static Point moveTowards(Point pttr, Point another, double rad);
        double get_X () const;
        double get_Y () const;
    };
    
}