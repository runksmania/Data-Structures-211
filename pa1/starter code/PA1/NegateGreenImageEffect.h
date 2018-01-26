#pragma once
#ifndef NEGATE_GREEN_IMAGE_EFFECT_H
#define NEGATE_GREEN_IMAGE_EFFECT_H

#include "ImageEffect.h"

class NegateGreenImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel pixel_to_change = doc.getPixel(i, j);
				int green_value = 255 - pixel_to_change.getGreen();
				pixel_to_change.setGreen(green_value);
				doc.setPixel(i, j, pixel_to_change);
			}
		}
	}
};

#endif // !NEGATE_GREEN_IMAGE_EFFECT_H