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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		int prev_x_coord, prev_y_coord, rand_x_coord, rand_y_coord;
		int height = doc.getHeight();
		int width = doc.getWidth();
=======
		int prev_x_coord, prev_y_coord, message_int;
		int i = doc.getHeight() - 1;
>>>>>>> parent of e222f4f... Added Random Encoding to:
		Pixel pixel_to_encode = doc.getPixel(0,0);
=======
		int prev_x_coord, prev_y_coord;
		int i = doc.getHeight() - 1;
		Pixel &pixel_to_encode = doc.getPixel(0,0);
>>>>>>> parent of 548c118... Finalized the following solution:
=======
		int prev_x_coord, prev_y_coord;
		int i = doc.getHeight() - 1;
		Pixel &pixel_to_encode = doc.getPixel(0,0);
>>>>>>> parent of 548c118... Finalized the following solution:

		while(counter > -1)
		{
			for (int j = doc.getWidth() - 1; j > -1; j--)
			{
<<<<<<< HEAD
				rand_x_coord = rand() % width;
				rand_y_coord = rand() % height;

				if (counter == message.size() - 1)
				{
<<<<<<< HEAD
					pixel_to_encode = doc.getPixel(rand_y_coord, rand_x_coord);
					pixel_to_encode.setRed(message[counter]);
					pixel_to_encode.setGreen(0);
					pixel_to_encode.setBlue(0);
					doc.setPixel(rand_y_coord, rand_x_coord, pixel_to_encode);
					prev_x_coord = rand_x_coord;
					prev_y_coord = rand_y_coord;
=======
					pixel_to_encode = doc.getPixel(0, 0);
					pixel_to_encode.setRed(message[0]);
					pixel_to_encode.setGreen(prev_x_coord);
					pixel_to_encode.setBlue(prev_y_coord);
					cout << "Message counter: " << message[counter] << endl;
					cout << "I: " << i << " J: " << j << endl;
					cout << "Previous x coord: " << prev_x_coord << " Previous y coord: " << prev_y_coord << endl << endl;
>>>>>>> parent of 548c118... Finalized the following solution:
					counter--;
				}
<<<<<<< HEAD
				else
=======
				if (counter == 0)
>>>>>>> parent of e222f4f... Added Random Encoding to:
				{
					pixel_to_encode = doc.getPixel(0, 0);
					pixel_to_encode.setRed(message[0]);
					pixel_to_encode.setGreen(prev_x_coord);
					pixel_to_encode.setBlue(prev_y_coord);
					cout << "Message counter: " << message[counter] << endl;
					cout << "I: " << i << " J: " << j << endl;
					cout << "Previous x coord: " << prev_x_coord << " Previous y coord: " << prev_y_coord << endl << endl;
					counter--;
<<<<<<< HEAD
=======
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
>>>>>>> parent of 548c118... Finalized the following solution:
=======
					break;
>>>>>>> parent of e222f4f... Added Random Encoding to:
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
