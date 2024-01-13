#pragma once
#include"Peice.h"
#include"Square.h"


class Tetro_a :public Peice {

	int rotaions;
public:
	Tetro_a() {
		int x = 124, y = 31;
		Square* shape = Peice::get_Boxes();
	
		for (int i = 0,y_ind=4; i < 4; i++,y_ind++){
			shape[i].set_x_pos(x);
			shape[i].set_y_pos(y);
			
			shape[i].set_x_index(1);
			shape[i].set_y_index(y_ind);
			
			x += 31;
		}
		rotaions = 0;
	}
	
	void rotate() 
	{
		
		Square* shape = Peice::get_Boxes();
		
		if (rotaions == 0) 
		{
			for (int i = 1; i < 4; i++)
			{
				shape[i].set_x_pos(shape[i-1].get_x_pos());
				shape[i].set_y_pos(shape[i - 1].get_y_pos() + 31);
				
				shape[i].set_y_index(shape[i - 1].get_y_index());
				shape[i].set_x_index(shape[i-1].get_x_index()+1);
			}
			rotaions = 1;

		}
		else
		{
		
			for (int i = 1; i < 4; i++)
			{
				shape[i].set_x_pos(shape[i-1].get_x_pos() + 31);
				shape[i].set_y_pos(shape[i - 1].get_y_pos());

				shape[i].set_x_index(shape[i - 1].get_x_index());
				shape[i].set_y_index(shape[i - 1].get_y_index() + 1);
			}
			rotaions = 0;

		}
	}

	void reset_Cordinates() 
	{
		
		{
			int x = 124, y = 31;
			Square* shape = Peice::get_Boxes();

			for (int i = 0, y_ind = 4; i < 4; i++, y_ind++)
			{
				shape[i].set_x_pos(x);
				shape[i].set_y_pos(y);

				shape[i].set_x_index(1);
				shape[i].set_y_index(y_ind);

				x += 31;
			}
			rotaions = 0;
		}
	}

};

