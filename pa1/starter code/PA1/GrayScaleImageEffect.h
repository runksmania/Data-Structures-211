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
#ifndef GRAY_SCALE_IMAGE_EFFECT_H
#define GRAY_SCALE_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

//This image effect will change pixel value to the average of its original rgb values.
class GrayScaleImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int avg_rgb = 0;
				Pixel &pixel_to_change = doc.getPixel(i, j);
				int red_value = pixel_to_change.getRed();
				int green_value = pixel_to_change.getGreen();
				int blue_value = pixel_to_change.getBlue();

				avg_rgb = (red_value + green_value + blue_value) / 3;

				pixel_to_change.setRed(avg_rgb);
				pixel_to_change.setGreen(avg_rgb);
				pixel_to_change.setBlue(avg_rgb);
				doc.setPixel(i, j, pixel_to_change);
			}
		}
	}
};

#endif // !GRAY_SCALE_IMAGE_EFFECT_H