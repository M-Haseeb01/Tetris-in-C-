#pragma once
#include "Peice.h"

class Tetro_f :
    public Peice
{
    int rotation;
public:
    Tetro_f()
    {
        int x = 124, y = 31, x_ind = 1, y_ind = 4;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[1].set_x_pos(shape[0].get_x_pos());
        shape[1].set_y_pos(shape[0].get_y_pos() + 31);

        shape[1].set_x_index(shape[0].get_x_index() + 1);
        shape[1].set_y_index(shape[0].get_y_index());

        shape[2].set_x_pos(shape[1].get_x_pos() + 31);
        shape[2].set_y_pos(shape[1].get_y_pos());

        shape[2].set_x_index(shape[1].get_x_index());
        shape[2].set_y_index(shape[1].get_y_index() + 1);

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index() + 1);
      
        rotation = 0;
    }

    void rotate()
    {
        Square* shape = Peice::get_Boxes();
        if (rotation == 0)
        {
            shape[2].set_x_pos(shape[1].get_x_pos());
            shape[2].set_y_pos(shape[1].get_y_pos() + 31);

            shape[2].set_x_index(shape[1].get_x_index() + 1);
            shape[2].set_y_index(shape[1].get_y_index());

            shape[3].set_y_pos(shape[2].get_y_pos());
            shape[3].set_x_pos(shape[2].get_x_pos() - 31);

            shape[3].set_x_index(shape[2].get_x_index());
            shape[3].set_y_index(shape[2].get_y_index() - 1);

         
            rotation = 1;
        }
        else
        {
            if (rotation == 1)
            {

                shape[1].set_x_pos(shape[0].get_x_pos() + 31);
                shape[1].set_y_pos(shape[0].get_y_pos());

                shape[1].set_x_index(shape[0].get_x_index());
                shape[1].set_y_index(shape[0].get_y_index() + 1);

                shape[2].set_y_pos(shape[0].get_y_pos());
                shape[2].set_x_pos(shape[1].get_x_pos() + 31);

                shape[2].set_x_index(shape[1].get_x_index());
                shape[2].set_y_index(shape[1].get_y_index() + 1);

                shape[3].set_x_pos(shape[2].get_x_pos());
                shape[3].set_y_pos(shape[2].get_y_pos() + 31);

                shape[3].set_x_index(shape[2].get_x_index() + 1);
                shape[3].set_y_index(shape[2].get_y_index());
                
                rotation = 2;
            }
            else
            {
                if (rotation == 2)
                {

                    shape[3].set_x_pos(shape[0].get_x_pos());


                    shape[2].set_x_pos(shape[3].get_x_pos());
                    shape[2].set_y_pos(shape[3].get_y_pos() + 31);

                    shape[3].set_y_index(shape[0].get_y_index());
                    shape[2].set_x_index(shape[3].get_x_index() + 1);
                    shape[2].set_y_index(shape[3].get_y_index());

                   
                    rotation = 3;
                }
                else
                {

                    shape[1].set_x_pos(shape[3].get_x_pos());
                    shape[1].set_y_pos(shape[3].get_y_pos());

                    shape[1].set_x_index(shape[3].get_x_index());
                    shape[1].set_y_index(shape[3].get_y_index());

                    shape[2].set_x_pos(shape[1].get_x_pos() + 31);
                    shape[2].set_y_pos(shape[1].get_y_pos());

                    shape[2].set_x_index(shape[1].get_x_index());
                    shape[2].set_y_index(shape[1].get_y_index() + 1);

                    shape[3].set_x_pos(shape[2].get_x_pos() + 31);
                    shape[3].set_y_pos(shape[2].get_y_pos());

                    shape[3].set_x_index(shape[2].get_x_index());
                    shape[3].set_y_index(shape[2].get_y_index() + 1);
              
                    rotation = 0;
                }
            }
        }
    }
    void reset_Cordinates() 
    {
        int x = 124, y = 31, x_ind = 1, y_ind = 4;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[1].set_x_pos(shape[0].get_x_pos());
        shape[1].set_y_pos(shape[0].get_y_pos() + 31);

        shape[1].set_x_index(shape[0].get_x_index() + 1);
        shape[1].set_y_index(shape[0].get_y_index());

        shape[2].set_x_pos(shape[1].get_x_pos() + 31);
        shape[2].set_y_pos(shape[1].get_y_pos());

        shape[2].set_x_index(shape[1].get_x_index());
        shape[2].set_y_index(shape[1].get_y_index() + 1);

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index() + 1);
        

        rotation = 0;
    }

};

