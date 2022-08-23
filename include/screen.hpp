#include <SDL2/sdl.h>

class screenClass{
  public:
    void init(){
        SDL_Init(SDL_INIT_VIDEO);
        this->window = SDL_CreateWindow(
           "pong",
           this->x_res,
           this->y_res,
           this->x_res,
           this->y_res,
           SDL_WINDOW_SHOWN
        );
        this->screen = SDL_GetWindowSurface( this->window );
        SDL_FillRect(
            this->screen,
            NULL,
            SDL_MapRGB(
                this->screen->format, 0xFF, 0xFF, 0xFF 
            ) 
        );
        SDL_UpdateWindowSurface( this->window );
    };
    void close(){
        SDL_DestroyWindow( this->window );
    }
  private:
    SDL_Window *window;
    SDL_Surface *screen;
    int x_res = 640;
    int y_res = 480;
};
