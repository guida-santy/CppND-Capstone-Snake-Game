#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "human.h"
class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  void HandleFoodPosition(bool  &running, Human &human) const;
 private:

    template <typename T>
  void ChangeDirection(T &animal, typename T::Direction input,
                       typename T::Direction opposite) const;
};

#endif