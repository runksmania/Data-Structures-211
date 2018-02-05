#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include "PpmDocument.h"
#include "Decoder.h"
#include "Encoder.h"

using namespace std;

enum colors_t { RED = 0, GREEN, BLUE };
PpmDocument ppmDocumentFromFile(string file_name);
void ppmDocumentToFile(PpmDocument &doc, string file_name);
void encode_or_decode();
void decode();
void encode();

int main()
{
	encode_or_decode();

	return 0;
}

PpmDocument ppmDocumentFromFile(string file_name)
{
	PpmDocument doc{ "P3" };

	//open PPM for file processing
	ifstream source_ppm{ file_name };

	//were we able to open the file?
	if (source_ppm.is_open() == true)
	{
		//grab basic PPM info before starting file
		//loop
		string ppm_type = "";
		string dimensions = "";
		string max_rgb = "";
		getline(source_ppm, ppm_type);
		getline(source_ppm, dimensions);
		getline(source_ppm, max_rgb);

		//convert strings into INTs for PPM document
		int width = 0;
		int height = 0;
		int rgb = 0;
		istringstream dimensions_stream{ dimensions };
		dimensions_stream >> width;
		dimensions_stream >> height;
		rgb = stoi(max_rgb);
		doc = PpmDocument{ ppm_type, width, height, rgb };

		//convert PPM
		while (source_ppm.good() == true)
		{
			int next_value = 0;
			int color_counter = 0;
			int row_counter = 0;
			int col_counter = 0;

			//grab next number irrespective of
			//line
			Pixel temp_pixel{};
			while (source_ppm >> next_value)
			{
				if (color_counter == RED)
				{
					temp_pixel.setRed(next_value);
				}
				else if (color_counter == GREEN)
				{
					temp_pixel.setGreen(next_value);
				}
				else if (color_counter == BLUE)
				{
					//BLUE represents a finished pixel
					temp_pixel.setBlue(next_value);

					//save finished pixel to document
					doc.setPixel(row_counter, col_counter, temp_pixel);

					col_counter++;
					if (col_counter >= doc.getWidth())
					{
						col_counter = 0;
						row_counter++;
					}
				}
				color_counter++;
				color_counter %= 3;
			}
		}
	}
	source_ppm.close();
	return doc;
}

void ppmDocumentToFile(PpmDocument &doc, string file_name)
{
	ofstream output_ppm{ file_name };
	output_ppm << doc.getDocType() << endl;
	output_ppm << doc.getWidth() << " " << doc.getHeight() << endl;
	output_ppm << doc.getMaxRgb() << endl;
	for (int i = 0; i < doc.getHeight(); i++)
	{
		for (int j = 0; j < doc.getWidth(); j++)
		{
			output_ppm << doc.getPixel(i, j).toString() << " ";
		}
		output_ppm << endl;
	}
	output_ppm.close();
}

void encode_or_decode()
{
	cout << "Do you wish to encode a file or decode a file? \n 1 for Encode. \n 2 for Decode. \n";
	cout << "What do you wish to do: ";
	string decision_str;
	getline(cin, decision_str);
	int decision = stoi(decision_str);

	if (decision == 2)
	{
		decode();
	}
	else
	{
		encode();
	}
}

void decode()
{
	//grab source PPM from the user
	cout << "Enter input file: ";
	string input_file_name = "";
	getline(cin, input_file_name);

	PpmDocument doc = ppmDocumentFromFile(input_file_name);
	Decoder decoder{};
	string decoded_message = decoder.imageDecoder(doc);

	cout << decoded_message;
	cout << endl;
}

void encode()
{
	//grab source PPM from the user
	cout << "Enter input file: ";
	string input_file_name = "";
	getline(cin, input_file_name);

	//grab destination file from user
	cout << "Enter destination file: ";
	string output_file_name = "";
	getline(cin, output_file_name);
	
	//grab message from user to encode into file.
	cout << "Enter message to encode.  No line breaks.\n";
	string message = "";
	getline(cin, message);

	PpmDocument doc = ppmDocumentFromFile(input_file_name);
	Encoder encoder{};
	encoder.encodeImage(doc, message);
	ppmDocumentToFile(doc, output_file_name);
}