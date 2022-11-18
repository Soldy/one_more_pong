#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cstdlib>

class ballClass{
   public:
     ballClass(){
         this->d.position.x =200;
         this->d.position.y =100;
         this->rect.h = 10;
         this->rect.w = 10;
     };
     int getX(){
         return result.x(this->d.position.x);
     }
     int getY(){
         return result.y(this->d.position.y);
     }
     void start (){
         this->d.speed.x = 5-(10*(rand()%2));
     }
     void load (){
         this->rw = SDL_RWFromConstMem(this->svg.c_str(), this->svg.size());
         this->image = IMG_LoadTexture_RW(cache.render, this->rw, 1);
         SDL_QueryTexture(this->image, NULL, NULL, &this->rect.w, &this->rect.h);
     }
     void update(){
         this->d.position.x = (
           this->d.position.x+this->d.speed.x
         );
         this->d.position.y = (
           this->d.position.y+this->d.speed.y
         );
     };
     void collusion(bool x, bool y){
         if(x > -1){
             this->d.position.x = (this->d.position.x+(this->d.speed.x-x) * -1);
             this->d.speed.y *= -1;
         }else{
             this->d.position.x = this->d.position.x+this->d.speed.x;
         }
         if(y > -1){
             this->d.position.y = (this->d.position.y+(this->d.speed.y-y) * -1);
             this->d.speed.y * -1;
         }else{
             this->d.position.y = this->d.position.y+this->d.speed.y;
         }
         this->hit = true;
     };
     void render(){
        this->rect.x = this->getX();
        this->rect.y = this->getY();
        SDL_RenderDrawRect(
            cache.render,
            & this->rect
        );
        SDL_RenderCopy(
            cache.render,
            this->image, 
            nullptr,
            &this->rect
        );
     };
     SDL_Rect rect;
     SDL_Texture *image;
   private:
     const std::string svg =
       "<svg height='10' width='10'><filter id='blur'><feGaussianBlur stdDeviation='5' /></filter><circle cx='5' cy='5' r='4' stroke='white' stroke-width='1' fill='white' filter='url(#blur)' /></svg>";
     SDL_RWops *rw;
     int id;
     bool hit = false;
     Dimension d;
};

ballClass * ball = new ballClass();
