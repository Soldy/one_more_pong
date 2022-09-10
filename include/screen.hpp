
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
        this->render = SDL_CreateRenderer(
            this->window,
            -1,
            0
        );
        SDL_SetRenderDrawColor(
            this->render,
            0,
            0,
            0,
            SDL_ALPHA_OPAQUE
        );
        SDL_RenderClear(this->render);
        SDL_SetRenderDrawColor(
            this->render,
            255,
            255,
            255,
            255
        );

        this->player.x = 10;
        this->player.y = 10;
        this->player.h = 200;
        this->player.w = 20;
        /*
        SDL_RenderDrawRect(
            this->render,
            & this->player
        );
        */
        SDL_RenderFillRect(
            this->render,
            & playerOne->rect
        );
        SDL_RenderFillRect(
            this->render,
            & playerTwo->rect
        );
        SDL_RenderFillRect(
            this->render,
            & ball->rect
        );
        SDL_RenderPresent(this->render);
    };
    void close(){
        SDL_DestroyWindow( this->window );
    }
  private:
    SDL_Window *window;
    SDL_Surface *screen;
    SDL_Renderer * render;
    SDL_Rect player;
    int x_res = 640;
    int y_res = 480;
};
