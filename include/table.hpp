#include <string>
#include <cstdlib>


class tableClass{
  public:
    bool overX(int size, int position){
        if((size+position)>size_x){
            return true;
        }
        return false;
    }
    bool overY(int size, int position){
        if((size+position)>size_y){
            return true;
        }
        return false;
    }
    int positionX(int size, int position){
        if(size_x > (size+position)){
            return position;
        }
        return size_x - size;
    }
    int positionY(int size, int position){
        if(size_y > (size+position)){
            return position;
        }
        return size_y - size;
    }
    int sizeX(){
        return size_x*1;
    }
    int sizeY(){
        return size_y*1;
    }
  private:
    int size_x = 1920; 
    int size_y = 1080; 

}
