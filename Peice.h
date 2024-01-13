#pragma once
#include "Square.h"
class Peice
{
	Square* boxes;
public:
	Peice() 
	{
		boxes = new Square[4];
	}

	Square* get_Boxes() 
	{
		return boxes;
	}

	
	virtual void rotate() 
	{
	
	}
	
	virtual void reset_Cordinates()
	{
	
	}


	
	void move_Left(int ** board) 
	{
		bool collision_Check = false;
		
		for (int i = 0; i < 4 && collision_Check==false; i++)
		{
			if (board[boxes[i].get_x_index()][boxes[i].get_y_index() - 1] == 1) 
			{
				collision_Check = true;
			}	
		}
		if (collision_Check == false)
		{
			for (int i = 0; i < 4; i++)
			{
				boxes[i].set_x_pos(boxes[i].get_x_pos() - 31);
				boxes[i].set_y_index(boxes[i].get_y_index() - 1);
			}
		}
	}
	void move_Right(int** board)
	{
		bool collision_Check = false;
		for (int i = 0; i < 4 && collision_Check == false; i++)
		{
			if (board[boxes[i].get_x_index()][boxes[i].get_y_index() + 1] == 1)
			{
				collision_Check = true;
			}
		}

		if (collision_Check == false)
		{
			for (int i = 0; i < 4; i++)
			{
				boxes[i].set_x_pos(boxes[i].get_x_pos() + 31);
				boxes[i].set_y_index(boxes[i].get_y_index() + 1);
			}
		}
	}
	void move_Down()
	{
		
		for (int i = 0; i < 4; i++)
		{
			boxes[i].set_y_pos(boxes[i].get_y_pos() + 31);
			boxes[i].set_x_index(boxes[i].get_x_index() + 1);
		}
	} 


	void operator =(Peice& obj) 
	{
		for (int i = 0; i < 4; i++)
		{
			boxes[i] = obj.boxes[i];
		}
	}
	
	~Peice() 
	{
		if (boxes != nullptr)
			delete[] boxes;
	}
};

