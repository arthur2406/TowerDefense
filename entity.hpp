#pragma once 
#include <SFML/Graphics.hpp>


class Entity 
{
public:    
    
    
    std::string File;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    float x,y,w,h; 
    std::string name; 

    bool isMovable;
    bool isAlive;
    virtual void update(float&) = 0; 
    
    int i; 

    sf::FloatRect getRectEntity();
    
};