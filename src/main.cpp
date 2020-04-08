#include "SDL2/SDL.h"
#include "controller.h"
#include "game.h"
#include "blockrenderer.h"
#include <iostream>
#include <stdio.h>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int level;

  SDL_Init(SDL_INIT_VIDEO);

  Controller controller;
  Game *game;
  BlockRenderer *renderer;

  renderer = new BlockRenderer(kScreenWidth, kScreenHeight, kGridWidth,
                                  kGridHeight);

  game = new Game(kGridWidth, kGridHeight, *renderer);
  game->Run(controller, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game->GetScore() << "\n";
  std::cout << "Size: " << game->GetSize() << "\n";

  delete renderer;
  delete game;

  return 0;
}