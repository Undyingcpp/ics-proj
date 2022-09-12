#pragma once
#include "imgui.h"
#include "imgui-sfml.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;
class Planet
{
public:
	Vector2f Position;
	float mass;
	float radius;
	Texture p_Texture;
	Sprite p_Sprite;
	Planet(){
		Position = Vector2f{1000, 500};
		mass = 10000000;
		radius = 100;
		p_Texture.loadFromFile("planet.png");
		p_Sprite.setTexture(p_Texture);
	}
	Sprite getSprite(){
		return p_Sprite;
	}
	void update(){
		
		Vector2f spos ={Position.x - 250, Position.y - 250};

		p_Sprite.setPosition(spos);
	}
};