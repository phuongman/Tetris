#include "header/object.hpp"

Object::Object()
{
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

void Object::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Object::setDst(SDL_Rect dst)
{
    this->dst = dst;
}
void Object::loadTexture(const char* path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(this->renderer, path);
    if(texture == NULL)
    {
        cout << "can't not create texture " << path << endl;
    }
    else 
    {

        SDL_QueryTexture(texture, NULL, NULL, &this->dst.w, &this->dst.h);
    }
    this->texture = texture;
}

void Object::draw()
{
    SDL_RenderCopy(this->renderer, this->texture, NULL, &this->dst);

}