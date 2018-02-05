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
		
		height = doc.getHeight();
		width = doc.getWidth();

		PpmDocument doc_copy(doc);

		doc.setHeight(width);
		doc.setWidth(height);

		cout << "Enter 1 to rotate left. Enter 2 to rotate right.\n Which direction: ";
		getline(cin, input);
		direction = stoi(input);

		if (direction > 2 || direction < 1)
		{
			while (direction > 2 || direction < 1)
			{
				cout << "Error. You have entered an incorrect amount. Please try again.\n";
				cout << "Enter 1 to rotate left. Enter 2 to rotate right.\n Which direction: ";
				getline(cin, input);
				direction = stoi(input);
			}
		}
		
		

		if (direction == 1)
		{
			for (int i = 0; i < doc_copy.getHeight(); i++)
			{
				for (int j = 0; j < doc_copy.getWidth(); j++)
				{
					
					Pixel rotated_pixel = doc_copy.getPixel(i, j);
					doc.setPixel(width - j - 1, i, rotated_pixel);
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
