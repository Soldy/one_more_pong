#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cstdlib>

class pointClass{
  public:
    void init(int x){ // do not change to constructor yet.
        this->Retrrg = TTF_OpenFont("assets/retrrg.ttf", 24); 
        this->rect.x = x; 
        this->rect.y = 20;
        this->rect.w = 24;
        this->rect.h = 24;
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
        if (this->Retrrg == NULL) {
            std::cout << TTF_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }
        this->surfaceMessage = TTF_RenderText_Solid(
            this->Retrrg,
            "0",
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
    int point;
};


