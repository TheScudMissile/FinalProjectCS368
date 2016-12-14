//
//  Sprite.hpp
//  Base_Defense
//
//  Created by Benjamin Scudder on 11/8/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Graphics.hpp"

class Sprite
{
public:
    Sprite();
    
    // sourceX, sourceY - spot on sprite sheet
    // posX, posY - where sprite starts on screen
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX,
           int sourceY, int width, int height, float posX, float posY);
    
    
    // Overrideable
    virtual ~Sprite();
    virtual void update();
    
    int getHeight();
    int getWidth();
    
    void draw(Graphics &graphics, int x, int y);
    
protected:
    SDL_Rect sourceRect;
    SDL_Texture *spriteSheet;
};

#endif /* Sprite_hpp */
