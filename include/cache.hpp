struct {
    SDL_Renderer * render;
    SDL_Window *window;
    bool full_screen;
    struct {
        int x = 1920;
        int y = 1080;
    } result;
} cache;
