//
//  Graphics.cpp - Holds graphics info for game
//  Base_Defense
//
//  Created by Benjamin Scudder on 10/29/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//
//
//

#include "Graphics.hpp"
#include "Globals.hpp"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(Globals::WIDTH, Globals::HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "BaseDefense");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
    // image not loaded yet
    if (spriteSheets.count(filePath) == 0)
    {
        spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle,
                           SDL_Rect *destRectangle)
{
    // copy image to renderer
    SDL_RenderCopy(renderer, source, sourceRectangle, destRectangle);
}

void Graphics::setColor()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Graphics::flip()
{
    SDL_RenderPresent(renderer);
}

void Graphics::clear()
{
    SDL_RenderClear(renderer);
}

SDL_Renderer *Graphics::getRenderer() const
{
    return renderer;
}







