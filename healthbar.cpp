#include "healthbar.hpp"

HealthBar::HealthBar()
{
    hb_image.loadFromFile("images/healthbar.png");
    hb_texture.loadFromImage(hb_image);
    hb_sprite.setTexture(hb_texture);

    bar.setFillColor(sf::Color(0,0,0));
    max = 100;

}
void HealthBar::hb_update(int e_health, float e_X, float e_Y)
{
    if(e_health > 0 && e_health < 100)
    {
        bar.setSize(sf::Vector2f(-((max - e_health) * 35 / max) ,6));
    }

    hb_sprite.setPosition(e_X,e_Y - 5);
    bar.setPosition(e_X + 36,e_Y -5);
}