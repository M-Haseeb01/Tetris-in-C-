#pragma once
#include<iostream>
using namespace std;


class Tetris_Board
{

	int**  board;
	int score;
public:
	
	Tetris_Board() 
	{
	
		score = 0;
		board = new int* [18];
		for (int i = 0; i < 18; i++)
		{
			board[i] = new int[12];
			for (int j = 0; j < 12; j++)
			{
				if (i == 0 || i == 17 || j == 0 || j == 11) 
				{
					board[i][j] = 1;
				}
				else
				{
					board[i][j] = 0;
				}
			}
		}
	}
	
	void check_Row_filled()
	{
		bool row_Is_filled = false;
		for (int i = 1; i < 17; i++)
		{
			row_Is_filled = true;
			for (int j = 1; row_Is_filled==true && j < 11; j++)
			{
				if (board[i][j] != 1) 
				{
					row_Is_filled = false;
				}
			}
			if (row_Is_filled == true) 
			{
				for (int j = 1; j < 11; j++)
				{
					board[i][j] = 0;
				}
				score += 10;
				shift_Upper_side_down(i);
			}
		}
	}
	
	void shift_Upper_side_down(int x) 
	{
		
		for (int i = x; i > 1; i--)
		{
			for (int j = 1, k = i - 1; j < 11; j++)
			{
				board[i][j] = board[k][j];
			}
		}
	}

	
	int** get_Board() 
	{
		return board;
	}

	int get_Score() 
	{
		return score;
	}


	bool border_Collision(Peice& tetromine) 
	{
		Square* shape=tetromine.get_Boxes();
		for (int i = 0; i < 4; i++)
		{
			
			if (board[shape[i].get_x_index() + 1][shape[i].get_y_index()] == 1)
				return true;
		}
		return false;
	}
	
	void fill_Board(Peice& tetromine) 
	{
		Square* shape = tetromine.get_Boxes();
		for (int i = 0; i < 4; i++)
		{
			board[shape[i].get_x_index()][shape[i].get_y_index()] = 1;
		}
	}
	
	void rotation_Validity(Peice& tetromine)
	{
		Square* shape = tetromine.get_Boxes();
		bool overlap_Check = false;
		for (int i = 0; overlap_Check==false && i < 4; i++)
		{
			if (board[shape[i].get_x_index()][shape[i].get_y_index()] == 1) 
			{
				overlap_Check = true;
			}
		}
		if (overlap_Check == true) 
		{
			tetromine.rotate();
			overlap_Check = false;
			for (int i = 0; overlap_Check == false && i < 4; i++)
			{
				if (board[shape[i].get_x_index()][shape[i].get_y_index()] == 1)
				{
					overlap_Check = true;
				}
			}

			if (overlap_Check == true)
			{
				tetromine.rotate();
				overlap_Check = false;
				for (int i = 0; overlap_Check == false && i < 4; i++)
				{
					if (board[shape[i].get_x_index()][shape[i].get_y_index()] == 1)
					{
						overlap_Check = true;
					}
				}
				if (overlap_Check == true)
				{
					tetromine.rotate();
				}
			}
		}
	}
	
	bool check_Game_Over() 
	{
		if (board[1][4] || board[1][5]|| board[1][6])	{
	
			return true;
		}
		return false;
	}

	~Tetris_Board()
	{
		if (board != nullptr) 
		{
			for (int i = 0; i < 17; i++)
			{
				delete[] board[i];

			}
			delete[] board;
			board = nullptr;
		}
	}
};

