# include "ResourceLoader.hpp"

void LoadFonts() {

	FontAsset::Register(L"LARGE", 45, Typeface::Black);
	FontAsset::Register(L"ITEMNAME", 15, Typeface::Black);

}

void LoadResources() {

	LoadFonts();

}