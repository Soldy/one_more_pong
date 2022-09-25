#include <string>
#include <cstdlib>
#include <iostream>

class PlayerClass{
   public:
     void init(int x){
         this->d.position.x = x;
         this->d.position.y = 0;
         this->d.speed_default.y=5;
         this->d.size.x=10;
         this->d.size.y=50;
         this->rect.x = x;
         this->rect.y = this->d.position.y;
         this->rect.w = this->d.size.x;
         this->rect.h = this->d.size.y;
         this->d.max.y = 1080 - this->d.size.y;
     };
     void update(){
        if(this->pressed == false)
           return ;
        this->d.position.y = this->d.position.y + this->d.speed.y;
         if(0 > this->d.position.y)
            this->d.position.y = 0;
         else if(this->d.position.y > this->d.max.y)
            this->d.position.y = this->d.max.y;
         this->rect.y = this->d.position.y;
     };
     void pressUp(){
        this->pressed = true;
        this->d.speed.y=this->d.speed_default.y*-1;
     };
     void pressDown(){
        this->pressed = true;
        this->d.speed.y=this->d.speed_default.y*1;
     };
     void relase(){
        this->pressed=false;
     };
     void render(){
        SDL_RenderFillRect(
            cache.render,
            & this->rect
        );
     };
   private:
     bool pressed = false;
     SDL_Rect rect;
     std::string name;
     Dimension d;
};

struct {
    PlayerClass * one = new PlayerClass();
    PlayerClass * two = new PlayerClass();
} players ;
