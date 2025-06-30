
#include "Chunk.h"

// NOTE: Remove
#include <iostream>

Chunk::Chunk(sf::Texture& tileset, sf::Vector2f position, Grid room)
    : tile_sprite(sf::Sprite(tileset)), position(position), grid(room)
{
    //tile_sprite.setTextureRect(sf::IntRect({0, 0}, {16, 16}));
}


void Chunk::render(sf::RenderWindow& window)
{
    tile_sprite.setPosition(position);

    TileType tile;
    for (int i = 0; i < chunk_size * chunk_size; i++)
    {
        tile = grid.tiles[i];

        // NOTE: Find a more efficient way to draw environment?
        if (tile != TileType::Empty)
        {
            tile_sprite.setTextureRect(sf::IntRect({tile * tile_size, 0}, {tile_size, tile_size}));

            sf::Vector2f tile_position = sf::Vector2f(i % chunk_size, i / chunk_size);
            tile_position.x *= tile_size;
            tile_position.y *= tile_size;

            tile_sprite.setPosition(position + tile_position);
            window.draw(tile_sprite);
        }
    }
}


Chunk::TileType Chunk::get_tile(int x, int y)
{
    x = x >= chunk_size ? chunk_size - 1 : (x < 0 ? 0 : x);
    y = y >= chunk_size ? chunk_size - 1 : (y < 0 ? 0 : y);

    return grid.tiles[x + y * chunk_size];
}