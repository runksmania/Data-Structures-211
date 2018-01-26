/*
Assignment: PA1
Description: Perform various image effects on ppm images.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: (Total Hours)
In completing this program, I received help from the following people:
Adam Carter
*/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include "PpmDocument.h"
#include "Pixel.h"
#include "ImageEffect.h"
#include "RemoveRedImageEffect.h"
#include "RemoveGreenImageEffect.h"
#include "RemoveBlueImageEffect.h"
#include "NegateRedImageEffect.h"
#include "NegateGreenImageEffect.h"
#include "NegateBlueImageEffect.h"
//#include "RandomNoiseImageEffect.h"
//#include "HighContrastImageEffect.h"
//#include "GrayScaleImageEffect.h"
#include "HorizontalFlipImageEffect.h"
#include "VerticalFlipImageEffect.h"
//#include "RotateNinetyDegreesImageEffect.h"
//#include "BlurImageEffect.h"
//#include "PixelateImageEffect.h"

using namespace std;

enum colors_t { RED = 0, GREEN, BLUE};
enum menu_options_t {REMOVE_RED = 1, REMOVE_GREEN = 2, REMOVE_BLUE = 3, NEGATE_RED = 4, NEGATE_GREEN = 5, NEGATE_BLUE = 6, ADD_RANDOM_NOISE = 7, HIGH_CONTRAST = 8, 
					 GRAY_SCALE = 9, HORIZONTAL_FLIP = 10, VERTICAL_FLIP = 11, ROTATE_90 = 12, BLUR_IMAGE = 13, PIXELATE_IMAGE = 14}; 
PpmDocument ppmDocumentFromFile(string file_name);
void ppmDocumentToFile(PpmDocument &doc, string file_name);
menu_options_t getMenuSelection();
void applyImageEffect(PpmDocument &doc, menu_options_t effect);

int main(void)
{
	//grab source PPM from the user
	cout << "Enter input file: ";
	string input_file_name = "";
	getline(cin, input_file_name);

    //grab destination file from user
    cout << "Enter destination file: ";
    string output_file_name = "";
    getline(cin, output_file_name);

    PpmDocument doc = ppmDocumentFromFile(input_file_name);
    menu_options_t selection = REMOVE_RED;
    while (selection > 0)
    {
        selection = getMenuSelection();
        if (selection > 0)
        {
            applyImageEffect(doc, selection);
        }
    }
    ppmDocumentToFile(doc, output_file_name);
	return 0;
}

PpmDocument ppmDocumentFromFile(string file_name)
{
    PpmDocument doc{ "P3"};

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
menu_options_t getMenuSelection()
{
    vector<string> menu_options{"", "Remove red", "Remove green", "Remove blue", "Negate red", "Negate green", "Negate blue", "Add random noise", "High contrast",
								"Gray scale", "Horizontal flip", "Vertical flip", "Rotate 90 degrees", "Blur image", "Pixelate image"};
    cout << "***Effect Menu***" << endl;
    for (int i = 1; i < menu_options.size(); i++)
    {
        cout << i << ". " << menu_options[i] << endl;
    }

    cout << "-1. Done applying effects" << endl;
    cout << "Apply which effect: ";
    string selection;
    getline(cin, selection);
    int result = stoi(selection);
    return (menu_options_t)result;
}
void applyImageEffect(PpmDocument &doc, menu_options_t option)
{

    ImageEffect *effect = nullptr;
    switch (option)
    {
    case REMOVE_RED:
        effect = new RemoveRedImageEffect();
        break;

    case REMOVE_GREEN:
        effect = new RemoveGreenImageEffect();
        break;

	case REMOVE_BLUE:
		effect = new RemoveBlueImageEffect();
	    break;

	case NEGATE_RED:
		effect = new NegateRedImageEffect();
		break;

	case NEGATE_GREEN:
		effect = new NegateGreenImageEffect();
		break;

	case NEGATE_BLUE:
		effect = new NegateBlueImageEffect();
		break;

	case ADD_RANDOM_NOISE:
	//	effect = new RandomNoiseImageEffect();
		break;

	case HIGH_CONTRAST:
	//	effect = new HighContrastImageEffect();
		break;

	case GRAY_SCALE:
	//	effect = new GrayScaleImageEffect();
		break;

	case HORIZONTAL_FLIP:
		effect = new HorizontalFlipImageEffect();
		break;

	case VERTICAL_FLIP:
		effect = new VerticalFlipImageEffect();
		break;

	case ROTATE_90:
	//	effect = new RotateNinetyDegreesImageEffect();
		break;

	case BLUR_IMAGE:
	//	effect = new BlurImageEffect();
		break;

	case PIXELATE_IMAGE:
	//	effect = new PixelateImageEffect();
		break;

    }

    if (effect != nullptr)
    {
        effect->processImage(doc);
    }
    delete effect;
}