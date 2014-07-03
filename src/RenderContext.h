#pragma once 

#define SDL2_RENDERER_DEF

#ifdef SDL2_RENDERER_DEF 
#include "SDL_Image.h"
#include <SDL2/SDL.h>

typedef SDL_Rect RECT;
typedef SDL_Texture TEXTURE;
typedef SDL_Point POINT;
#endif

#include <string>
#include <map>

struct TextureDesc
{
  TEXTURE *texture;
  RECT rect;

  TextureDesc(TEXTURE *t, RECT r)
  : texture(t), rect(r) {}
  TextureDesc() : texture(nullptr), rect(RECT()) {}
};

class RenderContext {
public:
  RenderContext(std::string title, int xpos, int ypos, int width, int height, int flags);
  RenderContext();
  ~RenderContext();

  void checkFS(bool isFullscreen);

  void clear();
  void render();
  void load_image(std::string file, std::string id);
  void draw_image(std::string id, int x, int y);
  std::map<std::string, TextureDesc> m_textureMap;

  int wWidth = 0;
  int wHeight = 0;
  bool isFullscreen = false;

private:
  #ifdef SDL2_RENDERER_DEF
  SDL_Renderer *m_renderer;
  SDL_Window *m_window;
  #endif
};

