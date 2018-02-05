#pragma once
#ifndef DECODER_H
#define DECODER_H

#include <vector>
#include "PpmDocument.h"

class Decoder
{
public:
	string imageDecoder(PpmDocument &doc)
	{
		string decoded;
		
		Pixel pixel_to_decode = doc.getPixel(0, 0);
		int character = pixel_to_decode.getRed();
		int y_coord = pixel_to_decode.getGreen();
		int x_coord = pixel_to_decode.getBlue();
		decoded += character;
		
		while (x_coord != 0 && y_coord != 0)
		{
			pixel_to_decode = doc.getPixel(y_coord, x_coord);
			character = pixel_to_decode.getRed();
			decoded += character;
			y_coord = pixel_to_decode.getGreen();
			x_coord = pixel_to_decode.getBlue();
		}

		return decoded;
	}

};

#endif // !DECODER_H
