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
#ifndef HORIZONTAL_FLIP_IMAGE_EFFECT_H
#define HORIZONTAL_FLIP_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

//This image effect will flip along the y axis.
class HorizontalFlipImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int width = doc.getWidth();
		int half_width = doc.getWidth() / 2;

		for (int i = 0; i < half_width; i++)
		{
			for (int j = 0; j < doc.getHeight(); j++)
			{
				Pixel temp_pixel;
				Pixel &left_pixel_to_swap = doc.getPixel(j, i);
				Pixel &right_pixel_to_swap = doc.getPixel(j, width - (i + 1));
				temp_pixel = right_pixel_to_swap;
				right_pixel_to_swap = left_pixel_to_swap;
				left_pixel_to_swap = temp_pixel;
			}
		}
	}
};

#endif // !HORIZONTAL_FLIP_IMAGE_EFFECT_H