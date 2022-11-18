#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include <SDL2/SDL.h>  
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "include/dimension.hpp"
#include "include/cache.hpp"
#include "include/table.hpp"
#include "include/ball.hpp"
#include "include/player.hpp"
#include "include/screen.hpp"
#include "include/sdlKey.hpp"
#include "include/gameloop.hpp"




int main(){
    GameClass * game = new GameClass();
    game->loop();
    delete screen;
    delete sdlKey;
    delete players.one;
    delete players.two;
    delete game;
    return EXIT_SUCCESS;
}


