
#ifndef TOWERCREEP_CHUNK_H
#define TOWERCREEP_CHUNK_H

#include <SFML/Graphics.hpp>

class Chunk
{
public:
    enum TileType
    {
        Empty = -1,
        Full
    };
    static const int chunk_size = 16;
    static const int tile_size = 16;
    struct Grid
    {
        Grid()
        {
            for (int i = 0; i < chunk_size * chunk_size; i++)
            {
                tiles[i] = TileType::Empty;
            }
        }
        TileType tiles[chunk_size * chunk_size];
        int connections = 0; // NOTE: Not sure about putting this here but whatevs
    };

private:
    // Rendering
    sf::Sprite tile_sprite;

    // Data
    sf::Vector2f position;
    Grid grid;

public:
    Chunk(sf::Texture& tileset, sf::Vector2f position, Grid room);

    void render(sf::RenderWindow& window);

    TileType get_tile(int x, int y);
    
};

#endif // TOWERCREEP_CHUNK_H