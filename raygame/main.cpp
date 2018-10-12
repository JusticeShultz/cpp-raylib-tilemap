#include "raylib.h"
#include "meep.h"
#include "tile.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
	srand(time(NULL));
	Vector2 mousePoint;

	//[row], [coumn]
	Tile MasterMap[15][20];

	int screenWidth = 1250;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "Why...");

	SetTargetFPS(60);
	
	//Texture originals
	meep Texture[15];
	Texture[0].texture = LoadTexture("Resources/mapTile_001.png");
	Texture[1].texture = LoadTexture("Resources/mapTile_002.png");
	Texture[2].texture = LoadTexture("Resources/mapTile_003.png");
	Texture[3].texture = LoadTexture("Resources/mapTile_004.png");
	Texture[4].texture = LoadTexture("Resources/mapTile_005.png");
	Texture[5].texture = LoadTexture("Resources/mapTile_006.png");
	Texture[6].texture = LoadTexture("Resources/mapTile_007.png");
	Texture[7].texture = LoadTexture("Resources/mapTile_008.png");
	Texture[8].texture = LoadTexture("Resources/mapTile_009.png");
	Texture[9].texture = LoadTexture("Resources/mapTile_119.png");
	Texture[10].texture = LoadTexture("Resources/mapTile_018.png");
	Texture[11].texture = LoadTexture("Resources/mapTile_019.png");
	Texture[12].texture = LoadTexture("Resources/mapTile_020.png");
	Texture[13].texture = LoadTexture("Resources/mapTile_021.png");
	Texture[14].texture = LoadTexture("Resources/Eraser.png");

	meep TopHUD01;
	TopHUD01.playerControlled = false;
	TopHUD01.texture = LoadTexture("Resources/Spacers.png");
	TopHUD01.position = Vector2{ 1, 1 };

	meep TopHUD001;
	TopHUD001.playerControlled = false;
	TopHUD001.texture = LoadTexture("Resources/AdditionalSpacers.png");
	TopHUD001.position = Vector2{ 747, 120 };

	meep TopHUD02;
	TopHUD02.playerControlled = false;
	TopHUD02.texture = LoadTexture("Resources/Selected.png");
	TopHUD02.position = Vector2{ 200, 125 };

	meep TopHUD03;
	TopHUD03.playerControlled = false;
	TopHUD03.texture = Texture[0].texture;
	TopHUD03.position = Vector2{ 30, 25 };

	meep TopHUD04;
	TopHUD04.playerControlled = false;
	TopHUD04.texture = Texture[1].texture;
	TopHUD04.position = Vector2{ 160, 25 };

	meep TopHUD05;
	TopHUD05.playerControlled = false;
	TopHUD05.texture = Texture[2].texture;
	TopHUD05.position = Vector2{ 290, 25 };

	meep TopHUD06;
	TopHUD06.playerControlled = false;
	TopHUD06.texture = Texture[3].texture;
	TopHUD06.position = Vector2{ 405, 25 };

	meep TopHUD07;
	TopHUD07.playerControlled = false;
	TopHUD07.texture = Texture[4].texture;
	TopHUD07.position = Vector2{ 530, 25 };

	meep TopHUD08;
	TopHUD08.playerControlled = false;
	TopHUD08.texture = Texture[5].texture;
	TopHUD08.position = Vector2{ 655, 25 };

	meep TopHUD09;
	TopHUD09.playerControlled = false;
	TopHUD09.texture = Texture[6].texture;
	TopHUD09.position = Vector2{ 775, 25 };

	meep TopHUD10;
	TopHUD10.playerControlled = false;
	TopHUD10.texture = Texture[7].texture;
	TopHUD10.position = Vector2{ 905, 25 };

	meep TopHUD11;
	TopHUD11.playerControlled = false;
	TopHUD11.texture = Texture[8].texture;
	TopHUD11.position = Vector2{ 1030, 25 };

	meep TopHUD12;
	TopHUD12.playerControlled = false;
	TopHUD12.texture = Texture[14].texture;
	TopHUD12.position = Vector2{ 1150, 25 };

	meep TopHUD13;
	TopHUD13.playerControlled = false;
	TopHUD13.texture = Texture[10].texture;
	TopHUD13.position = Vector2{ 775, 150 };

	meep TopHUD14;
	TopHUD14.playerControlled = false;
	TopHUD14.texture = Texture[11].texture;
	TopHUD14.position = Vector2{ 905, 150 };

	meep TopHUD15;
	TopHUD15.playerControlled = false;
	TopHUD15.texture = Texture[12].texture;
	TopHUD15.position = Vector2{ 1030, 150 };

	meep TopHUD16;
	TopHUD16.playerControlled = false;
	TopHUD16.texture = Texture[13].texture;
	TopHUD16.position = Vector2{ 1150, 150 };

	meep Selected;
	Selected.playerControlled = false;
	Selected.texture = Texture[0].texture;
	Selected.position = Vector2{ 205, 130 };
	
	for (int row = 0; row < 15; ++row)
	{
		for (int i = 0; i < 20; i++)
		{
			//DrawRectangle(15 * (i * 4.25), 15 * (row * 4.25), 62, 62, RED);
			MasterMap[row][i].texture = LoadTexture("Resources/mapTile_119.png");
		}
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BEIGE);

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(mousePoint, Rectangle{ 15, 10, 100, 100 })) Selected.texture = Texture[0].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 140, 10, 100, 100 })) Selected.texture = Texture[1].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 265, 10, 100, 100 })) Selected.texture = Texture[2].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 390, 10, 100, 100 })) Selected.texture = Texture[3].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 515, 10, 100, 100 })) Selected.texture = Texture[4].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 640, 10, 100, 100 })) Selected.texture = Texture[5].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 765, 10, 100, 100 })) Selected.texture = Texture[6].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 890, 10, 100, 100 })) Selected.texture = Texture[7].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 1015, 10, 100, 100 })) Selected.texture = Texture[8].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 1140, 10, 100, 100 })) Selected.texture = Texture[9].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 765, 130, 100, 100 })) Selected.texture = Texture[10].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 890, 130, 100, 100 })) Selected.texture = Texture[11].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 1015, 130, 100, 100 })) Selected.texture = Texture[12].texture;
			else if (CheckCollisionPointRec(mousePoint, Rectangle{ 1140, 130, 100, 100 })) Selected.texture = Texture[13].texture;
			else
			{
				for (int row = 0; row < 15; ++row)
				{
					for (int i = 0; i < 20; i++)
					{
						if (CheckCollisionPointRec(mousePoint, Rectangle{ (float)15 * ((float)i *(float) 4.25), (float)15 * ((float)row * (float)4.25), 64, 64 }))
						{
							MasterMap[row][i].texture = Selected.texture;
						}
					}
				}
			}
		}

		//DrawRectangle(25, 100, 200, 60, RED);
		//DrawText("Consume", 40, 110, 40, BLACK);

		TopHUD01.refresh();
		TopHUD001.refresh();
		TopHUD02.refresh();
		TopHUD03.refresh();
		TopHUD04.refresh();
		TopHUD05.refresh();
		TopHUD06.refresh();
		TopHUD07.refresh();
		TopHUD08.refresh();
		TopHUD09.refresh();
		TopHUD10.refresh();
		TopHUD11.refresh();
		TopHUD12.refresh();
		TopHUD13.refresh();
		TopHUD14.refresh();
		TopHUD15.refresh();
		TopHUD16.refresh();
		Selected.refresh();
		DrawText("Selected:", 5, 145, 40, BLACK);

		mousePoint = GetMousePosition();

		//Debug
		/*
		DrawRectangle(15, 10, 100, 100, RED);
		DrawRectangle(140, 10, 100, 100, RED);
		DrawRectangle(265, 10, 100, 100, RED);
		DrawRectangle(390, 10, 100, 100, RED);
		DrawRectangle(515, 10, 100, 100, RED);
		DrawRectangle(640, 10, 100, 100, RED);
		DrawRectangle(765, 10, 100, 100, RED);
		DrawRectangle(890, 10, 100, 100, RED);
		DrawRectangle(1015, 10, 100, 100, RED);
		DrawRectangle(1140, 10, 100, 100, RED);
		DrawRectangle(765, 130, 100, 100, RED);
		DrawRectangle(890, 130, 100, 100, RED);
		DrawRectangle(1015, 130, 100, 100, RED);
		DrawRectangle(1140, 130, 100, 100, RED);
		*/

		for (int row = 0; row < 15; ++row)
		{
			for (int i = 0; i < 20; i++)
			{
				//DrawRectangle(15 * (i * 4.25), 15 * (row * 4.25), 62, 62, RED );
				if (row > 3)
				DrawTexture(MasterMap[row][i].texture, 15 * (i * 4.25), 15 * (row * 4.25), WHITE);
			}
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}