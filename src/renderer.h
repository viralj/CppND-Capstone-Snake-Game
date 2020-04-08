#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "snake.h"
#include <vector>

class Renderer {
public:
  Renderer();
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void UpdateWindowTitle(int score, int fps);
  virtual void Render(Snake const, SDL_Point const &){};
  virtual bool collision(Snake){};
  virtual bool BlockCell(int, int){};

  SDL_Rect block1;
  SDL_Rect block2;
  SDL_Rect block3;
  SDL_Rect block4;

  SDL_Rect block;

protected:
  void RenderHead(Snake const);
  void RenderBody(Snake const);
  void RenderFood(SDL_Point const &);

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  int factor;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif