// helper to not have to do this in every file
#ifdef __APPLE__
  #include <SDL2_image/SDL_image.h>
  #include <SDL2_ttf/SDL_ttf.h>
#endif

#ifdef __linux__
  // Linux Includes Here
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_ttf.h>
#endif
