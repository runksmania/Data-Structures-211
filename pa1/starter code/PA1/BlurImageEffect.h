#pragma once
#ifndef BLUR_IMAGE_EFFECT_H
#define BLUR_IMAGE_EFFECT_H

#include "ImageEffect.h"

using namespace std;

class BlurImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		string input;
		int blur_degree;
		cout << "Enter a number from 1 to 10 on how blurry you want the image to be: ";
		getline(cin, input);
		blur_degree = stoi(input);
		
		for (int n = 0; n < blur_degree; n++)
		{
			for (int i = 0; i < doc.getHeight(); i++)
			{
				for (int j = 0; j < doc.getWidth(); j++)
				{
					//Change each pixels value to the average of its horizontal neighbors

					if (j == 0)
					{
						Pixel &left_pixel = doc.getPixel(i, j);
						Pixel &right_pixel = doc.getPixel(i, j + 1);

						int red_avg = (left_pixel.getRed() + right_pixel.getRed()) / 2;
						int green_avg = (left_pixel.getGreen() + right_pixel.getGreen()) / 2;
						int blue_avg = (left_pixel.getBlue() + right_pixel.getBlue()) / 2;

						left_pixel.setRed(red_avg);
						left_pixel.setGreen(green_avg);
						left_pixel.setBlue(blue_avg);

						right_pixel.setRed(red_avg);
						right_pixel.setGreen(green_avg);
						right_pixel.setBlue(blue_avg);
					}
					else if (j == (doc.getWidth() - 1))
					{
						Pixel &left_pixel = doc.getPixel(i, j - 1);
						Pixel &right_pixel = doc.getPixel(i, j);

						int red_avg = (left_pixel.getRed() + right_pixel.getRed()) / 2;
						int green_avg = (left_pixel.getGreen() + right_pixel.getGreen()) / 2;
						int blue_avg = (left_pixel.getBlue() + right_pixel.getBlue()) / 2;

						left_pixel.setRed(red_avg);
						left_pixel.setGreen(green_avg);
						left_pixel.setBlue(blue_avg);

						right_pixel.setRed(red_avg);
						right_pixel.setGreen(green_avg);
						right_pixel.setBlue(blue_avg);
					}
					else
					{
						Pixel &left_pixel = doc.getPixel(i, j - 1);
						Pixel &middle_pixel = doc.getPixel(i, j);
						Pixel &right_pixel = doc.getPixel(i, j + 1);

						int red_avg = (left_pixel.getRed() + middle_pixel.getRed() + right_pixel.getRed()) / 3;
						int green_avg = (left_pixel.getGreen() + middle_pixel.getGreen() + right_pixel.getGreen()) / 3;
						int blue_avg = (left_pixel.getBlue() + middle_pixel.getBlue() + right_pixel.getBlue()) / 3;

						left_pixel.setRed(red_avg);
						left_pixel.setGreen(green_avg);
						left_pixel.setBlue(blue_avg);

						middle_pixel.setRed(red_avg);
						middle_pixel.setGreen(green_avg);
						middle_pixel.setBlue(blue_avg);

						right_pixel.setRed(red_avg);
						right_pixel.setGreen(green_avg);
						right_pixel.setBlue(blue_avg);
					}

					//Change each pixel value to the average of its vertical neighbors

					if (i == 0)
					{
						Pixel &top_pixel = doc.getPixel(i, j);
						Pixel &bottom_pixel = doc.getPixel(i + 1, j);

						int red_vert_avg = (top_pixel.getRed() + bottom_pixel.getRed()) / 2;
						int green_vert_avg = (top_pixel.getGreen() + bottom_pixel.getGreen()) / 2;
						int blue_vert_avg = (top_pixel.getBlue() + bottom_pixel.getBlue()) / 2;

						top_pixel.setRed(red_vert_avg);
						top_pixel.setGreen(green_vert_avg);
						top_pixel.setBlue(blue_vert_avg);

						bottom_pixel.setRed(red_vert_avg);
						bottom_pixel.setGreen(green_vert_avg);
						bottom_pixel.setBlue(blue_vert_avg);
					}
					else if (i == (doc.getHeight() - 1))
					{
						Pixel &top_pixel = doc.getPixel(i - 1, j);
						Pixel &bottom_pixel = doc.getPixel(i, j);

						int red_vert_avg = (top_pixel.getRed() + bottom_pixel.getRed()) / 2;
						int green_vert_avg = (top_pixel.getGreen() + bottom_pixel.getGreen()) / 2;
						int blue_vert_avg = (top_pixel.getBlue() + bottom_pixel.getBlue()) / 2;

						top_pixel.setRed(red_vert_avg);
						top_pixel.setGreen(green_vert_avg);
						top_pixel.setBlue(blue_vert_avg);

						bottom_pixel.setRed(red_vert_avg);
						bottom_pixel.setGreen(green_vert_avg);
						bottom_pixel.setBlue(blue_vert_avg);
					}
					else
					{
						Pixel &top_pixel = doc.getPixel(i - 1, j);
						Pixel &middle_vert_pixel = doc.getPixel(i, j);
						Pixel &bottom_pixel = doc.getPixel(i + 1, j);

						int red_vert_avg = (top_pixel.getRed() + middle_vert_pixel.getRed() + bottom_pixel.getRed()) / 3;
						int green_vert_avg = (top_pixel.getGreen() + middle_vert_pixel.getGreen() + bottom_pixel.getGreen()) / 3;
						int blue_vert_avg = (top_pixel.getBlue() + middle_vert_pixel.getRed() + bottom_pixel.getBlue()) / 3;

						top_pixel.setRed(red_vert_avg);
						top_pixel.setGreen(green_vert_avg);
						top_pixel.setBlue(blue_vert_avg);

						middle_vert_pixel.setRed(red_vert_avg);
						middle_vert_pixel.setGreen(green_vert_avg);
						middle_vert_pixel.setBlue(blue_vert_avg);

						bottom_pixel.setRed(red_vert_avg);
						bottom_pixel.setGreen(green_vert_avg);
						bottom_pixel.setBlue(blue_vert_avg);
					}
				}
			}
		}
	}
};

#endif // !BLUR_IMAGE_EFFECT_H