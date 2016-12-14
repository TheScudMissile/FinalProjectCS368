//
//  Game.cpp - holds game loop info
//  Base_Defense
//
//  Created by Benjamin Scudder on 11/3/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//

#include "Game.hpp"
#include "Globals.hpp"

namespace
{
  //  const int FPS = 50;
   // const int MAX_FRAME_LENGTH = 5 * 1000 / FPS;
}

Game::Game()
{
    
    // initialize all SDL init flags
    SDL_Init(SDL_INIT_EVERYTHING);
    
    gameLoop();
}

Game::~Game()
{
    
}

void Game::gameLoop()
{
    bool running = true;
    shooting = false;
    Graphics graphics;
    int currTurretPos = 0;
    
    // hold event during single frame
    SDL_Event event;
    
    gunner0Deg = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/gunner.png", 0, 0, 37.0, 37.0,
                    0, 442.5);
    
    gunner30Deg = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/gunner.png", 42, 0, 37.0, 37.0,
                        0, 442.5);
    
    gunner45Deg = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/gunner.png", 0, 53, 37.0, 26.0,
                        0, 442.5);
    
    gunner60Deg = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/gunner.png", 42, 53, 37.0, 26.0,
                        0, 442.5);

    enemy = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/parachute.png", 0, 0, 37.0, 37.0,
                   0, 300);
    
    bullet = Sprite(graphics, "/Users/BScudder/Desktop/Base_Defense/bullet.png", 15.0, 14.0, 5.0, 5.0,
                   0, 442.5);
    
    enemyY = 0;
    enemyX = 4*(rand() % 100) + 50;
    
    bullet.draw(graphics, bulletInitX, bulletInitY);
    draw0Deg(graphics);
    
    // start game loop
    while (running)
    {
        
        // update keys
       // input.beginNewFrame();
        update(graphics, currTurretPos);
        
        // poll for pending events and place in var
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            draw60Deg(graphics);
                            currTurretPos = 60;
                            break;
                    
                        case SDLK_UP:
                            draw45Deg(graphics);
                            currTurretPos = 45;
                            break;
                    
                        case SDLK_RIGHT:
                            draw30Deg(graphics);
                            currTurretPos = 30;
                            break;
                    
                        case SDLK_DOWN:
                            draw0Deg(graphics);
                            currTurretPos = 0;
                            break;
                            
                        case SDLK_SPACE:
                            shooting = true;
                            break;
                        
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                    }
                    break;
            
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }
    return;
}

void Game::draw0Deg(Graphics &graphics)
{
    graphics.setColor();
    graphics.clear();
    
    gunner0Deg.draw(graphics, 0, Globals::HEIGHT - (gunner0Deg.getHeight() * Globals::SCALE_SPRITE));
    enemy.draw(graphics, enemyX, enemyY);
    
    graphics.flip();
}

void Game::draw30Deg(Graphics &graphics)
{
    graphics.setColor();
    graphics.clear();
    
    gunner30Deg.draw(graphics, 0, Globals::HEIGHT - (gunner30Deg.getHeight() * Globals::SCALE_SPRITE));
    enemy.draw(graphics, enemyX, enemyY);
    
    graphics.flip();
}

void Game::draw45Deg(Graphics &graphics)
{
    graphics.setColor();
    graphics.clear();
    
    gunner45Deg.draw(graphics, 0, Globals::HEIGHT - (gunner45Deg.getHeight() * Globals::SCALE_SPRITE));
    enemy.draw(graphics, enemyX, enemyY);
    
    graphics.flip();
}


void Game::draw60Deg(Graphics &graphics)
{
    graphics.setColor();
    graphics.clear();
    
    gunner60Deg.draw(graphics, 0, Globals::HEIGHT - (gunner60Deg.getHeight() * Globals::SCALE_SPRITE));
    enemy.draw(graphics, enemyX, enemyY);
    
    graphics.flip();
}

void Game::update(Graphics &graphics, int turretPos)
{
    graphics.setColor();
    graphics.clear();
    
    switch (turretPos)
    {
        case 0:
            
            if (shooting)
            {
                bullet.draw(graphics, bulletX += dx0, bulletY -= dy0);
            }
            gunner0Deg.draw(graphics, 0, Globals::HEIGHT - (gunner0Deg.getHeight() * Globals::SCALE_SPRITE));
            break;
            
        case 30:
            
            if (shooting)
            {
                bullet.draw(graphics, bulletX += dx30, bulletY -= dy30);
            }
            gunner30Deg.draw(graphics, 0, Globals::HEIGHT - (gunner30Deg.getHeight() * Globals::SCALE_SPRITE));
            break;
            
        case 45:
                
            if (shooting)
            {
                bullet.draw(graphics, bulletX += dx45, bulletY -= dy45);
            }
            gunner45Deg.draw(graphics, 0, Globals::HEIGHT - (gunner45Deg.getHeight() * Globals::SCALE_SPRITE));
            break;
            
        case 60:
            
            if (shooting)
            {
                bullet.draw(graphics, bulletX += dx60, bulletY -= dy60);
            }
            gunner60Deg.draw(graphics, 0, Globals::HEIGHT - (gunner60Deg.getHeight() * Globals::SCALE_SPRITE));
            break;
    }

    if (bulletX > Globals::WIDTH || bulletY < 0)
    {
        shooting = false;
        bulletX = bulletInitX;
        bulletY = bulletInitY;
        bullet.draw(graphics, bulletX, bulletY);
    }
    
    if (((bulletY - enemyY) >= 0 && (bulletY - enemyY) <= 2 * enemy.getHeight()) && ((bulletX - enemyX) >= 0 && (bulletX - enemyX) <= enemy.getWidth()))
    {
        collision = true;
        shooting = false;
        bullet.draw(graphics, bulletInitX, bulletInitY);
        bulletX = bulletInitX;
        bulletY = bulletInitY;

    }
    
    if (enemyY > Globals::HEIGHT + 50 || collision)
    {
        enemyX = 4*(rand() % 100) + 50;
        enemyY = -(enemy.getHeight() + 50);
        collision = false;
    }
    
    enemy.draw(graphics, enemyX, enemyY += dy);
    graphics.flip();
}
