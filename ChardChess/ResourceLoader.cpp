# include "ResourceLoader.hpp"

void LoadFonts() {

	FontAsset::Register(L"LARGE", 45, Typeface::Black);

}

void LoadResources() {

	LoadFonts();

}