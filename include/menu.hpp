
class MenuClass{
  public:
    
    void init(){
        this->font = TTF_OpenFont("assets/F25_Bank_Printer.ttf", 24); 
        this->font_active = TTF_OpenFont("assets/F25_Bank_Printer_Bold.ttf", 24); 
    };
    void up(){
        this->active--;
        if(0 > this->active)
            this->active = (this->menus.size()-1);
    };
    void down(){
        this->active++;
        if(this->active > (this->menus.size()-1))
            this->active = 0;
    };
    int get(){
        return this->active;
    };
  private:
    TTF_Font* font; 
    TTF_Font* font_active; 
    SDL_Color White = {255, 255, 255};
    std::vector<SDL_Surface*> surfaces;
    std::vector<SDL_Texture*> texts;
    std::vector<SDL_Rect>rects;
    Dimension d;
    int active = 0;
    std::vector<std::string> menus = {
      "Single Player",
      "Exit"
    };
};
