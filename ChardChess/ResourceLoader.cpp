# include "ResourceLoader.hpp"

void LoadFonts() {

	FontAsset::Register(L"LARGE", 45, Typeface::Black);
	FontAsset::Register(L"ITEMNAME", 15, Typeface::Black);
	FontAsset::Register(L"COST", 20, Typeface::Bold);
	FontAsset::Register(L"INFO", 12, Typeface::Default);
	FontAsset::Register(L"INFOTITLE", 15, Typeface::Bold);
	FontAsset::Register(L"LOG", 10, Typeface::Default);

}

void LoadResources() {

	LoadFonts();

}