#pragma once
#ifndef ENCODER_H
#define ENCODER_H

#include "PpmDocument.h"
#include <cstdlib>
#include <time.h>

using namespace std;

class Encoder
{
public:
	void encodeImage(PpmDocument &doc, string message_to_encode)
	{
		string message = message_to_encode;
		int counter = message.size() - 1;
		int prev_x_coord, prev_y_coord, rand_x_coord, rand_y_coord;
		
		//The following height and width variables are set to height/width - 1 so that we can add 1 when we get rand number so we don't use 0, 0 for encoding messages until the final letter of the message.
		int height = doc.getHeight() - 1;
		int width = doc.getWidth() - 1;
		Pixel pixel_to_encode = doc.getPixel(0,0);

		srand(time(NULL));

		while(counter > -1)
		{
			if (counter == 0)
			{
				pixel_to_encode = doc.getPixel(0, 0);
				pixel_to_encode.setRed(message[counter]);
				pixel_to_encode.setGreen(prev_y_coord);
				pixel_to_encode.setBlue(prev_x_coord);
				doc.setPixel(0, 0, pixel_to_encode);
				counter--;
				break;
			}
			else
			{
				rand_x_coord = (rand() % width) + 1;
				rand_y_coord = (rand() % height) + 1;

				if (counter == message.size() - 1)
				{
					pixel_to_encode = doc.getPixel(rand_y_coord, rand_x_coord);
					pixel_to_encode.setRed(message[counter]);
					pixel_to_encode.setGreen(0);
					pixel_to_encode.setBlue(0);
					doc.setPixel(rand_y_coord, rand_x_coord, pixel_to_encode);
					prev_x_coord = rand_x_coord;
					prev_y_coord = rand_y_coord;
					counter--;
				}
				else
				{
					pixel_to_encode = doc.getPixel(rand_y_coord, rand_x_coord);
					pixel_to_encode.setRed(message[counter]);
					pixel_to_encode.setGreen(prev_y_coord);
					pixel_to_encode.setBlue(prev_x_coord);
					doc.setPixel(rand_y_coord, rand_x_coord, pixel_to_encode);
					prev_x_coord = rand_x_coord;
					prev_y_coord = rand_y_coord;
					counter--;
				}
			}
		}

	}
};

#endif // !ENCODER_H
