#define SDL2_RENDERER_DEF

#ifdef SDL2_RENDERER_DEF 
#include "SDL_Image.h"
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <string>
#include <map>

class RenderContext {
public:
  #ifdef SDL2_RENDERER_DEF
  RenderContext(std::string title, int xpos, int ypos, int width, int height, int flags);
  #endif 
  ~RenderContext();

  void clear();
  void render();
  void load_image(std::string file, std::string id);
  void draw_image(std::string id, int x, int y, int width, int height);
  std::map<std::string, SDL_Texture*> m_textureMap;


private:
  #ifdef SDL2_RENDERER_DEF
  SDL_Renderer *m_renderer;
  SDL_Window *m_window;
  #endif
};