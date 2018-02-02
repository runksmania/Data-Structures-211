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
#ifndef NEGATE_RED_IMAGE_EFFECT_H
#define NEGATE_RED_IMAGE_EFFECT_H

#include "ImageEffect.h"

//This image effect will negate red from an image.
class NegateRedImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel pixel_to_change = doc.getPixel(i, j);
				int red_value = 255 - pixel_to_change.getRed();
				pixel_to_change.setRed(red_value);
				doc.setPixel(i, j, pixel_to_change);

			}
		}
	}
};

#endif // !BNEGATE_RED_IMAGE_EFFECT_H