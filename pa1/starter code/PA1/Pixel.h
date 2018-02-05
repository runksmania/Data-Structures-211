/*
Assignment: PA1
Description: Perform various image effects on ppm images.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 15 hours.
In completing this program, I received help from the following people:
Adam Carter
*/

#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <sstream>
using namespace std;

class Pixel
{
private:
    int _red;
    int _green;
    int _blue;

public:
    Pixel(int r = 0, int g = 0, int b = 0)
    {
        _red = r;
        _green = g;
        _blue = b;
    }

    int getRed()
    {
        return _red;
    }

    void setRed(int r)
    {
        _red = r;
    }

    int getGreen()
    {
        return _green;
    }

    void setGreen(int g)
    {
        _green = g;
    }

    int getBlue()
    {
        return _blue;
    }

    void setBlue(int b)
    {
        _blue = b;
    }

    string toString()
    {
        ostringstream output{};
        output << _red << " " << _green << " "
            << _blue;
        return output.str();
    }
};
#endif // !PIXEL_H

