#include <string>
#include <cstdlib>

class PlayerClass{
   public:
     void init(int x){
         this->d.position.x = x;
         this->d.speed_default.y=5;
         this->rect.x = x;
         this->rect.y = this->d.position.y;
         this->rect.w = this->d.size.x;
         this->rect.h = this->d.size.y;
         this->d.max.y = cache.result.y - this->d.size.y;
     };
     void update(){
        if(1 > this->round)
           return ;
        this->round--;
        this->d.position.y = this->d.position.y + this->d.speed.y;
         if(0 > this->d.position.y)
            this->d.position.y = 0;
         if(this->d.position.y > this->d.max.y)
            this->d.position.y = this->d.max.y;
         this->rect.y = this->d.position.y;
     };
     void pressUp(){
        this->round=1000;
        this->d.speed.y=this->d.speed_default.y*-1;
     };
     void pressDown(){
        this->round=1000;
        this->d.speed.y=this->d.speed_default.y*1;
     };
     void relase(){
        this->round=0;
     }
     SDL_Rect rect;
   private:
     int id;
     int round = 0;
     std::string name;
     Dimension d;
};
PlayerClass * playerOne = new PlayerClass();
PlayerClass * playerTwo = new PlayerClass();
