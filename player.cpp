#include "player.hpp"


Player::Player()
{
    p_tIsClicked = false;
    p_canStrike = false;
    p_striked = false;
    p_timerIsRunning = false;
    p_health = 1000;
    p_score = 0;
    p_money = 300;
    p_font.loadFromFile("COOPBL.ttf");

    p_moneyText.setFont(p_font);
    p_moneyText.setCharacterSize(30);
    p_scoreNeeded.setFont(p_font);
    p_scoreNeeded.setCharacterSize(30);
  

    p_towerPrice.setFont(p_font);
    p_towerPrice.setCharacterSize(15);
    
    p_upgradePrice.setFont(p_font);
    p_upgradePrice.setCharacterSize(15);

    p_scoreText.setFont(p_font);
    p_scoreText.setCharacterSize(30);

    p_moneyText.setPosition(680,90);
    p_scoreText.setPosition(680,120);
    p_scoreNeeded.setPosition(680,350);
    

    
    
    p_towerPrice.setPosition(680, 300);
    p_upgradePrice.setPosition(680, 325);
   
    p_hbImage.loadFromFile("images/p_healthbar.png");
    p_hbTexture.loadFromImage(p_hbImage);
    p_hbSprite.setTexture(p_hbTexture);

    p_imageTower.loadFromFile("images/p_tower.png");
    p_textureTower.loadFromImage(p_imageTower);
    p_spriteTower.setTexture(p_textureTower);
    p_spriteTower.setTextureRect(sf::IntRect(26, 170, 53, 130));

    p_imGameOver.loadFromFile("images/menu/gameover.jpg");
    p_tGameOver.loadFromImage(p_imGameOver);
    p_sGameOver.setTexture(p_tGameOver);

    p_imYouWin.loadFromFile("images/menu/youwin.jpg");
    p_tYouWin.loadFromImage(p_imYouWin);
    p_sYouWin.setTexture(p_tYouWin);

    p_imLightningIcon.loadFromFile("images/lightningicon.png");
    p_tLightningIcon.loadFromImage(p_imLightningIcon);
    p_sLightningIcon.setTexture(p_tLightningIcon);
    p_sLightningIcon.setPosition(790,165);

    p_imStrike.loadFromFile("images/lightning.png");
    p_tStrike.loadFromImage(p_imStrike);
    p_sStrike.setTexture(p_tStrike);

    p_imStrike2.loadFromFile("images/lightning2.png");
    p_tStrike2.loadFromImage(p_imStrike2);
    p_sStrike2.setTexture(p_tStrike2);
    
    

    p_tStartX = 680; p_tStartY = 160;
    p_spriteTower.setPosition(p_tStartX, p_tStartY);

    p_tX = 680; p_tY = 160;

    p_hbBar.setFillColor(sf::Color(0,0,0));
    p_hbMax = 1000;
}

void Player::p_update(sf::RenderWindow& window, int SCORENEEDED)
{
    std::ostringstream p_scoreString;
    std::ostringstream p_moneyString;
    std::ostringstream p_scoreNeededStr;
    

    p_scoreString<< p_score;
    p_moneyString<< p_money;
    p_scoreNeededStr<< SCORENEEDED;
  

    p_moneyText.setString("MONEY $ :"+p_moneyString.str());
    p_scoreText.setString("SCORE :"+p_scoreString.str());
    p_towerPrice.setString("300$");
    p_upgradePrice.setString("UPGRADE: 700$");
    p_scoreNeeded.setString("KILL "+p_scoreNeededStr.str()+" TO WIN!");
   
   
    p_upgradePrice.setFillColor(sf::Color::Green);
    p_towerPrice.setFillColor(sf::Color::Green);
    p_moneyText.setFillColor(sf::Color::Green);
    p_scoreText.setFillColor(sf::Color::Yellow);
    p_scoreNeeded.setFillColor(sf::Color::Red);
    if(!p_canStrike)
    {
        p_sLightningIcon.setColor(sf::Color(37,48,48));
    }
    else
    {
        p_sLightningIcon.setColor(sf::Color::White);
    }
    
    p_sStrike.setPosition(0,0);
    p_sStrike2.setPosition(0,0);
    
    window.draw(p_upgradePrice);
    window.draw(p_moneyText);
    window.draw(p_scoreText);
    window.draw(p_towerPrice);
    window.draw(p_scoreNeeded);
    window.draw(p_sLightningIcon);


    if(p_health > 0 && p_health < 1000)
    {
        p_hbBar.setSize(sf::Vector2f(-((p_hbMax - p_health) * 238) / p_hbMax , 26));
        
    }
    if(p_health < 100)
        {
            p_hbBar.setSize(sf::Vector2f(-230, 26));
        }
    
    p_hbSprite.setPosition(680, 40);
    p_hbBar.setPosition(680 + 250 - 11 ,40 + 7);
    p_spriteTower.setPosition(p_tX, p_tY);
    p_sGameOver.setPosition(0,0);
    p_sYouWin.setPosition(0,0);
   

    
    window.draw(p_hbSprite);
    window.draw(p_hbBar);
    window.draw(p_spriteTower);
    

}