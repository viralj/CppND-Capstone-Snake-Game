#include "blockrenderer.h"
#include <iostream>
#include <string>

void BlockRenderer::Render(Snake const snake, SDL_Point const &food) {

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render Block 1
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &block1);

  // Render Block 2
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &block2);

  // Render Block 3
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &block3);

  // Render Block 4
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &block4);
  // Render food
  RenderFood(food);

  // Render snake's body
  RenderBody(snake);

  // Render snake's head
  RenderHead(snake);

  SDL_UpdateWindowSurface(sdl_window);

  SDL_RenderPresent(sdl_renderer);
}

bool BlockRenderer::collision(Snake snake) {

  if ((block.w * static_cast<int>(snake.head_x) > block1.x &&
       block.w * static_cast<int>(snake.head_x) <
           (block1.x + block1.w)) &&
      (block.h * static_cast<int>(snake.head_y) > block1.y &&
       block.h * static_cast<int>(snake.head_y) <
           (block1.y + block1.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > block2.x &&
       block.w * static_cast<int>(snake.head_x) <
           (block2.x + block2.w)) &&
      (block.h * static_cast<int>(snake.head_y) > block2.y &&
       block.h * static_cast<int>(snake.head_y) <
           (block2.y + block2.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > block3.x &&
       block.w * static_cast<int>(snake.head_x) <
           (block3.x + block3.w)) &&
      (block.h * static_cast<int>(snake.head_y) > block3.y &&
       block.h * static_cast<int>(snake.head_y) <
           (block3.y + block3.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > block4.x &&
       block.w * static_cast<int>(snake.head_x) <
           (block4.x + block4.w)) &&
      (block.h * static_cast<int>(snake.head_y) > block4.y &&
       block.h * static_cast<int>(snake.head_y) <
           (block4.y + block4.h))) {
    return true;
  }

  return false;
}

bool BlockRenderer::BlockCell(int x, int y) {

  if ((block.w * x >= block1.x &&
       block.w * x <= (block1.x + block1.w)) &&
      (block.h * y >= block1.y &&
       block.h * y <= (block1.y + block1.h))) {
    return true;
  }

  if ((block.w * x >= block2.x &&
       block.w * x <= (block2.x + block2.w)) &&
      (block.h * y >= block2.y &&
       block.h * y <= (block2.y + block2.h))) {
    return true;
  }

  if ((block.w * x >= block3.x &&
       block.w * x <= (block3.x + block3.w)) &&
      (block.h * y >= block3.y &&
       block.h * y <= (block3.y + block3.h))) {
    return true;
  }

  if ((block.w * x >= block4.x &&
       block.w * x <= (block4.x + block4.w)) &&
      (block.h * y >= block4.y &&
       block.h * y <= (block4.y + block4.h))) {
    return true;
  }

  return false;
}