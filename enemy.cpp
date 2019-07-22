#include "enemy.hpp"
#include "entity.hpp"
#include <iostream>

Enemy::Enemy(int GOLDPERUNIT, float LVLSPEED, int ENEMY_ID, const std::string& ENEMY_IMAGE,const std::string& ENEMY_NAME, float X, float Y, float W, float H)
{
    e_id = ENEMY_ID;
    name = ENEMY_NAME;
    goldPerUnit = GOLDPERUNIT;
    image.loadFromFile("images/" + ENEMY_IMAGE);
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    lvlSpeed = LVLSPEED; 
    isMovable = true;
    isAlive = true;
    x = X; y = Y;
    w = W; h = H;

    dx = 0; dy = 0; speed = 0; dir = 0; i = 1;
    health = 100;
    isAlive = true;
   // inRadius = false;
    
    sprite.setTextureRect(sf::IntRect(0, 30, w, h)); 
    currentFrame = 0;
}

void Enemy::update(float& time)
{
    switch (dir)
    {
        case 0: dx = speed; dy = 0; break;
        case 1: dx = -speed; dy = 0; break;
        case 2: dx = 0; dy = speed; break;
        case 3: dx = 0; dy = -speed; break;
    }
     
    x += dx*time;
    y += dy*time;
    
    healthbar.hb_update(health, x , y);
    if(health <= 0) isAlive = false;
    
    sprite.setPosition(x,y); 
 
};

void Enemy::sMove(std::vector<int>& px, std::vector<int>& py, float& time, Player& player)
{
    const int tilesize  = 32; // 
   
    speed = 0;


    if(px[i] * tilesize > x) // right
    {
        dir = 0;
        speed = lvlSpeed;

        currentFrame += 0.005*time;
        if(currentFrame > 3) currentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(32 * static_cast<int>(currentFrame),157, w, h));

        if((px[i] * tilesize - x) < 1)
        {
            
            x = px[i] * tilesize;
            y = py[i] * tilesize;

            i++;
        }
    }
      

    if(py[i] * tilesize < y)// up
    {
        dir = 3;
        speed = lvlSpeed;

        currentFrame += 0.005*time;
        if(currentFrame > 3) currentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(32 * static_cast<int>(currentFrame),225, w, h));

        if((y - py[i] * tilesize) < 1) 
        {
            x = px[i] * tilesize;
            y = py[i] * tilesize;

            i++;
        }
    }


    if(px[i] * tilesize < x) // left
    {
        dir = 1;
        speed = lvlSpeed;

        currentFrame += 0.005*time;
        if(currentFrame > 3) currentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(32 * static_cast<int>(currentFrame),97, w, h));
        
        if((x - (px[i] * tilesize)) < 1 )
        {
            x = px[i] * tilesize;
            y = py[i] * tilesize;

            i++;
        } 
    }

     if(py[i] * tilesize > y) // down
    {
        dir = 2;
        speed = lvlSpeed; 

        currentFrame += 0.005 * time;
        if(currentFrame > 3) currentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(32 * static_cast<int>(currentFrame),31, w, h));

        if((py[i] * tilesize - y) < 1) //checking if we had changed position on 32px
        {
            x = px[i] * tilesize;
            y = py[i] * tilesize;
            i++;
        }
    } 
   

           
    update(time);

    if(i >= px.size() || i >= py.size())
    {
        player.p_health -= 100;
        player.p_money -= goldPerUnit;
        player.p_score -= 1;
        
       // std::cout<<"health: "<<player.p_health<<std::endl;
        isAlive = false;
    }  
   
      
}
