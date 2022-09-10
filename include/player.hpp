#include <string>
#include <cstdlib>

class playerClass{
   public:
     void init(int x){
         this->rect.x = x;
         this->rect.y = 100;
         this->rect.h = 100;
         this->rect.w = 20;

     };
     void update(){
     };
     void pressUp(){
        this->position_x = this->position_x - this->speed;
        if(0 > this->position_x)
            this->position_x;
     };
     void pressDown(){
        this->position_x = this->position_x + this->speed;
        if(0 > this->position_x)
            this->position_x;
     };
     SDL_Rect rect;
   private:
     int id;
     std::string name;
     int position_x = 0;
     int position_y = 0;
     int default_speed = 10;
     int speed = 0;
     int size_x = 0;
     int size_y = 0;
};
playerClass * playerOne = new playerClass();
playerClass * playerTwo = new playerClass();
