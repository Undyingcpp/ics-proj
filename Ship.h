#pragma once
#include<bits/stdc++.h>
#include "imgui.h"
#include "imgui-sfml.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Planet.h"
using namespace sf;
float len(Vector2f v){
	return sqrt(v.x * v.x + v.y * v.y);
}
class Ship{
private:
	Vector2f Position;
	Vector2f Force;
	Vector2f Speed;
	float Angle;
	float AngleSpeed;
	float engineforce;
	float mass;
	bool FrontPressed;
	bool BackPressed;
	bool LeftPressed;
    bool RightPressed;
	Sprite s_Sprite;
	Texture s_Texture;
public:
	Ship(){
    Speed = {0, 0};
    AngleSpeed = 0.5;
    engineforce = 30;
    mass = 1;
    s_Texture.loadFromFile("ship.png");
    s_Sprite.setTexture(s_Texture);     
    Position.x = 300;
    Position.y = 300;
 }
	Sprite getSprite(){
    return s_Sprite;
  	}
	void turnLeft(){
    LeftPressed = true;
 	}
 	void turnRight(){
    RightPressed = true;
	}
 	void stopLeft(){
    LeftPressed = false;
  	}
    void stopRight(){
    RightPressed = false;
	}
	void goFront(){
    FrontPressed = true;
	}
 	void stopFront(){
    FrontPressed = false;
  	}
  	void goBack(){
    BackPressed = true;
	}
 	void stopBack(){
    BackPressed = false;
  	}
    void update(float elapsedTime, Planet plan){
    if (RightPressed)
    {
        Angle += AngleSpeed * elapsedTime;
    }
 
    if (LeftPressed)
    {
        Angle -= AngleSpeed * elapsedTime;
    }
    Force={0,0};
    if(FrontPressed)
    {
    	Force = Vector2f{cos(Angle) * engineforce / mass, sin(Angle) * engineforce / mass};
    }
    if(BackPressed)
    {
    	Force = Vector2f{-cos(Angle) * engineforce, -sin(Angle) * engineforce};
    }
    float f = plan.mass * mass / pow(len(plan.Position-Position) , 3);
    Force+=(plan.Position-Position) * f;
    s_Sprite.setRotation(Angle * 180 / 3.1415926);
    Speed += Vector2f{Force.x / mass * elapsedTime, Force.y / mass * elapsedTime};
    Position+=Vector2f{ Speed.x * elapsedTime, Speed.y * elapsedTime};
    s_Sprite.setPosition(Position);   
 
	}
};