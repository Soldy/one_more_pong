
class SdlKeyClass {
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
                    players.two->pressUp(); 
                    return true;
                  case SDLK_DOWN:
                    players.two->pressDown(); 
                    return true;
                  case SDLK_w:
                    players.one->pressUp(); 
                    return true;
                  case SDLK_s:
                    players.one->pressDown(); 
                    return true;

                  case SDLK_ESCAPE:
                    this->quit = true;
                    return true;
                  default:
                    return false;
                }
              case SDL_KEYUP:
                switch(this->events.key.keysym.sym){
                  case SDLK_LEFT:
                    players.two->relase(); 
                    return true;
                  case SDLK_RIGHT:
                    players.two->relase(); 
                    return true;
                  case SDLK_UP:
                    players.two->relase(); 
                    return true;
                  case SDLK_DOWN:
                    players.two->relase(); 
                    return true;
                  case SDLK_w:
                    players.one->relase(); 
                    return true;
                  case SDLK_s:
                    players.one->relase(); 
                    return true;
                }
            }
        }
        return false;
    };
  private:
    SDL_Event events;
};
SdlKeyClass * sdlKey = new SdlKeyClass();

