#pragma once
#ifndef REMOVE_RED_IMAGE_EFFECT 
#define REMOVE_RED_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will remove all red from a picture
class RemoveRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				Pixel pixel_to_change = doc.getPixel(i, j);
				pixel_to_change.setRed(0);
				doc.setPixel(i, j, pixel_to_change);
            }
        }
    }

};

#endif // !REMOVE_RED_IMAGE_EFFECT 