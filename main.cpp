#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include "SDL.h"
#include "include/table.hpp"
#include "include/ball.hpp"
#include "include/player.hpp"
#include "include/screen.hpp"





int main(){
    SDL_Event event;
    int turn = 0;
    int console_key;
    bool quit = false;
    screenClass * Screen = new screenClass();
    playerOne->init(100);
    playerTwo->init(540);
    Screen->init();
    SDL_Event events;    //The SDL event that we will poll to get events.
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(75);  
//initiate color function
    start_color();


    while(quit == false){
        SDL_Delay(40);
        console_key = getch();
        while (SDL_PollEvent(&events)){
            switch(events.type){
              case SDL_KEYDOWN:
                switch(events.key.keysym.sym){
                  case SDLK_LEFT:
                    break;
                  case SDLK_RIGHT:
                    break;
                  case SDLK_UP:
                    playerOne->pressUp(); 
                    break;
                  case SDLK_DOWN:
                    playerOne->pressDown(); 
                    break;
                  case SDLK_ESCAPE:
                      quit = true;
                      break;
                  default:
                    break;
                }
            }
        }
        turn++;
        switch(console_key){
            case KEY_UP:
                playerOne->pressUp(); 
                break;
            case KEY_DOWN:
                playerOne->pressDown(); 
                break;
            case 'q':
                quit = true;
                break;
            default:
                break;
        }
    }
//    std::this_thread::sleep_for(
//        std::chrono::seconds(2)
//    );
    endwin();
    return 0;
} 


