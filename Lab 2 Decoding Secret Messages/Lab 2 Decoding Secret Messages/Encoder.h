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
		int prev_x_coord, prev_y_coord;
		int i = doc.getHeight() - 1;
		Pixel &pixel_to_encode = doc.getPixel(0,0);

		while(counter > -1)
		{
			for (int j = doc.getWidth() - 1; j > -1; j--)
			{
				if (counter == 0)
				{
					pixel_to_encode = doc.getPixel(0, 0);
					pixel_to_encode.setRed(message[0]);
					pixel_to_encode.setGreen(prev_x_coord);
					pixel_to_encode.setBlue(prev_y_coord);
					cout << "Message counter: " << message[counter] << endl;
					cout << "I: " << i << " J: " << j << endl;
					cout << "Previous x coord: " << prev_x_coord << " Previous y coord: " << prev_y_coord << endl << endl;
					counter--;
					break;
				}
				else if ((counter >= 0 ) && ((i + j) % 3 == 1))
				{
					if (counter == message.size() - 1)
					{
						pixel_to_encode = doc.getPixel(i, j);
						pixel_to_encode.setRed(message[counter]);
						pixel_to_encode.setGreen(0);
						pixel_to_encode.setBlue(0);
						prev_x_coord = i;
						prev_y_coord = j;
						counter--;
						cout << "Message counter: " << message[counter] << endl;
						cout << "I: " << i << " J: " << j << endl;
						cout << "Previous x coord: " << prev_x_coord << " Previous y coord: " << prev_y_coord << endl << endl;
					}
					else
					{
						pixel_to_encode = doc.getPixel(i, j);
						pixel_to_encode.setRed(message[counter]);
						pixel_to_encode.setGreen(prev_x_coord);
						pixel_to_encode.setBlue(prev_y_coord);
						prev_x_coord = i;
						prev_y_coord = j;
						counter--;
						cout << "Message counter: " << message[counter] << endl;
						cout << "I: " << i << " J: " << j << endl;
						cout << "Previous x coord: " << prev_x_coord << " Previous y coord: " << prev_y_coord << endl << endl;
					}
				}

			}
			
			i--;
		}

	}
};

#endif // !ENCODER_H
