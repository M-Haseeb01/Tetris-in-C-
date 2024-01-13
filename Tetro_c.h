#pragma once
#include"Square.h"
#include "Peice.h"


class Tetro_c :
    public Peice
{
    int rotation;
public:
    Tetro_c() 
    {
        
       
        rotation = 0;
        int x = 124, y = 31;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(1);
        shape[0].set_y_index(4);

        shape[1].set_x_pos(shape[0].get_x_pos() + y);
        shape[1].set_y_pos(shape[0].get_y_pos());

        shape[1].set_x_index(1);
        shape[1].set_y_index(5);

        shape[2].set_y_pos(shape[0].get_y_pos() + y);
        shape[2].set_x_pos(shape[0].get_x_pos() - y);

        shape[2].set_y_index(shape[0].get_y_index() - 1);
        shape[2].set_x_index(shape[0].get_x_index() + 1);

        shape[3].set_x_pos(shape[0].get_x_pos());
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(2);
        shape[3].set_y_index(4);
 
    }
   
    void rotate() 
    {
        Square* shape = Peice::get_Boxes();
        if (rotation == 0) 
        {
 
            shape[0].set_y_pos(shape[3].get_y_pos() + 31);
            shape[1].set_x_pos(shape[2].get_x_pos());

            shape[0].set_x_index(shape[3].get_x_index() + 1);
            shape[1].set_y_index(shape[2].get_y_index());
           
            rotation = 1;
        }
        else
        {

            shape[0].set_y_pos(shape[3].get_y_pos() - 31);
            shape[1].set_x_pos(shape[0].get_x_pos()+31);


            shape[0].set_x_index(shape[3].get_x_index() -1);
            shape[1].set_y_index(shape[0].get_y_index()+1);
     
            
            rotation = 0;
        }
    }
    
    void reset_Cordinates() 
    {
      
        rotation = 0;
        int x = 124, y = 31;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(1);
        shape[0].set_y_index(4);

        shape[1].set_x_pos(shape[0].get_x_pos() + y);
        shape[1].set_y_pos(shape[0].get_y_pos());

        shape[1].set_x_index(1);
        shape[1].set_y_index(5);

        shape[2].set_y_pos(shape[0].get_y_pos() + y);
        shape[2].set_x_pos(shape[0].get_x_pos() - y);

        shape[2].set_y_index(shape[0].get_y_index() - 1);
        shape[2].set_x_index(shape[0].get_x_index() + 1);

        shape[3].set_x_pos(shape[0].get_x_pos());
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(2);
        shape[3].set_y_index(4);
    }

};

