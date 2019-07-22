#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "tileMap.hpp"
#include "enemy.hpp"
#include "entity.hpp"
#include "menu.hpp"
#include "tower.hpp"
#include "healthbar.hpp"
#include "player.hpp"
#include <iostream>
#include <sstream>
#include <list>



bool startGame()
{
    int enemy_id = 0; 
    int gameTime = 0;
    int lightningStrikeTime = 0;
    int lightningStrikeImageDelay = 0;
    float spawnTime = 0;
    float waveTime = 0;
    float waveTimeDelay = 40000;
    float spawnDelay = 3000;
    float enemySpeed = 0.07;
    int goldPerUnit = 75;
    int scoreNeeded = 100;
    int tower1Price = 300;
    int tower2Price = 700;
    
    const int HEIGHT_MAP = 20;//размер карты высота
    const int WIDTH_MAP = 20;//размер карты ширина
    
    Player player;
    tileMap* map;

    sf::RenderWindow window(sf::VideoMode(1000, 640), "TowerDefense");
    int currentLvl = menu(window);
    if(currentLvl == 6) return false;
    else if(currentLvl == 1)
    {
        map = new tileMap("tileset2.png", currentLvl);
        spawnDelay = 3000;
        waveTimeDelay = 40000;
        scoreNeeded = 30;
        enemySpeed = 0.07;
        goldPerUnit = 100;
    }
    else if(currentLvl == 2)
    {
        map = new tileMap("tileset2.png", currentLvl);
        spawnDelay = 2800;
        waveTimeDelay = 39000;
        scoreNeeded = 50;
        enemySpeed = 0.07;
        goldPerUnit = 100;
    }
    else if(currentLvl == 3)
    {
        map = new tileMap("tileset2.png", currentLvl);
        spawnDelay = 2700;
        waveTimeDelay = 35000;
        scoreNeeded = 100;
        enemySpeed = 0.07;
        goldPerUnit = 100;
    }
    else if(currentLvl == 4)
    {
        map = new tileMap("tileset2.png", currentLvl);
        spawnDelay = 2600;
        waveTimeDelay = 35000;
        scoreNeeded = 150;
        enemySpeed = 0.07;
        goldPerUnit = 100;
    }
    else if(currentLvl == 5)
    {
        map = new tileMap("tileset2.png", currentLvl);
        spawnDelay = 2500;
        waveTimeDelay = 30000;
        scoreNeeded = 200;
        enemySpeed = 0.07;
        goldPerUnit = 100;
    }

    sf::Font font;
    font.loadFromFile("COOPBL.ttf");
    sf::Text text("",font, 20);

    sf::Text menuButton("MENU", font, 30);
    sf::Text exitButton("EXIT", font, 30);

    window.setFramerateLimit(60);
    
    std::list<Enemy*> enemies;
    std::list<Enemy*>::iterator it;

    
    sf::FloatRect finishRect(map->finishPos.x * 32, map->finishPos.y * 32, 32 ,32);
        

    sf::Clock clock;
    sf::Clock gameClock;    
    
    
    
    std::list<Tower*> towerList;
    std::list<Tower*>::iterator tower_it;
    std::vector<towerTile>::iterator tt_it;

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        gameTime = gameClock.getElapsedTime().asSeconds(); // run time
        float time = clock.getElapsedTime().asMicroseconds();

        clock.restart();
        time = time / 800;
        spawnTime += time;
        waveTime += time;
        lightningStrikeTime += time;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            window.close();

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(player.p_spriteTower.getGlobalBounds().contains(mousePos.x, mousePos.y) && player.p_money >= tower1Price)
                    {
                        player.p_spriteTower.setColor(sf::Color::Yellow); 
                        player.p_tDx = mousePos.x - player.p_spriteTower.getPosition().x;
                        player.p_tDy = mousePos.y - player.p_spriteTower.getPosition().y;
                        player.p_tIsClicked = true;       

                    }

                    if (menuButton.getGlobalBounds().contains(mousePos.x,mousePos.y))
                    {

                        menuButton.setFillColor(sf::Color::Blue);
                        menuButton.setOutlineThickness(2);
                        return true;
                    }
                    
                    if(exitButton.getGlobalBounds().contains(mousePos.x,mousePos.y))
                    {
                        exitButton.setFillColor(sf::Color::Blue);
                        exitButton.setOutlineThickness(2);
                        return false;
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    for(tower_it = towerList.begin(); tower_it != towerList.end(); tower_it++)
                    {
                        if( sf::FloatRect((*tower_it)->coordinates.x * 32, (*tower_it)->coordinates.y * 32, 32, 32).contains(mousePos.x, mousePos.y) )
                        {
                            if(player.p_money >= tower2Price)
                            {
                                Tower* temp = *tower_it;
                                towerList.push_back(new Tower(window, true, (*tower_it)->coordinates.x, (*tower_it)->coordinates.y));
                                player.p_money -= tower2Price;
                                towerList.erase(tower_it);
                                delete temp;
                            }
                        }
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(player.p_sLightningIcon.getGlobalBounds().contains(mousePos.x,mousePos.y) && player.p_canStrike)
                    {
                        player.p_striked = true;
                        player.p_canStrike = false;
                    }
                }
            }

            if(player.p_tIsClicked)
            {
               player.p_tX = mousePos.x - player.p_tDx;
               player.p_tY = mousePos.y - player.p_tDy;
            }        

            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(player.p_tIsClicked == true)
                    {
                        for(tt_it = map->towerTileList.begin(); tt_it != map->towerTileList.end(); tt_it++)
                        {
                            if( (sf::FloatRect(tt_it->coordinates.x * 32, tt_it->coordinates.y * 32, 32, 32)).contains(mousePos.x, mousePos.y))
                            {
                                if(tt_it->tile_isSelected == false)
                                {
                                    
                                    
                                    towerList.push_back(new Tower(window, false, tt_it->coordinates.x, tt_it->coordinates.y));
                                    player.p_money -= tower1Price;
                                    tt_it->tile_isSelected = true;
                                    player.p_tX = player.p_tStartX; player.p_tY = player.p_tStartY;
                                    player.p_spriteTower.setColor(sf::Color::White);
                                }
                                
                                    
                            }
                            else 
                            {
                                player.p_tX = player.p_tStartX;
                                player.p_tY = player.p_tStartY;

                                player.p_tIsClicked = false;
                                player.p_spriteTower.setColor(sf::Color::White);
                            }                           
                        }                       
                    } 
                }
            }             
        }

        if(player.p_striked)
        {
            player.p_striked = false;
            lightningStrikeTime = 0;
            player.p_timerIsRunning = true;
            for(auto& it : enemies)
            {
                (*it).health -= 90;
            }
            
        }

       
        

        
        if(lightningStrikeTime >= 45000)
       {
           player.p_canStrike = true;
           lightningStrikeTime = 45000;
       }
    
        window.clear(sf::Color(25,36,53));
        map->mapDraw(window);
       if(waveTime > waveTimeDelay)
       {
           spawnDelay -= 500;
           std::cout<<"New Wave"<<std::endl;
           waveTime = 0;

       }
        
       
        if(spawnTime > spawnDelay)
        {
            enemy_id++;
            
            enemies.push_back(new Enemy(goldPerUnit, enemySpeed,enemy_id,"enemy.png","enemy", map->startPos.x * 32, map->startPos.y * 32, 32, 32));
            spawnTime = 0;
        }

         for(auto & it : towerList)
        {
            (*it).t_update(time, enemies);
        }

        for(it = enemies.begin(); it != enemies.end(); it++)
        {
            Enemy* temp = *it;
            temp->sMove(map->px, map->py, time, player);
            
            window.draw(temp->sprite);
            
            window.draw(temp->healthbar.hb_sprite);
            window.draw(temp->healthbar.bar);
           
            if(temp->isAlive == false)
            {
                player.p_score += 1;
                player.p_money += goldPerUnit;
                enemies.erase(it);
                delete temp;
            }
           
        }
        
        
       

        player.p_update(window, scoreNeeded);

        std::ostringstream gameTimeString;
        gameTimeString << gameTime;
        
        text.setString("GAME TIME: "+gameTimeString.str());
        text.setPosition(680,600);

        menuButton.setFillColor(sf::Color::Yellow);
        menuButton.setOutlineThickness(1);
        menuButton.setPosition(680,550);

        exitButton.setFillColor(sf::Color::Red);
        exitButton.setOutlineThickness(1);
        exitButton.setPosition(900, 550);

        window.draw(menuButton);
        window.draw(exitButton);
        window.draw(text);

         if(player.p_health <= 0)
       {
            time = 0;
            gameTime = 0;
            menuButton.setPosition(350, 450);
            exitButton.setPosition(550, 450);
            
            window.draw(player.p_sGameOver);
            window.draw(menuButton);
            window.draw(exitButton);
       }

       if(player.p_score >= scoreNeeded)
       {
           time = 0;
           gameTime = 0;
        
            menuButton.setPosition(350,450);
            exitButton.setPosition(550, 450);
            
            window.draw(player.p_sYouWin);
            window.draw(menuButton);
            window.draw(exitButton);
       }
        if(player.p_timerIsRunning)
        {
            lightningStrikeImageDelay += time;
            
            if(lightningStrikeImageDelay <= 500)
            {
                window.draw(player.p_sStrike);
               
            }
            else if(lightningStrikeImageDelay >= 500 && lightningStrikeImageDelay <= 1000)
            {
                window.draw(player.p_sStrike2);
            }
            else
            {
                player.p_timerIsRunning = false;
                lightningStrikeImageDelay = 0;
            }
            
        }

       
          
       // window.draw(tower1.sprite);
        window.display();
        }
    for(auto & it : towerList)
    {
        delete it;
    }
    delete map;

}

void gameRunning()
{
    if(startGame()) gameRunning();
}


int main()
{
   gameRunning();
    return 0;
}

