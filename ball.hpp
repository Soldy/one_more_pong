#include <string>
#include <cstdlib>

class ballClass{
   public:
     void update(){
         if(hit == true){
             hit = false;
             return ;
         }
         position_x = position_x+speed_x;
         position_y = position_y+speed_y;
     }
     bool collusion((bool x, bool y){
         if(x > -1){
             position_x = (position_x+(speed_x-x) * -1)*;
             speed_y * -1;
         }else{
             position_x = position_x+speed_x;
         }
         if(y > -1){
             position_y = (position_y+(speed_y-y) * -1)*;
             speed_y * -1;
         }else{
             position_y = position_y+speed_y;
         }
         hit = true;
     }
   private:
     int id;
     int position_x = 0;
     int position_y = 0;
     int speed_x = 0;
     int speed_y = 0;
     bool hit = false;
}

