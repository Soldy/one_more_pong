
class GameClass {
  public:
    GameClass(){
        players.one->init(100);
        players.two->init(1820);
        screen->init();
    };
    ~GameClass(){};
    void loop(){
        screen->rendering();
        while(this->run){
            SDL_Delay(5);
            sdlKey->watch();
            if(sdlKey->quit == true )
                this->run = false;
            this->turn++;
            players.one->update();
            players.two->update();
            screen->rendering();
        }
    };
  protected:
    int turn = 0;
    bool run = true;
};
