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
		cout << "Enter a number from 1 to 5 on how pixelated you want the image to be: ";
		getline(cin, input);
		pixelation_degree = stoi(input);

		for (int i = 0; i < height; i+= pixelation_degree)
		{
			for (int j = 0; j < width; j+= pixelation_degree)
			{
				Pixel the_pixel_to_rule_them_all = doc.getPixel(i, j);
				int pixels_left_of_ruling_pixel = j - pixelation_degree;
				int pixels_right_of_ruling_pixel = j + pixelation_degree;
				int pixels_below_ruling_pixel = i + pixelation_degree;
				int pixels_above_ruling_pixel = i - pixelation_degree;

				if ((pixels_left_of_ruling_pixel < 0) || (pixels_right_of_ruling_pixel >= width - 1))
				{
					if (pixels_left_of_ruling_pixel < 0)
					{
						for (int n = j; n >= 0; n--)
						{
							doc.setPixel(i, n, the_pixel_to_rule_them_all);

						}
					}
					
					if (pixels_right_of_ruling_pixel >= width - 1)
					{
						for (int n = j; n < width; n++)
						{
							doc.setPixel(i, n, the_pixel_to_rule_them_all);
						}
					}
				}
				else
				{
					for (int n = j; n > pixels_left_of_ruling_pixel; n--)
					{
						doc.setPixel(i, n, the_pixel_to_rule_them_all);
					}
					
					for (int n = j; n < pixels_right_of_ruling_pixel; n++)
					{
						doc.setPixel(i, n, the_pixel_to_rule_them_all);
					}
				}
				
				if ((pixels_above_ruling_pixel < 0) || (pixels_below_ruling_pixel > height - 1))
				{
					if (pixels_above_ruling_pixel < 0)
					{
						for (int n = i; n >= 0; n--)
						{
							doc.setPixel(n, j, the_pixel_to_rule_them_all);
						}
					}
					
					if (pixels_below_ruling_pixel > height - 1)
					{
						for (int n = i; n < height; n++)
						{
							doc.setPixel(n, j, the_pixel_to_rule_them_all);
						}
					}
				}
				else
				{
					for (int n = i; n > pixels_above_ruling_pixel; n--)
					{
						doc.setPixel(n, j, the_pixel_to_rule_them_all);
					}

					for (int n = i; n < pixels_below_ruling_pixel; n++)
					{
						doc.setPixel(n, j, the_pixel_to_rule_them_all);
					}
				}

			}
		}
	}
};

#endif // !PIXELATE_IMAGE_EFFECT_H