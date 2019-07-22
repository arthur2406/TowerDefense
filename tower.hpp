#pragma once 
#include <SFML/Graphics.hpp>
#include <Vector>
#include <memory>
#include "Enemy.hpp"
#include "tileMap.hpp"


class Bullet : public Entity
{
public:

    void update(float& time);
    Bullet(bool IS_UPGRADED);
    ~Bullet();
    float b_speed;
    bool b_isUpgraded;
    float b_distance;
  //  void moveToEnemy(float& time,float enemyX, float enemyY);
    float dx, dy;   
   
};



class Tower : public Entity, public towerTile
{
public:    
    Tower(sf::RenderWindow& WINDOW, bool IS_UPGRADED, float, float);
    ~Tower();

    void update(float& time);
    
    void t_update(float&time, std::list<Enemy*>& enemies);
    Bullet* bullet; 

    
    
     // saved in pixels
private:   
    
    std::list<Enemy*>::iterator it_e;
    sf::RectangleShape t_attackZone;
    int t_price;
    bool t_isUpgraded;// 1 or 2 lvl
    int t_isAttacking;
    float t_damage;
    float t_radius;

    sf::RenderWindow* window;
    void checkArea(std::list<Enemy*>& enemies, float& time);

};

