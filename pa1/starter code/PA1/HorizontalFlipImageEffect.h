#pragma once
#ifndef HORIZONTAL_FLIP_IMAGE_EFFECT_H
#define HORIZONTAL_FLIP_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

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