
class ScreenClass{
  public:
    void init(){
        SDL_Init(SDL_INIT_VIDEO);
        cache.window = SDL_CreateWindow(
           "pong",
           this->x_res,
           this->y_res,
           this->x_res,
           this->y_res,
           SDL_WINDOW_SHOWN
        );
        cache.render = SDL_CreateRenderer(
            cache.window,
            -1,
            0
        );
        SDL_SetRenderDrawColor(
            cache.render,
            0,
            0,
            0,
            SDL_ALPHA_OPAQUE
        );
        SDL_RenderClear(cache.render);
       ball->load();
    };
    void rendering(){
        SDL_SetRenderDrawColor(
            cache.render,
            0,
            0,
            0,
            SDL_ALPHA_OPAQUE
        );
        SDL_RenderClear(cache.render);
        SDL_RenderDrawRect(
            cache.render,
            & ball->rect
        );
        SDL_RenderCopy(
            cache.render,
            ball->image, 
            nullptr,
            &ball->rect
        );
        SDL_SetRenderDrawColor(
            cache.render,
            255,
            255,
            255,
            255
        );
        SDL_RenderFillRect(
            cache.render,
            & playerOne->rect
        );
        SDL_RenderFillRect(
            cache.render,
            & playerTwo->rect
        );

        SDL_RenderPresent(cache.render);
    };
    void close(){
        SDL_DestroyWindow( cache.window );
    }
  private:
    int x_res = 640;
    int y_res = 480;
};
ScreenClass * screen = new ScreenClass();
