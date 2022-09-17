#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "SDL_image.h"
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
    delete playerOne;
    delete playerTwo;
    delete game;
    return EXIT_SUCCESS;
}


