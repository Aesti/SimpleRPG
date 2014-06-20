#define SDL2_RENDERER_DEF

#ifdef SDL2_RENDERER_DEF 
#include "SDL_Image.h"
#include <SDL2/SDL.h>
#endif

#include <string>

class RenderContext {
public:
  #ifdef SDL2_RENDERER_DEF
  RenderContext(std::string title, int xpos, int ypos, int width, int height, int flags);
  #endif 
  ~RenderContext();

  void clear();
  void render();
  void draw_image(std::string res, int x, int y);

private:
  #ifdef SDL2_RENDERER_DEF
  SDL_Renderer *m_renderer;
  SDL_Window *m_window;
  #endif
};