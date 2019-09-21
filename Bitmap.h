#pragma once
#include <iostream>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <assert.h>
#pragma pack(push, 1)
struct BMPFileHeader
{
	uint16_t fileType{ 0x4D42 };  // file type, which must be "BM"
	uint32_t fileSize{ 0 };       // size of a file in bytes
	uint16_t reserved1{ 0 };
	uint16_t reserved2{ 0 };
	uint32_t offsetData{ 0 };     // start position of pixel data(bytes fron the beginning of a file
};

struct BMPInfoHeader
{
	uint32_t size{ 0 };
	int32_t height{ 0 };
	int32_t width{ 0 };

	uint16_t planes{ 1 };         // Must be 1          
	uint16_t bitCount{ 0 };       // In our case it is 24(RGB) of 32(RGBA)            
	uint32_t compression{ 0 };    // 0           
	uint32_t imageSize{ 0 };      // Image size in bytes

	// You don`t need these 4 last
	int32_t xPixelsPerMeter{ 0 };
	int32_t yPixelsPerMeter{ 0 };
	uint32_t usedColors{ 0 };
	uint32_t importantColors{ 0 };

};

struct BMPColorHeader {
	uint32_t redMask{ 0x00ff0000 };         // Bit mask for the red channel
	uint32_t greenMask{ 0x0000ff00 };
	uint32_t blueMask{ 0x000000ff };
	uint32_t alphaMask{ 0xff000000 };
	uint32_t colorSpaceType{ 0x73524742 };  // Default "sRGB" (0x73524742)
	uint32_t unused[16]{ 0 };               // Unused data for sRGB color space
};

struct RGBColor
{
	uint8_t r{ 0 }, g{ 0 }, b{ 0 };
	RGBColor operator*(double c) { return RGBColor{ (uint8_t)(r*c), (uint8_t)(g*c), (uint8_t)(b*c) }; }
	bool operator==(RGBColor other) {
		return r == other.r &&
			g == other.g &&
			b == other.b;
	}
};

struct RGBAColor : RGBColor
{
	uint8_t a{ 0 };
};
#pragma pack(pop)




class Bitmap
{
private:
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;
	BMPColorHeader colorHeader;
	RGBColor* data;
public:

	Bitmap();
	Bitmap(const char *fname);
	Bitmap(int32_t height, int32_t width, uint16_t bitCount, RGBColor* pixelData);
	Bitmap(int32_t height, int32_t width, uint16_t bitCount, const RGBColor& color);

	~Bitmap();

	int32_t Height()const { return infoHeader.height; }
	int32_t Width()const { return infoHeader.width; }

	RGBColor& GetPixel(int32_t x, int32_t y);
	void Read(const char *fname);
	void Write(const char *fname)const;
	void Create(int32_t height, int32_t width, uint16_t bitCount, RGBColor* pixelData);
};

