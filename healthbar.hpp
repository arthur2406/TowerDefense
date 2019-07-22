#pragma once
#include <SFML/Graphics.hpp>

class HealthBar
{
public:
    sf::Image hb_image;
    sf::Texture hb_texture;
    sf::Sprite hb_sprite;
    sf::RectangleShape bar;

    int max;  

    HealthBar(); 
    void hb_update(int e_health, float, float);
    
};