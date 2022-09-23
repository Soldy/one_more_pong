
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
                    playerTwo->pressUp(); 
                    return true;
                  case SDLK_DOWN:
                    playerTwo->pressDown(); 
                    return true;
                  case SDLK_w:
                    playerOne->pressUp(); 
                    return true;
                  case SDLK_s:
                    playerOne->pressDown(); 
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
                    playerTwo->relase(); 
                    return true;
                  case SDLK_RIGHT:
                    playerTwo->relase(); 
                    return true;
                  case SDLK_UP:
                    playerTwo->relase(); 
                    return true;
                  case SDLK_DOWN:
                    playerTwo->relase(); 
                    return true;
                  case SDLK_w:
                    playerOne->relase(); 
                    return true;
                  case SDLK_s:
                    playerOne->relase(); 
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

