#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include <cmath>

template<typename T>
void Controller::ChangeDirection(T &animal, typename T::Direction input,
                                 typename T::Direction opposite) const {
    if (animal.direction != opposite || animal.size == 1) animal.direction = input;
    return;
}


void Controller::HandleInput(bool &running, Snake &snake) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    ChangeDirection(snake, Snake::Direction::kUp,
                                    Snake::Direction::kDown);
                    break;

                case SDLK_DOWN:
                    ChangeDirection(snake, Snake::Direction::kDown,
                                    Snake::Direction::kUp);
                    break;

                case SDLK_LEFT:
                    ChangeDirection(snake, Snake::Direction::kLeft,
                                    Snake::Direction::kRight);
                    break;

                case SDLK_RIGHT:
                    ChangeDirection(snake, Snake::Direction::kRight,
                                    Snake::Direction::kLeft);
                    break;
            }
        }
    }
}
double DistanceBetweenTwoPoints(SDL_Point p1, SDL_Point p2){
    return sqrt(pow(p1.x - p2.x, 2) +
                pow(p1.y - p2.y, 2));

}
void Controller::HandleFoodPosition(bool &running, Human &human) const {
    SDL_Event e;
    if (e.type == SDL_QUIT) {
        running = false;
        return;
    }

    if (round(human.head_x) != human.GetFoodLocation().x) {
        human.direction = Human::Direction::kLeft;

    } else {

        // Make human "smarter" by calculating if it's faster to go up or down given its' and food's positions
            SDL_Point aux {static_cast<int>(human.head_x), static_cast<int>(human.head_y)};
            auto dist_human_food = DistanceBetweenTwoPoints(aux,human.GetFoodLocation());

            SDL_Point down{human.GetFoodLocation().x,human.GetGridHeight()};
            auto dist_human_down = DistanceBetweenTwoPoints(aux,down);
            auto dist_food_down = DistanceBetweenTwoPoints(human.GetFoodLocation(),down);

            SDL_Point up{human.GetFoodLocation().x,0};
            auto dist_food_up = DistanceBetweenTwoPoints(human.GetFoodLocation(),up);
            auto dist_human_up = DistanceBetweenTwoPoints(aux,up);



        if ((dist_human_food <= dist_human_down + dist_food_up && human.head_y > human.GetFoodLocation().y) ||
                (dist_human_food >= dist_human_up + dist_food_down && human.head_y < human.GetFoodLocation().y )) {
                ChangeDirection(human, Human::Direction::kUp, Human::Direction::kDown);
            } else {
                ChangeDirection(human, Human::Direction::kDown, Human::Direction::kUp);
            }
    }


}