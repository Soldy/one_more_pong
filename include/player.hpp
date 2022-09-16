#include <string>
#include <cstdlib>

class PlayerClass{
   public:
     void init(int x){
         this->position_x = x;
         this->rect.x = x;
         this->rect.y = this->position_y;
         this->rect.h = 100;
         this->rect.w = 20;

     };
     void update(){
        if(1 > this->round)
           return ;
        this->round--;
        this->position_y = this->position_y + this->speed;
         if(0 > this->position_y)
            this->position_y = 0;
         if(this->position_y > 400)
            this->position_y = 400;
         this->rect.y = this->position_y;
     };
     void pressUp(){
        this->round=100;
        this->speed=this->default_speed*-1;
     };
     void pressDown(){
        this->round=100;
        this->speed=this->default_speed*1;
     };
     void relase(){
        this->round=0;
     }
     SDL_Rect rect;
   private:
     int id;
     int round = 0;
     std::string name;
     int position_x = 0;
     int position_y = 0;
     int default_speed = 1;
     int speed = 1;
     int size_x = 20;
     int size_y = 100;

};
PlayerClass * playerOne = new PlayerClass();
PlayerClass * playerTwo = new PlayerClass();
