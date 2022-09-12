#pragma once
#include "imgui.h"
#include "imgui-sfml.h"
#include "Ship.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;
class Engine
{
private:
 
    RenderWindow m_Window;  
    Sprite BackgroundSprite;
    Texture BackgroundTexture;
    Ship my_Ship;
    Planet my_Planet;
    void input(){
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
 	if (Keyboard::isKeyPressed(Keyboard::W))
    {
        my_Ship.goFront();
    }
    else
    {
    	my_Ship.stopFront();
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        my_Ship.goBack();
    }
    else
    {
    	my_Ship.stopBack();
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        my_Ship.turnLeft();
    }
    else
    {
        my_Ship.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        my_Ship.turnRight();
    }
    else
    {
        my_Ship.stopRight();
    }                       
 
	}
    void update(float dtAsSeconds){
    my_Ship.update(dtAsSeconds, my_Planet);
    my_Planet.update();
	}
    void draw(){
    m_Window.clear(Color::White);
    m_Window.draw(BackgroundSprite);
    m_Window.draw(my_Ship.getSprite());
    m_Window.draw(my_Planet.getSprite());
    m_Window.display();
	}
 
public:
    Engine(){
   	Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Game Engine",
        Style::Fullscreen);
 
    BackgroundTexture.loadFromFile("background.jpg");

    BackgroundSprite.setTexture(BackgroundTexture);
 
    }
    void start(){
    Clock clock;
 
    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
 
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
	}
 	
};