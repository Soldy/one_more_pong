
class GameClass {
  public:
    GameClass(){
        TTF_Init();
        SDL_Init(SDL_INIT_VIDEO);
        players.one->init(100, 480);
        players.two->init(1820, 1540);
        screen->init();
    };
    ~GameClass(){};
    void loop(){
        int last;
        screen->rendering();
        while(this->run){
            last = ball->getX();
            SDL_Delay(5);
            sdlKey->watch();
            if(sdlKey->quit == true )
                this->run = false;
            this->turn++;
            ball->update();
            players.one->update();
            players.two->update();
            players.one->checkX(last, ball->getX());
            screen->rendering();
        }
    };
  protected:
    int turn = 0;
    bool run = true;
};
