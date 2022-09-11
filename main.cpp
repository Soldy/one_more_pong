#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "include/table.hpp"
#include "include/ball.hpp"
#include "include/player.hpp"
#include "include/screen.hpp"
#include "include/ncurses.hpp"


int turn = 0;


class sdlClass {
  public:
    bool quit = false;
    bool watch(){
        while (SDL_PollEvent(&this->events)){
            switch(this->events.type){
              case SDL_KEYDOWN:
                switch(this->events.key.keysym.sym){
                  case SDLK_LEFT:
                    return true;
                  case SDLK_RIGHT:
                    return true;
                  case SDLK_UP:
                    playerOne->pressUp(); 
                    return true;
                  case SDLK_DOWN:
                    playerOne->pressDown(); 
                    return true;
                  case SDLK_ESCAPE:
                    this->quit = true;
                    return true;
                  default:
                    return false;
                }
            }
        }
        return false;
    };
  private:
    SDL_Event events;

};



int main(){
    screenClass * Screen = new screenClass();
    ncursesClass * Ncurses = new ncursesClass();
    sdlClass * Sdl = new sdlClass();
    playerOne->init(100);
    playerTwo->init(540);
    Screen->init();
    while(true){
        SDL_Delay(40);
        if(Sdl->watch() == false)
            Ncurses->watch();
        if( Ncurses->quit == true || Sdl->quit == true ){
            delete Ncurses;
            delete Sdl;
            delete playerOne;
            delete playerTwo;
            delete Screen;
            return EXIT_SUCCESS;
        }
        turn++;
    }
    endwin();
    return EXIT_SUCCESS;
}


