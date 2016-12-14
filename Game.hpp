//
//  Game.hpp
//  Base_Defense
//
//  Created by Benjamin Scudder on 11/3/16.
//  Copyright © 2016 Scudder_Bruehlman. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include "Graphics.hpp"
#include "Input.hpp"
#include "Sprite.hpp"

class Graphics;

class Game {
public:
    Game();
    ~Game();

private:
    
    void gameLoop();
    void draw0Deg(Graphics &graphics);
    void draw30Deg(Graphics &graphics);
    void draw45Deg(Graphics &graphics);
    void draw60Deg(Graphics &graphics);
    void drawEnemy(Graphics &graphics);
    void update(Graphics &graphics, int turretPos);
    
    Sprite gunner0Deg;
    Sprite gunner30Deg;
    Sprite gunner45Deg;
    Sprite gunner60Deg;
    Sprite enemy;
    Sprite bullet;
    
    bool shooting;
    bool collision;
    int enemyX;
    int enemyY;
    const int dy = 1;
    const int bulletInitX = 35;
    const int bulletInitY = 454;
    int bulletX = bulletInitX;
    int bulletY = bulletInitY;
    const int dx0 = 3;
    const int dy0 = 0;
    const int dx30 = 3;
    const int dy30 = 1;
    const int dx45 = 2;
    const int dy45 = 2;
    const int dx60 = 1;
    const int dy60 = 3;
};

#endif /* Game_hpp */
