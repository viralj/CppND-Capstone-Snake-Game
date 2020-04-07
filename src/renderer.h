#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();
  Renderer(const Renderer &chatbot) noexcept;
  Renderer& operator=(const Renderer &chatbot) noexcept;
  Renderer(Renderer &&chatbot);
  Renderer& operator=(Renderer &&chatbot);

  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &life, SDL_Point const &double_food);
  void UpdateWindowTitle(int score, int fps, int lives);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif