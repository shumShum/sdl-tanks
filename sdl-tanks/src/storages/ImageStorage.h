#ifndef __sdl_tanks__ImageStorage__
#define __sdl_tanks__ImageStorage__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

enum {
    BACKGROUND_STARTUP,
    BACKGROUND_PLAYING
};

class ImageStorage {
private:
    static SDL_Surface* images[30];
    
public:
    ImageStorage();
    
public:
    static SDL_Surface* get_texture(int texture_id);
};

#endif
