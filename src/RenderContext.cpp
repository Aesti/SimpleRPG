#include "RenderContext.h"

#ifdef SDL2_RENDERER_DEF
RenderContext::RenderContext(std::string title, int xpos, int ypos, int width, int height, int flags) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return;
  }
  m_window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);

  if (m_window == nullptr) {
    SDL_Quit();
    return;
  }
  
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

RenderContext::~RenderContext() {
  SDL_DestroyRenderer(m_renderer);
}
#endif

void RenderContext::clear() {
  #ifdef SDL2_RENDERER_DEF
  SDL_RenderClear(m_renderer);
  #endif
}

void RenderContext::render() {
  #ifdef SDL2_RENDERER_DEF
  SDL_RenderPresent(m_renderer);
  #endif
}