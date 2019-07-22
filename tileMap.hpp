#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#pragma once 

using namespace sf;

const int W = 20;
const int H = 20;


class towerTile
{
public:
   // towerTile();
    int effRate; //rate of efficience
    sf::Vector2u coordinates; // x y in tileMap
    bool tile_isSelected;

    bool operator < (const towerTile& towtile) const 
    {
       return(effRate > towtile.effRate); //reverse for descending sort in std::sort
    }
};
 



class tileMap 
{
public:
    
    tileMap(const std::string& tileset, int lvl);
    ~tileMap();
    mapDraw(sf::RenderWindow& window);
    
    sf::Vector2u startPos;
    sf::Vector2u finishPos;
    

    int tileArray[H][W];

    
    

    bool lee_search();   

    std::vector<int> px;
    std::vector<int> py; // here we will contain our shortest path

    void sortTowerTiles();
    std::vector<towerTile> towerTileList;
    

private:
    
    

    sf::Image image;
    sf::Texture texture;

    sf::Sprite sprite;
    sf::Sprite spriteTowerTile;

};





