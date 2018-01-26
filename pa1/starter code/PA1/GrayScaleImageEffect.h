#pragma once
#ifndef GRAY_SCALE_IMAGE_EFFECT_H
#define GRAY_SCALE_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

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