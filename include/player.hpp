#include <string>
#include <cstdlib>

class PlayerClass{
   public:
     void init(int x){
         this->position.x = x;
         this->rect.x = x;
         this->rect.y = this->position.y;
         this->rect.w = this->size.x;
         this->rect.h = this->size.y;
         this->max.y = cache.result.y - this->size.y;
     };
     void update(){
        if(1 > this->round)
           return ;
        this->round--;
        this->position.y = this->position.y + this->speed.y;
         if(0 > this->position.y)
            this->position.y = 0;
         if(this->position.y > this->max.y)
            this->position.y = this->max.y;
         this->rect.y = this->position.y;
     };
     void pressUp(){
        this->round=1000;
        this->speed.y=this->default_speed.y*-1;
     };
     void pressDown(){
        this->round=1000;
        this->speed.y=this->default_speed.y*1;
     };
     void relase(){
        this->round=0;
     }
     SDL_Rect rect;
   private:
     int id;
     int round = 0;
     std::string name;
     struct { 
         int x = 1;
         int y = 1;
     } position ;
     struct { 
         int x = 10;
         int y = 10;
     } default_speed ;
     struct { 
         int x = 5;
         int y = 5;
     } speed ;
     struct {
         int x = 10;
         int y = 80;
     } size;
     struct {
         int x = 400;
         int y = 400;
    } max;

};
PlayerClass * playerOne = new PlayerClass();
PlayerClass * playerTwo = new PlayerClass();
