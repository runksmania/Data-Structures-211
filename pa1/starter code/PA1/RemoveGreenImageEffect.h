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
#ifndef REMOVE_GREEN_EFFECT_H
#define REMOVE_GREEN_EFFECT_H

#include "ImageEffect.h"

//this image effect will remove all green from a picture
class RemoveGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		for (int i = 0; i < doc.getHeight(); i++) 
		{
			for (int j = 0; j < doc.getWidth(); j++) 
			{
				Pixel pixel_to_change = doc.getPixel(i, j);
				pixel_to_change.setGreen(0);
				doc.setPixel(i, j, pixel_to_change);
			}
		}
    }

};

#endif // !REMOVE_GREEN_EFFECT_H