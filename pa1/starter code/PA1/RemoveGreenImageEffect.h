#pragma once
#ifndef REMOVE_GREEN_EFFECT_H
#define REMOVE_GREEN_EFFECT_H

#include "ImageEffect.h"

//this image effect will remove all green from a picture
class RemoveGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		for (int i = 0; i < doc.getWidth(); i++)
		{
			for (int j = 0; j < doc.getHeight(); i++)
			{
				doc.setPixel(i, j, 0);
			}
		}
    }

};

#endif // !REMOVE_GREEN_EFFECT_H

#include "ImageEffect.h"

