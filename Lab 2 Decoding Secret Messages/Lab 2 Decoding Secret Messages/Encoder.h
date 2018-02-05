#pragma once
#ifndef ENCODER_H
#define ENCODER_H

#include "PpmDocument.h"

using namespace std;

class Encoder
{
public:
	void encodeImage(PpmDocument &doc, string message_to_encode)
	{
		string message = message_to_encode;
		int counter = message.size() - 1;
		int prev_x_coord, prev_y_coord, message_int;
		int i = doc.getHeight() - 1;
		Pixel pixel_to_encode = doc.getPixel(0,0);

		while(counter > -1)
		{
			for (int j = doc.getWidth() - 1; j > -1; j--)
			{
				if (counter == 0)
				{
					message_int = message[counter];
					pixel_to_encode = doc.getPixel(0, 0);
					pixel_to_encode.setRed(message_int);
					pixel_to_encode.setGreen(prev_y_coord);
					pixel_to_encode.setBlue(prev_x_coord);
					doc.setPixel(0, 0, pixel_to_encode);
					counter--;
					break;
				}
				else if ((counter > 0 ) && ((i + j) % 3 == 0))
				{
					if (counter == message.size() - 1)
					{
						message_int = message[counter];
						pixel_to_encode = doc.getPixel(i, j);
						pixel_to_encode.setRed(message_int);
						pixel_to_encode.setGreen(0);
						pixel_to_encode.setBlue(0);
						doc.setPixel(i, j, pixel_to_encode);
						prev_x_coord = j;
						prev_y_coord = i;
						counter--;
					}
					else
					{
						message_int = message[counter];
						pixel_to_encode = doc.getPixel(i, j);
						pixel_to_encode.setRed(message_int);
						pixel_to_encode.setGreen(prev_y_coord);
						pixel_to_encode.setBlue(prev_x_coord);
						doc.setPixel(i, j, pixel_to_encode);
						prev_x_coord = j;
						prev_y_coord = i;
						counter--;
					}
				}

			}
			
			i--;
		}

	}
};

#endif // !ENCODER_H
