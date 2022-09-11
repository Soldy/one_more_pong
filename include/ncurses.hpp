#include <ncurses.h>

class ncursesClass{
  public:
    ncursesClass(){
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        timeout(75);  
        start_color();
    };
    ~ncursesClass(){
        endwin();
    };
    bool quit = false;
    bool watch(){
        this->key = getch();
        switch(this->key){
            case KEY_UP:
                playerOne->pressUp(); 
                return true;
            case KEY_DOWN:
                playerOne->pressDown(); 
                return true;
            case 'q':
                this->quit = true;
                return true;
            default:
                return false;
        }
    };
  private:
    int key;
};

