
class GameClass {
  public:
    GameClass(){
        playerOne->init(100);
        playerTwo->init(1820);
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
            playerOne->update();
            playerTwo->update();
            screen->rendering();
        }
    };
  protected:
    int turn = 0;
    bool run = true;
};
