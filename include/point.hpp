#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cstdlib>

class PointClass{
  public:
    void init(int x){ // do not change to constructor yet.
        this->Retrrg = TTF_OpenFont("assets/retrrg.ttf", 24); 
        this->d.position.y = 20;
        this->d.size.x = 24;
        this->d.size.y = 24;
        this->d.position.x = x - ( this->d.size.x /2 ); 
    };
    void clear(){
        SDL_FreeSurface(this->surfaceMessage);
        SDL_DestroyTexture(this->Message);
    };
    void reset(){
        this->point = 0;
    };
    void set(int p){
        this->point = p;
    };
    void add(int p){
        this->point = this->point + p;
    };
    int get(){
        return this->point;
    };
    void render(){
        this->update();
        this->rect.x = result.x(this->d.position.x); 
        this->rect.y = result.y(this->d.position.y); 
        this->rect.w = result.x(this->d.size.x); 
        this->rect.h = result.y(this->d.size.y); 
        if (this->Retrrg == NULL) {
            std::cout << TTF_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }
        this->surfaceMessage = TTF_RenderText_Solid(
            this->Retrrg,
            this->stm.str().c_str(),
            this->White
        );
        this->Message = SDL_CreateTextureFromSurface(
            cache.render,
            this->surfaceMessage
        );

        SDL_RenderCopy(
            cache.render, 
            this->Message,
            nullptr, 
            &this->rect
        );

    };
  private:
    TTF_Font* Retrrg ; 
    SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceMessage;
    SDL_Texture* Message;
    SDL_Rect rect;
    Dimension d;
    int point = 0;
    char* point_char;
    std::stringstream stm;
    void update(){
      this->stm << this->point;
   }
};


