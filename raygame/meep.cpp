#include "meep.h"
#include <iostream>

meep::meep()
{
	enabled = true;
	playerControlled = false;
	texture = LoadTexture("Resources/Demon.png");
	position = { 0,0 };
}

meep::meep(bool _enabled)
{
	enabled = _enabled;
	playerControlled = false;
	texture = LoadTexture("Resources/Demon.png");
	position = { 0,0 };
}

meep::meep(bool _enabled, bool _player)
{
	enabled = _enabled;
	playerControlled = _player;
	texture = LoadTexture("Resources/Demon.png");
	position = { 0,0 };
}

meep::~meep()
{
	UnloadTexture(texture);
}

void meep::update()
{
	if (!playerControlled) { return; }

	if (IsKeyDown(KEY_A)) { position.x -= 1.0f * speed; }
	if (IsKeyDown(KEY_D)) { position.x += 1.0f * speed; }
	if (IsKeyDown(KEY_W)) { position.y -= 1.0f * speed; }
	if (IsKeyDown(KEY_S)) { position.y += 1.0f * speed; }
}

void meep::refresh()
{
	if (enabled)
	{
		DrawTexture(texture, position.x, position.y, WHITE);
	}
}