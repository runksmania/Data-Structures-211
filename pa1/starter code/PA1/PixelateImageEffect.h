#pragma once
#ifndef PIXELATE_IMAGE_EFFECT_H
#define PIXELATE_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

class PixelateImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		string input;
		int pixelation_degree;
		int width = doc.getWidth();
		int height = doc.getHeight();
		cout << "Enter a number from 1 to 10 on how pixelated you want the image to be: ";
		getline(cin, input);
		pixelation_degree = stoi(input);

		if (pixelation_degree > 10 || pixelation_degree < 1)
		{
			while (pixelation_degree > 10 || pixelation_degree < 1)
			{
				cout << "Error. You have entered an incorrect amount. Please try again.\n";
				cout << "Enter a number from 1 to 10 on how pixelated you want the image to be: ";
				getline(cin, input);
				pixelation_degree = stoi(input);
			}
		}

		for (int i = 0; i < height; i += pixelation_degree)
		{
			for (int j = 0; j < width; j += pixelation_degree)
			{
				Pixel the_pixel_to_rule_them_all = doc.getPixel(i, j);
				int pixels_left_of_ruling_pixel, pixels_right_of_ruling_pixel, pixels_below_ruling_pixel, pixels_above_ruling_pixel;

				if (j - pixelation_degree < 0)
				{
					pixels_left_of_ruling_pixel = 0;
				}
				else
				{
					pixels_left_of_ruling_pixel = j - pixelation_degree;
				}

				if (j + pixelation_degree >= width)
				{
					pixels_right_of_ruling_pixel = width;
				}
				else
				{
					pixels_right_of_ruling_pixel = j + pixelation_degree;
				}

				if (i + pixelation_degree >= height)
				{
					pixels_below_ruling_pixel = height;
				}
				else
				{
					pixels_below_ruling_pixel = i + pixelation_degree;
				}

				if (i - pixelation_degree < 0)
				{
					pixels_above_ruling_pixel = 0;
				}
				else
				{
					pixels_above_ruling_pixel = i - pixelation_degree;
				}

				for (int w = j; w < pixels_right_of_ruling_pixel; w++)
				{
					doc.setPixel(i, w, the_pixel_to_rule_them_all);

					for (int h = i; h < pixels_below_ruling_pixel; h++)
					{
						doc.setPixel(h, w, the_pixel_to_rule_them_all);
					}

					for (int h = pixels_above_ruling_pixel; h > i; h--)
					{
						doc.setPixel(h, w, the_pixel_to_rule_them_all);
					}
				}

				for (int w = pixels_left_of_ruling_pixel; w > j; w--)
				{
					doc.setPixel(i, w, the_pixel_to_rule_them_all);

					for (int h = i; h < pixels_below_ruling_pixel; h++)
					{
						doc.setPixel(h, w, the_pixel_to_rule_them_all);
					}

					for (int h = pixels_above_ruling_pixel; h > i; h--)
					{
						doc.setPixel(h, w, the_pixel_to_rule_them_all);
					}
				}

			}
		}
	}
};

#endif // !PIXELATE_IMAGE_EFFECT_H