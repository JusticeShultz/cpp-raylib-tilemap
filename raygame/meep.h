#pragma once
#include "raylib.h"
#include <string>;

class meep
{
public:
	bool enabled;
	Texture2D texture;
	bool playerControlled;
	Vector2 position;
	float speed;

	meep();
	meep(bool _enable);
	meep(bool _enable, bool _player);
	~meep();
	
	void update();
	void refresh();
};