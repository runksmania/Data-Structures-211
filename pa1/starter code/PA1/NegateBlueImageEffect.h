#pragma once
#ifndef NEGATE_BLUE_IMAGE_EFFECT_H
#define NEGATE_BLUE_IMAGE_EFFECT_H

#include "ImageEffect.h"

class NegateBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel pixel_to_change = doc.getPixel(i, j);
				int blue_value = 255 - pixel_to_change.getBlue();
				pixel_to_change.setBlue(blue_value);
				doc.setPixel(i, j, pixel_to_change);
			}
		}
	}
};

#endif // !NEGATE_Blue_IMAGE_EFFECT_H