#pragma once
#ifndef ROTATE_NINETY_DEGREES_IMAGE_EFFECT_H
#define ROTATE_NINETY_DEGREES_IMAGE_EFFECT_H

#include "ImageEffect.h"
#include "PpmDocument.h"

using namespace std;

class RotateNinetyDegreesImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		string input;
		int direction, width, height;
		cout << "Enter 1 to rotate left. Enter 2 to rotate right.\n Which direction: ";
		getline(cin, input);
		direction = stoi(input);
		
		height = doc.getHeight();
		width = doc.getWidth();

		cout << "Doc Width: " << width << " Doc Height: " << height << endl;

		PpmDocument doc_copy(doc);

		doc.setHeight(width);
		doc.setWidth(height);

		cout << "Doc Width: " << doc.getWidth() << " Doc Height: " << doc.getHeight() << endl;
		cout << "Doc_copy Width: " << doc_copy.getWidth() << " Doc_copy Height: " << doc_copy.getHeight() << endl;

		if (direction == 1)
		{
			for (int i = 0; i < height; i++)
			{
				for (int j = width; j > 0; j--)
				{
					
					//Pixel rotated_pixel = doc_copy.getPixel(i, j);
					//doc.setPixel(j, height - i, rotated_pixel);
				}
			}
		}
		else
		{
			for (int i = 0; i < doc_copy.getHeight(); i++)
			{
				for (int j = 0; j < doc_copy.getWidth(); j++)
				{
					Pixel rotated_pixel = doc_copy.getPixel(i, j);
					doc.setPixel(j, height - i - 1, rotated_pixel);
				}
			}
		}
	}
};

#endif // !ROTATE_NINETY_DEGREES_IMAGE_EFFECT_H
