#include <string>
#include <cstdlib>

class ballClass{
   public:
     ballClass(){
         this->rect.x = 200;
         this->rect.y = 100;
         this->rect.h = 10;
         this->rect.w = 10;
     };
     void load (){
         this->rw = SDL_RWFromConstMem(this->svg.c_str(), this->svg.size());
         this->image = IMG_LoadTexture_RW(cache.render, this->rw, 1);
         SDL_QueryTexture(this->image, NULL, NULL, &this->rect.w, &this->rect.h);
     }
     void update(){
         if(hit == true){
             hit = false;
             return ;
         }
         position_x = position_x+speed_x;
         position_y = position_y+speed_y;
     };
     void collusion(bool x, bool y){
         if(x > -1){
             position_x = (position_x+(speed_x-x) * -1);
             speed_y * -1;
         }else{
             position_x = position_x+speed_x;
         }
         if(y > -1){
             position_y = (position_y+(speed_y-y) * -1);
             speed_y * -1;
         }else{
             position_y = position_y+speed_y;
         }
         hit = true;
     };
     SDL_Rect rect;
     SDL_Texture *image;
   private:
     const std::string svg =
       "<svg height='10' width='10'><filter id='blur'><feGaussianBlur stdDeviation='5' /></filter><circle cx='5' cy='5' r='4' stroke='white' stroke-width='1' fill='white' filter='url(#blur)' /></svg>";
     SDL_RWops *rw;
     int id;
     int position_x = 0;
     int position_y = 0;
     int speed_x = 0;
     int speed_y = 0;
     bool hit = false;
};

ballClass * ball = new ballClass();
