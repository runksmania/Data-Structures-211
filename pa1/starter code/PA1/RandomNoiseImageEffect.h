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
#ifndef RANDOM_NOISE_IMAGE_EFFECT_H
#define RANDOM_NOISE_IMAGE_EFFECT_H

#include <cstdlib>
#include <stdio.h>
#include "ImageEffect.h"
#include "Time.h"

using namespace std;

//This image effect will add random noise to an image.
class RandomNoiseImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int rand_pos_neg, rand_amount_noise;
		srand(time(NULL));

		for (int i = 0; i < doc.getHeight(); i++)
		{
			rand_pos_neg = rand() % 2;
			rand_amount_noise = rand() % 10 + 1;

			if (rand_pos_neg == 0)
			{
				rand_amount_noise *= -1;
			}

			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel &pixel_to_change = doc.getPixel(i, j);
				int red_value = pixel_to_change.getRed() + rand_amount_noise;
				int green_value = pixel_to_change.getGreen() + rand_amount_noise;
				int blue_value = pixel_to_change.getBlue() + rand_amount_noise;

				if (red_value < 0)
				{
					red_value = 0;
				}
				else if (red_value > 255)
				{
					red_value = 255;
				}

				if (green_value < 0)
				{
					green_value = 0;
				}
				else if (green_value > 255)
				{
					green_value = 255;
				}

				if (blue_value < 0)
				{
					blue_value = 0;
				}
				else if (blue_value > 255)
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

#endif // !RANDOM_NOISE_IMAGE_EFFECT_H