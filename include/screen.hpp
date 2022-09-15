
class ScreenClass{
  public:
    void init(
        PlayerClass * one,
        PlayerClass * two
    ){
        this->playerOne = one;
        this->playerTwo = two;
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
    };
    void rendering(){
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
    PlayerClass * playerOne;
    PlayerClass * playerTwo;
    int x_res = 640;
    int y_res = 480;
};
