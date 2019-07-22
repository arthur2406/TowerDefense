#include "tower.hpp"
#include <iostream>
#include <cmath>

#include <algorithm>

Tower::Tower(sf::RenderWindow& WINDOW, bool IS_UPGRADED, float X, float Y)
{
    if(IS_UPGRADED)
    {
        image.loadFromFile("images/tower2.png");
        t_damage = 34;
        t_price = 400;
    }
    else
    {
        image.loadFromFile("images/tower1.png");
        t_damage = 10;
        t_price = 100;
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setOrigin(0,38);
   // sprite.setOrigin(0,-32);

    
    w = 32; 
    h = 70;
    
    if (coordinates.x == -1 && coordinates.y == -1)
    {
        std::cout<<"i've got bad news for you!"<<std::endl;
        
    }
    //game coordinates, not window
    coordinates.x = X;
    coordinates.y = Y;

    t_radius = 140;
    t_attackZone.setSize(sf::Vector2f(t_radius, t_radius));
    t_attackZone.setOrigin(sf::Vector2f(t_radius / 2, t_radius / 2));
    t_attackZone.setPosition((X * 32 + 16), (Y * 32 + 16));


    
    t_isAttacking = 0; // int value
    isMovable = false;
    isAlive = true;
    t_isUpgraded = IS_UPGRADED;
    
    bullet = new Bullet(IS_UPGRADED);
    window = &WINDOW;

    sprite.setPosition(X * 32, Y * 32);

}


Tower::~Tower()
{
    delete(bullet);
}

void Tower::checkArea(std::list<Enemy*>& enemies, float& time)
{
  
    for(it_e = enemies.begin(); it_e != enemies.end(); it_e++)
    {        
        if(!t_isAttacking || t_isAttacking == (*it_e)->e_id) 
        {                        
            if(  ((*it_e)->getRectEntity().intersects(t_attackZone.getGlobalBounds())) && (*it_e)->isAlive  && !bullet->isAlive)
            {
                bullet->isAlive = true;
                t_isAttacking = (*it_e)->e_id;
                bullet->sprite.setPosition(Vector2f(coordinates.x * 32 + 16, coordinates.y * 32 + 16));
                bullet->x = bullet->sprite.getPosition().x; bullet->y = bullet->sprite.getPosition().y;             
            }
            else
            {   
                t_isAttacking = 0;
            }

            if(!(*it_e)->isAlive && bullet->b_distance > 10)
                {
                   // t_isAttacking = 0;  
                    continue;   
                }
               

            
            if(bullet->isAlive)
            {

                bullet->b_distance = sqrt(   ((*it_e)->sprite.getPosition().x - bullet->x) * ((*it_e)->sprite.getPosition().x - bullet->x)  +   ((*it_e)->sprite.getPosition().y - bullet->y) * ((*it_e)->sprite.getPosition().y - bullet->y) );       
                t_isAttacking = (*it_e)->e_id;
                if( bullet->b_distance > 10)
                {
                   
                    window->draw(bullet->sprite);
                    bullet->x += (bullet->b_speed) * time * ((*it_e)->sprite.getPosition().x - bullet->x) / bullet->b_distance;
                    bullet->y += (bullet->b_speed) * time * ((*it_e)->sprite.getPosition().y - bullet->y) / bullet->b_distance;

                    bullet->sprite.setPosition(sf::Vector2f(bullet->x, bullet->y));
                   
                }
                else
                {
                   
                    (*it_e)->health -= t_damage;
                    bullet->isAlive = false;

                    if(((*it_e)->health <= 0))
                    {
                        (*it_e)->isAlive = false;
                        std::cout<<"hello"<<std::endl;
            
                        t_isAttacking = 0;
                        
                    }        
                }                
            }
        } 
    } 
}

    
    




void Tower::t_update(float& time, std::list<Enemy*>& enemies)
{
    checkArea(enemies, time);
    window->draw(sprite);
   // window->draw(t_attackZone);
}

void Tower::update(float& time){} // this func is not going to be used



////////////////////BULLET//////////////////
Bullet::Bullet(bool IS_UPGRADED)
{
    
    if(IS_UPGRADED)
    {
        b_speed = 0.2;
        image.loadFromFile("images/bullet2.png");
    }
    else
    {
        b_speed = 0.2;
        image.loadFromFile("images/bullet1.png");
    }
    

    texture.loadFromImage(image);
    sprite.setTexture(texture);
    
    
    w = 10; h = 10;
    isMovable = true;
    isAlive = false;
    b_isUpgraded = IS_UPGRADED;
}

void Bullet::update(float& time){};

Bullet::~Bullet()
{
   
}


