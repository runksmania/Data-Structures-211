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
#ifndef  IMAGE_EFFECT_H
#define IMAGE_EFFECT_H
#include "PpmDocument.h"

//This is an abstract class for different image effects.
class ImageEffect
{
public:
    virtual void processImage(PpmDocument &doc) = 0;
    virtual ~ImageEffect() {}
};

#endif // ! IMAGE_EFFECT_H

