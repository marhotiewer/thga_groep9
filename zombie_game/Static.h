#ifndef STATIC_H
#define STATIC_H

#include "AssetManager.h"
#include "Drawable.h"

class Static : public Drawable
{
	public:
		Static(AssetManager& assets) : Drawable(assets) {}
};

#endif
