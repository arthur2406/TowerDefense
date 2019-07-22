#pragma once 
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "healthbar.hpp"
#include "player.hpp"
class Enemy :  public Entity
{
public:
    int e_id;
    int dir;
    float health;    
    float  dx, dy, speed;  
    float lvlSpeed;
    int goldPerUnit;

    Enemy(int,float, int, const std::string& ENEMY_IMAGE,const std::string& ENEMY_NAME, float X, float Y, float W, float H);    
    void sMove(std::vector<int>& px, std::vector<int>& py, float& time,Player& player);
    void update(float& time);

    HealthBar healthbar;

private:
    
    float currentFrame;

};

