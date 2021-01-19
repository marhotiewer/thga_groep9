#ifndef STATIC_H
#define STATIC_H

#include "AssetManager.h"
#include "Drawable.h"
/// @file


/// \class Static
/// \brief
/// Class for the Static items
/// \details
/// The Static class inhert from the Drawable class.
/// This class is used to inhert from static items (items that can not move) like Floor or Wall.
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
