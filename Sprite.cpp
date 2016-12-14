//
//  Sprite.cpp
//  Base_Defense
//
//  Created by Benjamin Scudder on 11/8/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//

#include "Sprite.hpp"
#include "Globals.hpp"

Sprite::Sprite()
{
    
}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX,
       int sourceY, int width, int height, float posX, float posY)
{
    sourceRect.x = sourceX;
    sourceRect.y = sourceY;
    sourceRect.w = width;
    sourceRect.h = height;
    
    spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if (spriteSheet == NULL)
    {
        printf("\nError: Unable to load image\n");
    }
}

Sprite::~Sprite()
{
    
}

int Sprite::getWidth()
{
    return sourceRect.w;
}

int Sprite::getHeight()
{
    return sourceRect.h;
}

void Sprite::draw(Graphics &graphics, int x, int y)
{
    SDL_Rect destRect = {x, y, sourceRect.w * Globals::SCALE_SPRITE, sourceRect.h * Globals::SCALE_SPRITE};
    graphics.blitSurface(spriteSheet, &sourceRect, &destRect);
}

void Sprite::update()
{
    
}
