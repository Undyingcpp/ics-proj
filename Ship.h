#include<iostream>
#include "imgui.h"
#include "imgui-sfml.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;
class Ship{
private:
	Vector2f Position;
	double Speed;
	double AngleSpeed;
	bool LeftPressed;
    bool RightPressed;
	Sprite p_Sprite;
	Texture p_texture;
public:
	Ship();
	Sprite getSprite();
	void turnLeft();
 	void turnRight();
 	void stopLeft();
    void stopRight();
    void update(double elapsedTime);
}