#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

class Player
{
public:    
    Player();
    float p_health;
    int p_score;
    int p_money;
    int p_hbMax;  
    bool p_tIsClicked;
    bool p_canStrike;
    bool p_striked;
    bool p_timerIsRunning;

    

    sf::Font p_font;
    sf::Text p_moneyText;
    sf::Text p_scoreText;
    sf::Text p_towerPrice;
    sf::Text p_upgradePrice;
    sf::Text p_scoreNeeded;
    //sf::Text p_strikeTimeText;

    
    sf::Image p_hbImage;
    sf::Texture p_hbTexture;
    sf::Sprite p_hbSprite;
    sf::RectangleShape p_hbBar;
    
    sf::Image p_imGameOver;
    sf::Texture p_tGameOver;
    sf::Sprite p_sGameOver;

    sf::Image p_imYouWin;
    sf::Texture p_tYouWin;
    sf::Sprite p_sYouWin;
    
    
    sf::Image p_imageTower;
    sf::Texture p_textureTower;
    sf::Sprite p_spriteTower;

    sf::Image p_imLightningIcon;
    sf::Texture p_tLightningIcon;
    sf::Sprite p_sLightningIcon;

    sf::Image p_imStrike;
    sf::Texture p_tStrike;
    sf::Sprite p_sStrike;

    sf::Image p_imStrike2;
    sf::Texture p_tStrike2;
    sf::Sprite p_sStrike2;

    float p_tX, p_tY;
    float p_tStartX, p_tStartY;
    float p_tDx,  p_tDy;
    
    void p_update(sf::RenderWindow& window, int SCORENEEDED);
    
};