#ifndef STATIC_H
#define STATIC_H

#include "AssetManager.h"
#include "Drawable.h"

/// \class Static
/// \brief
/// Class for the Static items
/// \details
/// The Static class inhert from the Drawable class.
class Static : public Drawable
{
	public:
		/// <summary>
		/// The static class need the AssetManager for textures
		/// </summary>
		/// <param name="AssetManager"></param>
		Static(AssetManager& assets) : Drawable(assets) { this->type = Type::Static; }
};

#endif
