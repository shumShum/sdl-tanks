#include "ImageStorage.h"

SDL_Surface* ImageStorage::images[30] = { [0 ... 29] = NULL};

SDL_Surface* ImageStorage::get_texture(int texture_id)
{
    SDL_Surface* img;
    if (images[texture_id] == NULL) images[texture_id] = IMG_Load("bg_intro.jpg");
    img = images[texture_id];
        
    return img;
}
