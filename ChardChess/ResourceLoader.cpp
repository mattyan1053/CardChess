# include "ResourceLoader.hpp"

void LoadFonts() {

	FontAsset::Register(L"TITLE", 25, Typeface::Default);
	FontAsset::Register(L"ITEMNAME", 15, Typeface::Black);
	FontAsset::Register(L"COST", 20, Typeface::Bold);
	FontAsset::Register(L"INFO", 12, Typeface::Default);
	FontAsset::Register(L"INFOTITLE", 15, Typeface::Bold);
	FontAsset::Register(L"LOG", 10, Typeface::Default);
	FontAsset::Register(L"COST", 40, Typeface::Black);
	FontAsset::Register(L"LARGE", 45, Typeface::Black);
	FontAsset::Register(L"BIG", 120, Typeface::Black);
	FontAsset::Register(L"UP1", 17, Typeface::Black);

}

void LoadPictures() {

	TextureAsset::Register(L"BACK", L"/1000");
	TextureAsset::Register(L"TITLE", L"/1001");
	TextureAsset::Register(L"RESULT", L"/1002");
	TextureAsset::Register(L"WINNER", L"/1003");

}

void LoadResources() {

	LoadFonts();
	LoadPictures();

}