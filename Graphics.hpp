//
//  Graphics.hpp
//  Base_Defense
//
//  Created by Benjamin Scudder on 10/29/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//

#ifndef graphics_h
#define graphics_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>
#include <string>

// forward declare SDL struct types that will
// be used in .cpp file
struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
    Graphics();
    
    // destructor
    ~Graphics();
    
    // Load image into spriteSheets map if it doesn't exist
    SDL_Surface* loadImage(const std::string &filePath);
    
    
    // draws part of source (sprite on spriteSheet) to certain
    // part of screen (destination)
    void blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle,
                     SDL_Rect *destRectangle);
    
    // white background
    void setColor();
    
    // renders to screen
    void flip();
    
    // clear window
    void clear();
    
    // returns renderer
    SDL_Renderer *getRenderer () const;
    
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    std::map<std::string, SDL_Surface *> spriteSheets;
};

#endif /* Graphics_hpp */
