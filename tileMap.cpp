#include <SFML/Graphics.hpp>
#include "tileMap.hpp"
#include <list>
#include <iostream>


int tileArray1[W][H] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1},
    {1,2,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,4},
    {1,2,1,3,3,3,3,3,3,1,2,1,1,1,2,1,3,1,2,1},
    {1,2,1,3,3,1,1,1,1,1,2,1,3,1,2,1,3,1,2,1},
    {1,2,1,3,3,1,2,2,2,2,2,1,3,1,2,1,3,1,2,1},
    {1,2,1,3,3,1,2,1,1,1,2,1,3,1,2,1,3,1,2,1},
    {1,2,1,3,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1},
    {1,2,1,3,3,1,2,1,3,1,2,1,3,1,2,1,1,1,2,1},
    {1,2,1,3,3,1,2,1,3,1,2,1,3,1,2,2,2,2,2,1},
    {1,2,1,3,3,1,2,1,3,1,2,1,1,1,1,1,1,1,1,1},
    {1,2,1,3,3,1,2,1,3,1,2,2,1,3,3,3,3,3,3,1},
    {1,2,1,3,3,1,2,1,3,1,1,2,1,1,1,1,1,1,3,1},
    {1,2,1,3,3,1,2,1,1,1,1,2,2,2,2,2,2,1,1,1},
    {1,2,1,3,3,1,2,2,2,1,1,1,1,1,1,1,2,1,1,1},
    {1,2,1,3,3,1,1,1,2,1,3,3,3,3,3,1,2,1,1,1},
    {1,2,1,3,3,3,3,1,2,1,3,3,3,3,3,1,2,1,1,1},
    {1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
    {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


int tileArray2[W][H] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,3,3,3,3,3,3,1,1,1,2,2,2,2,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,3,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,1,2,2,2,1,1,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,1,3,1,1,1,2,1,1},
    {0,2,2,1,1,1,1,1,1,1,1,1,1,1,3,3,1,2,1,1},
    {1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1},
};

int tileArray3[W][H] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,1,3,1,2,1,3,3,3,3,3,3,3,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,2,2,2,2,2,2,4},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,1,1,2,1,3,1,2,1,1},
    {0,2,2,1,3,1,2,2,2,2,2,2,2,2,1,3,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,1,1,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,3,3,3,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int tileArray4[W][H] =
{
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,1,3,1,2,1,3,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,3,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,2,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,1,2,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,2,1,3,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,2,1,3,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,2,2,2,2,1,3,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,3,3,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,1,2,1,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int tileArray5[W][H] =
{
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,2,2,2,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,1,1,2,1,1,2,1,3,3,3,3,3,3,1,2,1,1},
    {1,1,2,1,1,2,1,1,2,1,3,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,1,2,2,2,2,1,3,1,1,1,1,3,1,2,1,1},
    {1,1,2,1,1,1,1,1,2,1,3,3,3,3,1,3,1,2,1,1},
    {1,1,2,1,3,3,3,1,2,1,1,1,1,3,1,3,1,2,1,1},
    {1,1,2,1,3,1,3,1,2,2,2,2,1,3,1,3,1,2,1,1},
    {1,1,2,1,3,1,3,1,1,1,1,2,1,3,3,3,1,2,1,1},
    {1,1,2,1,3,1,3,3,3,3,1,2,1,1,1,1,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,3,1,2,2,2,2,1,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,3,1,1,1,1,2,1,1,2,1,1},
    {1,1,2,1,3,1,1,1,1,3,3,3,3,1,2,1,1,2,1,1},
    {1,1,2,1,3,3,3,3,3,3,3,3,3,1,2,2,2,2,1,1},
    {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1},
};

tileMap::tileMap(const std::string& tileset, int lvl)
{
   
    for(int i = 0; i < W; i++)
        for(int j = 0; j < H; j++)
        {
            switch (lvl)
            {
                case 1: tileArray[i][j] = tileArray1[i][j]; break;
                case 2: tileArray[i][j] = tileArray2[i][j]; break;
                case 3: tileArray[i][j] = tileArray3[i][j]; break;
                case 4: tileArray[i][j] = tileArray4[i][j]; break;
                case 5: tileArray[i][j] = tileArray5[i][j]; break;
            }
            
        }
            
   
    


    px.resize(20 * 20);
    py.resize(20 * 20);
  
    image.loadFromFile("images/"+tileset); 

    texture.loadFromImage(image);
   

    sprite.setTexture(texture);
    spriteTowerTile.setTexture(texture);

    for(int i = 0; i < W; i++)
        for(int j = 0; j < H; j++)
        {

            if(tileArray[i][j] == 4) { startPos.x = j, startPos.y = i;}
            if(tileArray[i][j] == 0) { finishPos.x = j; finishPos.y = i;}

        }
    if(!lee_search()) std::cout<<"in lee_search sth went wrong"<<std::endl; // run algoritm   
    
    sortTowerTiles();    // run sort
    

}

tileMap::~tileMap()
{

}

tileMap::mapDraw(sf::RenderWindow& window)
{
    

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
        {
            if(tileArray[i][j] == 0) sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
            if(tileArray[i][j] == 1) sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
            if(tileArray[i][j] == 2) sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
            if(tileArray[i][j] == 3)
            { 
                int meanWhileOperator = 0;
                sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
                for(auto & it : towerTileList)
                {
                    meanWhileOperator++;
                    if(meanWhileOperator == 10) break;
                    if(it.coordinates.x == j && it.coordinates.y == i)
                    {
                        spriteTowerTile.setTextureRect(sf::IntRect(96, 0, 32, 32));
                        spriteTowerTile.setColor(sf::Color(0 / it.effRate, 0 / it.effRate, 0 / it.effRate));
                        //std::cout<<"Hello"<<std::endl;
                        spriteTowerTile.setPosition(j * 32, i * 32);
                        
                        
                    }
                } 
            }
            if(tileArray[i][j] == 4) sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));

            
            sprite.setPosition(j * 32, i * 32);
            

            
            window.draw(sprite);
            window.draw(spriteTowerTile);
        }
}




bool tileMap::lee_search()
{
    const int WALL = -1; //impassable tile
    const int BLANK = -2; //tile was not touched
    int len; // length of the path
    
    int grid[W][H];
    
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {   
            if(tileArray[i][j] != 2 && tileArray[i][j] != 4 && tileArray[i][j] != 0)
            {
                grid[i][j] = WALL; // impassable
            }
            else
            {
                grid[i][j] = BLANK; // 0 steps were made
            }

        }


    
     // lets find the shortest path from startPos to FinishPos
    int dx[4] = {1, 0,-1,0}; //offset
    int dy[4] = {0, 1, 0, -1};//r d l u

    int d, x, y, k;
    bool stop;

    

    if(grid[startPos.y][startPos.x] == WALL || grid[finishPos.y][finishPos.x] == WALL)
    {
        return false; // one of the tiles is wall
    }

     //sharing a wave
    d = 0;
    grid[startPos.y][startPos.x] = 0; // mark the start point as 0

    do
    {
        stop = true; //assuming all free tiles are marked

        for( y = 0; y < H; ++y)
            for(x = 0; x < W; ++x)
                if(grid[y][x] == d) //if tile marked as d
                {
                   for( k = 0; k < 4; ++k) // checking all nonmarked neigbours 
                    {
                        int iy = y + dy[k], ix = x + dx[k];

                        if( iy >= 0 && iy < H && ix >= 0 && ix < W && grid[iy][ix] == BLANK)
                        {
                            stop = false; //found non-marked tiles
                            grid[iy][ix] = d + 1;
                        }        
                    } 
                }
        d++;        

    }while(!stop && grid[finishPos.y][finishPos.x] == BLANK); // path is not found
    
    //setting the path
    len = grid[finishPos.y][finishPos.x]; // length of the shortest path

    x = finishPos.x;
    y = finishPos.y;
    d = len;
    while(d > 0)
    {
        px[d] = x;
        py[d] = y; //adding tile (x,y) to the path

        d--;
        for( k = 0; k < 4; ++k)
        {
           int iy = y + dy[k], ix = x + dx[k];
           if( iy >= 0 && iy < H && ix >= 0 && ix < W && grid[iy][ix] == d)
           {
               x = x + dx[k];
               y = y + dy[k]; // moving towards start on 1 tile

               break;
           } 
        }
    }
    px[0] = startPos.x;
    py[0] = startPos.y;

    
    px.resize(len + 1);
    py.resize(len + 1);
  
    return true;
};



void tileMap::sortTowerTiles()
{
    const int TOWERTILE = 3;
    const int PATHTILE = 2;
    

   

    int dx[12] = {-1, 0, 1, -2, -2, -2, -1, 0, 1, 2, 2, 2};
    int dy[12] = {-2, -2, -2, 1, 0, -1, 2, 2, 2, 1, 0, -1}; 

    int x,y,k,t;

    for(y = 0; y < H; ++y)
        for(x = 0; x < W; ++x)
        {
            if(tileArray[y][x] == TOWERTILE)
            {
                towerTile ttile;
                ttile.effRate = 0;
                ttile.coordinates.y = y;
                ttile.coordinates.x = x;
                ttile.tile_isSelected = false;
                for(k = 0; k < 12; ++k)
                {
                    
                    int iy = y + dy[k], ix = x + dx[k];

                    if(tileArray[iy][ix] == PATHTILE)
                    {
                         for(int t = 0; t < px.size(); t++)
                        {
                             if(iy == py[t] && ix == px[t])
                             {
                                
                                ttile.effRate++;// increasing efficiency rate of the towerTile
                             }
                         }    
                    }
                }

                towerTileList.push_back(ttile);
            }
        }
    std::sort(towerTileList.begin(), towerTileList.end());    
    
}







