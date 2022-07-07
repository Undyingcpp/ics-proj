#pragma once
#include<iostream>
#include "imgui.h"
#include "imgui-sfml.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;
#include "Ship.h"
 
Bob::Bob()
{
    // Вписываем в переменную скорость Боба
    m_Speed = 400;
 
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("bob.png");
    m_Sprite.setTexture(m_Texture);     
 
    // Устанавливаем начальную позицию Боба в пикселях
    m_Position.x = 300;
    m_Position.y = 300;
 
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite Bob::getSprite()
{
    return m_Sprite;
}
 
void Bob::moveLeft()
{
    m_LeftPressed = true;
}
 
void Bob::moveRight()
{
    m_RightPressed = true;
}
 
void Bob::stopLeft()
{
    m_LeftPressed = false;
}
 
void Bob::stopRight()
{
    m_RightPressed = false;
}
 
// Двигаем Боба на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Bob::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
 
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
 
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);   
 
}