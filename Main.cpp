#include<SFML/Graphics.hpp>

#include"Tetro_a.h"
#include"Tetro_b.h"
#include"Tetro_c.h"
#include"Tetro_d.h"
#include"Tetro_e.h"
#include"Tetro_f.h"
#include"Tetro_g.h"
#include"Peice.h"

#include"Tetris_Board.h"

#include<cstdlib>
#include <string>/
#include<ctime>  
#include<Windows.h>
#include<iostream>
using namespace std;


void load_Peices(Peice**& list_Of_Peices) 
{
	list_Of_Peices = new Peice * [7];
	
	list_Of_Peices[0] = new Tetro_a;
	list_Of_Peices[1] = new Tetro_b;
	list_Of_Peices[2] = new Tetro_c;
	list_Of_Peices[3] = new Tetro_d;
	list_Of_Peices[4] = new Tetro_e;
	list_Of_Peices[5] = new Tetro_f;
	list_Of_Peices[6] = new Tetro_g;
}

void select_Random_Peice(int& peice_num) 
{
	srand((unsigned)time(0));
	//built-in by cstdlib
	peice_num = rand() % 7;
}



void display_Starting() 
{
	sf::RenderWindow window1(sf::VideoMode(695, 475), "Welcome_To_Tetris"); 
	sf::Texture logotexture;
	logotexture.loadFromFile("game logo.png");  
	sf::Sprite logo(logotexture);
	logo.setPosition(0, 0);
	window1.draw(logo);
	window1.display();
	Sleep(3000);
	window1.close();

}
void display_Ending() 
{
	sf::Texture logotexture_end;
	logotexture_end.loadFromFile("end game logo.png");   
	sf::Sprite logo_end(logotexture_end);
	logo_end.setPosition(0, 0);
	sf::RenderWindow win(sf::VideoMode(630, 395), "Ending_Tetris ");  
	win.draw(logo_end);
	win.display();
	Sleep(2500);
	win.close();
}

int main()
{

	
	Tetris_Board Game;
	
	Peice** list_Of_Tetromines;
	Peice next_shape;

	

	int tetromine_Number = 0;
	int next_Tetromine_Number = 0;
	int score = Game.get_Score();
	int m = 0;
	int s = 0;//This will s
	int execution_Speed = 0;
	int execution_Limiter = 5;
	int** board = Game.get_Board();

	

	bool Peice_selected = true;

	
	
	sf::Clock clock;
	sf::Time time; 

	
	sf::Text seconds;
	sf::Text sec;  
	sf::Text minutes;
	sf::Text min;    



	display_Starting();



	load_Peices(list_Of_Tetromines);
	select_Random_Peice(tetromine_Number);
	select_Random_Peice(next_Tetromine_Number);
	next_shape = *list_Of_Tetromines[next_Tetromine_Number];
	


	sf::RenderWindow window(sf::VideoMode(800, 560), "TETRIS_GAME");   
	//window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) ]
			if (event.type == sf::Event::Closed)
				window.close();
		if (Peice_selected == false) 
			tetromine_Number = next_Tetromine_Number;
			
			select_Random_Peice(next_Tetromine_Number);
			next_shape = *list_Of_Tetromines[next_Tetromine_Number];
			Peice_selected = true;
		}

		
		sf::RectangleShape board_graph[18][12];
	
		int x_position = 0;
		int y_position = 0;
		for (int i = 0; i < 18; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				
				if (board[i][j] == 1) 
				{
					board_graph[i][j].setSize(sf::Vector2f(30, 30));
					board_graph[i][j].setPosition(x_position, y_position);
					board_graph[i][j].setFillColor(sf::Color::Magenta);
					window.draw(board_graph[i][j]);
				}
				x_position += 31;
			}
			x_position = 0;
			y_position += 31;
		}
			
			Square* shape_Squares = list_Of_Tetromines[tetromine_Number]->get_Boxes();
			
			sf::RectangleShape shape[4];
			for (int i = 0; i < 4; i++)
			{
				shape[i].setSize(sf::Vector2f(30, 30));
				shape[i].setPosition(shape_Squares[i].get_x_pos(), shape_Squares[i].get_y_pos());
				shape[i].setFillColor(sf::Color::Green);
				window.draw(shape[i]);
			}

			
			sf::RectangleShape next_Shape_Graphics[4];
			Square* next_shape_Squares = next_shape.get_Boxes();
			for (int i = 0; i < 4; i++)
			{
				next_Shape_Graphics[i].setSize(sf::Vector2f(30, 30));
				next_Shape_Graphics[i].setPosition(next_shape_Squares[i].get_x_pos() + 420, next_shape_Squares[i].get_y_pos()+450);
				next_Shape_Graphics[i].setFillColor(sf::Color::Green);
				window.draw(next_Shape_Graphics[i]);
			}


			sf::Font font;
			if (font.loadFromFile("fresh.ttf")) {
											 
				sf::Text head;
				head.setFont(font);
				head.setString("Tetris_GamePlay");
				head.setStyle(sf::Text::Italic | sf::Text::StrikeThrough);
				head.setFillColor(sf::Color::Red);
				head.setCharacterSize(65);
				head.setPosition(400, 0);
				window.draw(head);
										
				sf::Text text;
				sf::Text score; 
				text.setFont(font);
				text.setString("Score");
				text.setCharacterSize(50);
				text.setStyle(sf::Text::Underlined);
				text.setFillColor(sf::Color::Red);
				text.setPosition(520, 60);
				window.draw(text);

				
				score.setFont(font);
				score.setString(std::to_string(Game.get_Score()));
				score.setCharacterSize(50);
				score.setFillColor(sf::Color::Yellow);
				score.setPosition(550, 110);
				window.draw(score);



			
				seconds.setFont(font);
				seconds.setCharacterSize(50);
				seconds.setFillColor(sf::Color::Yellow);
				seconds.setPosition(500, 340);
				
				sec.setFont(font);
				sec.setString("Seconds");
				sec.setCharacterSize(50);
				sec.setStyle(sf::Text::Underlined);
				sec.setFillColor(sf::Color::Red);
				sec.setPosition(500, 280);
				
				minutes.setFont(font);
				minutes.setCharacterSize(50);
				minutes.setFillColor(sf::Color::Yellow);
				minutes.setPosition(550, 220);
				
				min.setFont(font);
				min.setString("Minutes");
				min.setCharacterSize(50);
				min.setFillColor(sf::Color::Red);
				min.setStyle(sf::Text::Underlined);
				min.setPosition(500, 170);
				
				time = clock.getElapsedTime();
				s = time.asSeconds();
				seconds.setString(std::to_string(time.asSeconds()));

				if (s == 60)
				{
					m++;
					clock.restart();
				}
				minutes.setString(std::to_string(m));
				window.draw(minutes);
				window.draw(seconds);
				window.draw(sec);
				window.draw(min);

				sf::Text text1;
				text1.setFont(font);
				text1.setString("Next_shape");
				text1.setStyle(sf::Text::Underlined);
				text1.setFillColor(sf::Color::Red);
				text1.setCharacterSize(50);
				text1.setPosition(next_shape_Squares[0].get_x_pos() + 370, next_shape_Squares[0].get_y_pos() + 370);
				window.draw(text1);
			}


				   if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				   {
				list_Of_Tetromines[tetromine_Number]->move_Left(board);
				   }
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
				   {
					list_Of_Tetromines[tetromine_Number]->move_Right(board);
				   }
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						list_Of_Tetromines[tetromine_Number]->move_Down();
					}
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
						{
							list_Of_Tetromines[tetromine_Number]->rotate();
							Game.rotation_Validity(*list_Of_Tetromines[tetromine_Number]);
						
						}
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
				   {
					   window.close();
					   break;
				   }
	
					
 
			
			if (!Game.border_Collision(*list_Of_Tetromines[tetromine_Number]) && execution_Speed==execution_Limiter)
			{
				list_Of_Tetromines[tetromine_Number]->move_Down();
				execution_Speed = 0;
			}
			if (Game.border_Collision(*list_Of_Tetromines[tetromine_Number])) {
				
				Peice_selected = false;
				execution_Speed = 0;	Game.fill_Board(*list_Of_Tetromines[tetromine_Number]);
				list_Of_Tetromines[tetromine_Number]->reset_Cordinates();
			
				Game.check_Row_filled();
			}
			if (Game.check_Game_Over()) {
			
				sf::Font font;
				font.loadFromFile("fresh.ttf");
				sf::Text text;
				text.setFont(font);
				text.setString("Game_Over");
				text.setStyle(sf::Text::Italic | sf::Text::StrikeThrough | sf::Text::Underlined);
				text.setFillColor(sf::Color::Yellow);
				text.setCharacterSize(80);
				text.setLetterSpacing(2);
				text.setPosition(1, 212);
				window.draw(text);
				window.display();
				Sleep(5000);
				window.close();
			}
		
		window.display();
		Sleep(100);
		window.clear();
		execution_Speed++;
	}
	display_Ending();
	system("pause");
	return 0;
}

