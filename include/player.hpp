#include <string>
#include <cstdlib>

class playerClass{
   public:
     void update(){
         if(press_x == false && press_y == false ){
             return ;
         }
         position_x = position_x+speed_x;
         position_y = position_y+speed_y;
         if(0 > position_x){
              position_x =0;
         }
         if(0 > position_y){
              position_y =0;
         }
         position_x = table->overX(
             size_x,
             position_x
         );
         position_y = table->overY(
             size_y,
             position_y
         );
     };
     void pressX(bool plus){
        press_x = true;
        if(plus == true){
            speed_x = default_speed_x * 1;
            return;
        }
        speed_x = default_speed_x * -1;

     };
     void pressY(bool plus){
        press_y = true;
        if(plus == true){
            speed_y = default_speed_y * 1;
            return;
        }
        speed_y = default_speed_y * -1;
     };
     void relaseX(){
        speed_x = 0;
        press_x = false;
     };
     void relaseY(){
        speed_y = 0;
        press_y = false;
     };
   private:
     int id;
     std::string name;
     int position_x = 0;
     int position_y = 0;
     int default_speed_x = 10;
     int default_speed_y = 10;
     int speed_x = 0;
     int speed_y = 0;
     int size_x = 0;
     int size_y = 0;
     bool press_x = false;
     bool press_y = false;
};
playerClass * playerOne = new playerClass();
playerClass * playerTwo = new playerClass();
