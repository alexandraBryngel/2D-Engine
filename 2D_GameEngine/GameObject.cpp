#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * texturesheet, SDL_Renderer * ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 32;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h*2;
	destRect.w = srcRect.w*2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
