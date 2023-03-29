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


void Object::setFont(TTF_Font* font)
{
    this->font = font;
}
void Object::loadFromeRenderText(string textureText, SDL_Color textColor)
{
    if( this->texture != NULL )
	{
		SDL_DestroyTexture( this->texture );
		this->texture = NULL;
	}
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( this->font, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
       this->texture = SDL_CreateTextureFromSurface( this->renderer, textSurface );
		if( this->texture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			this->dst.w = textSurface->w;
		    this->dst.h = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

}