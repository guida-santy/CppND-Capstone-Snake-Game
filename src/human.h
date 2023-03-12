#ifndef SDL2TEST_HUMAN_H
#define SDL2TEST_HUMAN_H

#include <vector>
#include "SDL.h"


class Human {
public:
    enum class Direction {
        kUp, kDown, kLeft, kRight
    };

    explicit Human(int grid_width, int grid_height, SDL_Point food_loc) :
            grid_width(grid_width),
            grid_height(grid_height),
            head_x(grid_width / 2),
            head_y(grid_height),
            _food_loc{food_loc} {}

    void Update();

    void GrowBody();

    bool HumanCell(int x, int y);

    Direction direction = Direction::kLeft;

    float speed{0.1f};
    int size{1};
    bool alive{true};
    float head_x;
    float head_y;
    std::vector<SDL_Point> body;

    void SetFoodLocation(SDL_Point loc){
        _food_loc = loc;
    };

    SDL_Point GetFoodLocation(){
        return _food_loc;
    };

    int GetGridHeight(){
        return grid_height;
    };

private:
    void UpdateHead();

    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

    bool growing{false};
    int grid_width;
    int grid_height;
    SDL_Point _food_loc;
};


#endif //SDL2TEST_HUMAN_H
