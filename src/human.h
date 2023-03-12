#ifndef SDL2TEST_HUMAN_H
#define SDL2TEST_HUMAN_H

#include <vector>
#include "SDL.h"
#include "game.h"

class Game;

class Human {
public:
    enum class Direction {
        kUp, kDown, kLeft, kRight
    };

    explicit Human(int grid_width, int grid_height, Game &game) :
            grid_width(grid_width),
            grid_height(grid_height),
            head_x(0),
            head_y(grid_height),
            _game{&game} {}

    void Update();

    void GrowBody();

    bool HumanCell(int x, int y);

    Direction direction = Direction::kUp;

    float speed{0.1f};
    int size{1};
    bool alive{true};
    float head_x;
    float head_y;
    std::vector<SDL_Point> body;

private:
    void UpdateHead();

    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

    bool growing{false};
    int grid_width;
    int grid_height;
    Game *_game;
};


#endif //SDL2TEST_HUMAN_H
