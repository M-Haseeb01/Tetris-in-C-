#pragma once
#include "Peice.h"
#include"Square.h"


class Tetro_b : public Peice
{
    int rotation;
public:
    Tetro_b() 
    {
        rotation = 0;
        int x = 124, y = 31;

        Square* shape = Peice::get_Boxes();
       
        shape[0].set_x_pos(x);
        shape[2].set_x_pos(x);

        shape[0].set_x_index(1);
        shape[2].set_x_index(2);


        x += 31;
        shape[1].set_x_pos(x);
        shape[3].set_x_pos(x);

        shape[1].set_x_index(1);
        shape[3].set_x_index(2);

        shape[0].set_y_pos(y);
        shape[1].set_y_pos(y);

        shape[0].set_y_index(4);
        shape[1].set_y_index(5);


        y += 31;

        shape[2].set_y_pos(y);
        shape[3].set_y_pos(y);

        shape[2].set_y_index(4);
        shape[3].set_y_index(5);
    }

    void rotate() 
    {
    //No rotation
    }

    void reset_Cordinates() 
    {

        {
            rotation = 0;
            int x = 124, y = 31;

            Square* shape = Peice::get_Boxes();
            
            shape[0].set_x_pos(x);
            shape[2].set_x_pos(x);

            shape[0].set_x_index(1);
            shape[2].set_x_index(2);


            x += 31;
            shape[1].set_x_pos(x);
            shape[3].set_x_pos(x);

            shape[1].set_x_index(1);
            shape[3].set_x_index(2);

            shape[0].set_y_pos(y);
            shape[1].set_y_pos(y);

            shape[0].set_y_index(4);
            shape[1].set_y_index(5);


            y += 31;

            shape[2].set_y_pos(y);
            shape[3].set_y_pos(y);

            shape[2].set_y_index(4);
            shape[3].set_y_index(5);
        }
    
    }

};

