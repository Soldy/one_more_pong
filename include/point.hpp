#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cstdlib>

class pointClass{
  public:
    void init(int x){ // do not change to constructor yet.
        this->Retrrg = TTF_OpenFont("assets/retrrg.ttf", 24); 
        this->d.position.x = x; 
        this->d.position.y = 20;
        this->d.size.x = 24;
        this->d.size.y = 24;
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
        this->rect.x = result.x(this->d.position.x); 
        this->rect.y = result.y(this->d.position.y); 
        this->rect.w = result.x(this->d.size.x); 
        this->rect.h = result.y(this->d.size.xy); 
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
    Dimension d;
};

