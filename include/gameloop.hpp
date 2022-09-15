
class GameClass {
  public:
    GameClass(){
        this->playerOne->init(100);
        this->playerTwo->init(540);
        this->screen->init(
            this->playerOne,
            this->playerTwo
        );
        this->sdlKey->init(
            this->playerOne,
            this->playerTwo
        );
        this->ncurses->init(
            this->playerOne,
            this->playerTwo
        );
    };
    ~GameClass(){
         delete this->screen;
         delete this->ncurses;
         delete this->sdlKey;
         delete this->playerOne;
         delete this->playerTwo;
    };
    void loop(){
        while(this->run){
            SDL_Delay(40);
             if(this->sdlKey->watch() == false)
                 this->ncurses->watch();
             if(this->ncurses->quit == true || this->sdlKey->quit == true ){
                 this->run = false;
             }
             this->turn++;
             this->screen->rendering();
        }
    };
    PlayerClass * playerOne = new PlayerClass();
    PlayerClass * playerTwo = new PlayerClass();
    ScreenClass * screen = new ScreenClass();
    NcursesClass * ncurses = new NcursesClass();
    SdlKeyClass * sdlKey = new SdlKeyClass();
  protected:
    int turn = 0;
    bool run = true;
};
