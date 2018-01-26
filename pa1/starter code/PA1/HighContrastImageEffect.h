#pragma once
#ifndef HIGH_CONTRAST_IMAGE_EFFECT_H
#define HIGH_CONTRAST_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

class HighContrastImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int half_max_rgb = doc.getMaxRgb() / 2;

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel &pixel_to_change = doc.getPixel(i, j);
				int red_value = pixel_to_change.getRed();
				int green_value = pixel_to_change.getGreen();
				int blue_value = pixel_to_change.getBlue();

				if (red_value < half_max_rgb)
				{
					red_value = 0;
				}
				else 
				{
					red_value = 255;
				}

				if (green_value < half_max_rgb)
				{
					green_value = 0;
				}
				else 
				{
					green_value = 255;
				}

				if (blue_value < half_max_rgb)
				{
					blue_value = 0;
				}
				else 
				{
					blue_value = 255;
				}

				pixel_to_change.setRed(red_value);
				pixel_to_change.setGreen(green_value);
				pixel_to_change.setBlue(blue_value);
				doc.setPixel(i, j, pixel_to_change);
			}
		}
	}
};

#endif // !HIGH_CONTRAST_IMAGE_EFFECT_H