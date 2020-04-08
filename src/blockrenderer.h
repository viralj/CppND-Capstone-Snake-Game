#ifndef RENDERER_LEVEL2_H
#define RENDERER_LEVEL2_H

#include "SDL.h"
#include "renderer.h"
#include "snake.h"
#include <vector>

class BlockRenderer : public Renderer {

public:
  BlockRenderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
      : Renderer(screen_width, screen_height, grid_width, grid_height) {

    block1.w = grid_width;
    block1.h = screen_height;
    block1.x = 0;
    block1.y = 0;

    block2.w = screen_width;
    block2.h = grid_width;
    block2.x = 0;
    block2.y = 0;

    block3.w = grid_width;
    block3.h = screen_height;
    block3.x = screen_width - grid_width;
    block3.y = 0;

    block4.w = screen_height;
    block4.h = grid_width;
    block4.x = 0;
    block4.y = screen_height - grid_height;
  }

  void Render(Snake const snake, SDL_Point const &food);
  bool collision(Snake);
  bool BlockCell(int, int);
};

#endif