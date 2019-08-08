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

	TextureAsset::Register(L"BACK", L"./ccslogo.png");
	TextureAsset::Register(L"TITLE", L"./title.png");
	TextureAsset::Register(L"RESULT", L"./result.png");
	TextureAsset::Register(L"WINNER", L"./winner.png");

}

void LoadResources() {

	LoadFonts();
	LoadPictures();

}