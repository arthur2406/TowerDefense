
#include "menu.hpp"

using namespace sf;
int menu(sf::RenderWindow& window)
{
    Texture backgroundTexture, lvl1Texture, lvl2Texture, lvl3Texture, lvl4Texture, lvl5Texture, quitTexture;
	lvl1Texture.loadFromFile("images/menu/level1.png");
	lvl2Texture.loadFromFile("images/menu/level2.png");
    lvl3Texture.loadFromFile("images/menu/level3.png");
    lvl4Texture.loadFromFile("images/menu/level4.png");
    lvl5Texture.loadFromFile("images/menu/level5.png");
    quitTexture.loadFromFile("images/menu/quit.png");
	backgroundTexture.loadFromFile("images/menu/background.jpg");
	
	Sprite lvl1(lvl1Texture), lvl2(lvl2Texture), lvl3(lvl3Texture), lvl4(lvl4Texture), lvl5(lvl5Texture), quit(quitTexture), background(backgroundTexture);

	bool isMenu = 1;
	int menuNum = 0;

	lvl1.setPosition(100, 30);
	lvl2.setPosition(100, 90);
	lvl3.setPosition(100, 150);
    lvl4.setPosition(100, 210);
    lvl5.setPosition(100, 270);
    quit.setPosition(100, 330);
	background.setPosition(345, 0);
 
	/////////MENU//////////////
	while (isMenu)
	{
		sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
			{
            window.close();
			isMenu = false;
			
			}
        } 
		
		lvl1.setColor(Color::White);
		lvl2.setColor(Color::White);
		lvl3.setColor(Color::White);
        lvl4.setColor(Color::White);
        lvl5.setColor(Color::White);
        quit.setColor(Color::White);


		menuNum = 0;
		window.clear(Color(11, 21, 38));
 
		if (IntRect(100, 30, 249, 51).contains(Mouse::getPosition(window))) { lvl1.setColor(Color::Blue); menuNum = 1; }
        if (IntRect(100, 90, 249, 51).contains(Mouse::getPosition(window))) { lvl2.setColor(Color::Blue); menuNum = 2; }
        if (IntRect(100, 150, 249, 51).contains(Mouse::getPosition(window))) { lvl3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(100, 210, 249, 51).contains(Mouse::getPosition(window))) { lvl4.setColor(Color::Blue); menuNum = 4; }
        if (IntRect(100, 270, 249, 51).contains(Mouse::getPosition(window))) { lvl5.setColor(Color::Blue); menuNum = 5; }
		if (IntRect(100, 330, 165, 57).contains(Mouse::getPosition(window))) { quit.setColor(Color::Blue); menuNum = 6;}
 
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1){ isMenu = false; return 1;}//
			if (menuNum == 2) { isMenu = false; return 2; }
            if (menuNum == 3){ isMenu = false; return 3; }
            if (menuNum == 4){ isMenu = false; return 4; }
            if (menuNum == 5){ isMenu = false; return 5; }
			if (menuNum == 6)  { window.close(); isMenu = false; return 6;}
 
		}
 
		window.draw(background);
		window.draw(lvl1);
		window.draw(lvl2);
		window.draw(lvl3);
        window.draw(lvl4);
        window.draw(lvl5);
        window.draw(quit);
		
		window.display();

		
	}
	////////////////////////////////////////
}