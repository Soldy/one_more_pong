#include <cstdlib>
#include <iostream>

class PlayerClass{
   private:
     bool pressed = false;
     SDL_Rect rect;
     Dimension d;
     PointClass * point;
   public:
     void init(int x, int point_x){
         this->d.position.x = x;
         this->d.position.y = 0;
         this->d.speed_default.y=5;
         this->d.size.x=10;
         this->d.size.y=50;
         this->d.max.y = 1080 - this->d.size.y;
         this->point = new PointClass();
         this->point->init(point_x);
     };
     void update(){
        if(this->pressed == false)
           return ;
        this->d.position.y = this->d.position.y + this->d.speed.y;
         if(0 > this->d.position.y)
            this->d.position.y = 0;
         else if(this->d.position.y > this->d.max.y)
            this->d.position.y = this->d.max.y;
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
        this->d.speed.y=0;
     };
     void clear(){
        SDL_RenderFillRect(
            cache.render,
            & this->rect
        );
     };
     void render(){
        this->rect.x = result.x(this->d.position.x);
        this->rect.y = result.y(this->d.position.y);
        this->rect.w = result.x(this->d.size.x);
        this->rect.h = result.y(this->d.size.y);
        SDL_RenderFillRect(
            cache.render,
            & this->rect
        );
        this->point->render();
     };
     bool checkX(int last, int current){
         int left = this->d.size.x + this->d.position.x;
         if(
           (
              ( last > left )&&
              ( left > current )
            )||(
              ( this->d.position.x > last )&&
              ( current > this->d.position.x )
            )
         )
             return true;
         return false;
     }
     int checkY(int current){
         if(
           (current > this->d.position.y)&&
           (this->d.position.y+this->d.size.y > current)
        )
           return true;
        return false;
     }
     ~PlayerClass(){
     };
};

struct {
    PlayerClass * one = new PlayerClass();
    PlayerClass * two = new PlayerClass();
} players ;
