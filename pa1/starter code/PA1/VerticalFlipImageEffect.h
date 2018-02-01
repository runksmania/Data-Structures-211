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
#ifndef VERTICAL_FLIP_IMAGE_EFFECT_H
#define VERTICAL_FLIP_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

class VerticalFlipImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int height = doc.getHeight();
		int half_height = doc.getHeight() / 2;

		for (int i = 0; i < half_height; i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel temp_pixel;
				Pixel &top_pixel_to_swap = doc.getPixel(i, j);
				Pixel &bottom_pixel_to_swap = doc.getPixel(height - (i + 1), j);
				temp_pixel = bottom_pixel_to_swap;
				bottom_pixel_to_swap = top_pixel_to_swap;
				top_pixel_to_swap = temp_pixel;
			}
		}
	}
};

#endif // !VERTICAL_FLIP_IMAGE_EFFECT_H