class ScreenClass{
  public:
    void init(){
        cache.result.x=1920;
        cache.result.y=1080;
        SDL_Init(SDL_INIT_VIDEO);
        this->checkSize();
        this->createWindow();
        this->createRender();
        ball->load();
    };
    void rendering(){
        this->setBlack();
        SDL_RenderClear(cache.render);
        ball->render();
        SDL_SetRenderDrawColor(
            cache.render,
            255,
            255,
            255,
            255
        );
        players.one->render();
        players.two->render();
        SDL_RenderPresent(cache.render);
    };
    void close(){
        SDL_DestroyWindow( cache.window );
    }
  private:
    void checkSize(){
        SDL_GetCurrentDisplayMode(
            0, 
            & cache.display_mode
        );
    };
    void createWindow(){
        cache.window = SDL_CreateWindow(
           "pong",
           cache.result.x,
           cache.result.y,
           cache.result.x,
           cache.result.y,
           SDL_WINDOW_SHOWN
        );
        cache.full_screen = false;
        SDL_SetWindowFullscreen(
            cache.window, 
            !cache.full_screen
        );
        SDL_ShowCursor(cache.full_screen);
    };
    void createRender(){
        cache.render = SDL_CreateRenderer(
            cache.window,
            -1,
            0
        );
        this->setBlack();
        SDL_RenderClear(cache.render);
    };
    void setBlack(){
        SDL_SetRenderDrawColor(
            cache.render,
            0,
            0,
            0,
            SDL_ALPHA_OPAQUE
        );
    }
};
ScreenClass * screen = new ScreenClass();
