#include "Bitmap.h"


Bitmap::Bitmap()
{

}

Bitmap::Bitmap(const char * fname)
{
	std::ifstream fin(fname, std::ios_base::binary);
	if (!fin)
	{
		std::cerr << "Can not open the file \"" << fname << "\"." << std::endl;
		return;
	}
	fin.read((char*)&fileHeader, sizeof(fileHeader));
	if (fileHeader.fileType != 0x4D42)
	{
		std::cerr << "The file \"" << fname << "\" is not .BMP file." << std::endl;
		return;
	}
	fin.read((char*)&infoHeader, sizeof(infoHeader));
	if (infoHeader.bitCount == 32) {
		fin.read((char*)&colorHeader, sizeof(colorHeader));
	}
	fin.seekg(fileHeader.offsetData, fin.beg);
	switch (infoHeader.bitCount)
	{
	case 24:
		data = new RGBColor[infoHeader.imageSize / 3];
		break;
	case 32:
		data = new RGBAColor[infoHeader.imageSize / 4];
		break;
	}
	fin.read((char*)data, infoHeader.imageSize);
}

Bitmap::Bitmap(int32_t height, int32_t width, uint16_t bitCount, RGBColor* pixelData)
{
	infoHeader.height = height;
	infoHeader.width = width;

	assert(bitCount == 24 || bitCount == 32);
	infoHeader.bitCount = bitCount;
	int size = height * width;
	fileHeader.fileSize = size*(bitCount/8) + fileHeader.offsetData;
	infoHeader.size = sizeof(BMPInfoHeader);
	infoHeader.imageSize = size*(bitCount/8);
	switch (infoHeader.bitCount)
	{
	case 24:
		data = new RGBColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
		break;
	case 32:
		data = new RGBAColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);
		break;
	}
	for (int i = 0; i < size; i++)
	{
		data[i] = pixelData[i];
	}
	
}

Bitmap::Bitmap(int32_t height, int32_t width, uint16_t bitCount, const RGBColor & color)
{
	infoHeader.height = height;
	infoHeader.width = width;

	assert(bitCount == 24 || bitCount == 32);
	infoHeader.bitCount = bitCount;
	int size = height * width;
	fileHeader.fileSize = size * (bitCount / 8) + fileHeader.offsetData;
	infoHeader.size = sizeof(BMPInfoHeader);
	infoHeader.imageSize = size * (bitCount / 8);
	switch (infoHeader.bitCount)
	{
	case 24:
		data = new RGBColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
		break;
	case 32:
		data = new RGBAColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);
		break;
	}
	for (int i = 0; i < size; i++)
	{
		data[i] = color;
	}

}


Bitmap::~Bitmap()
{
	if (data) delete[] data;
}

RGBColor & Bitmap::GetPixel(int32_t x, int32_t y)
{
	uint32_t index = x * infoHeader.height + y;
	if (index < infoHeader.imageSize / 3) return data[index];
	else throw std::out_of_range("There is no such pixel with these coordinates"); 

}

void Bitmap::Read(const char *fname) {
	if (data) delete[] data;
	std::ifstream fin(fname, std::ios_base::binary);
	if (!fin)
	{
		std::cerr << "Can not open the file \"" << fname << "\"." << std::endl;
		return;
	}
	fin.read((char*)&fileHeader, sizeof(fileHeader));
	if (fileHeader.fileType != 0x4D42)
	{
		std::cerr << "The file \"" << fname << "\" is not .BMP file." << std::endl;
		return;
	}
	fin.read((char*)&infoHeader, sizeof(infoHeader));
	if (infoHeader.bitCount == 32) {
		fin.read((char*)&colorHeader, sizeof(colorHeader));
	}
	fin.seekg(fileHeader.offsetData, fin.beg);

	switch (infoHeader.bitCount)
	{
	case 24:
		data = new RGBColor[infoHeader.imageSize];
		break;
	case 32:
		data = new RGBAColor[infoHeader.imageSize];
		break;
	}	
	fin.read((char*)data, infoHeader.imageSize);

}

void Bitmap::Write(const char * fname)const
{
	std::ofstream fout(fname, std::ios_base::binary);
	if (!fout)
	{
		std::cerr << "Can not open/create the file \"" << fname << "\"." << std::endl;
		return;
	}
	fout.write((const char*)&fileHeader, sizeof(fileHeader));
	fout.write((const char*)&infoHeader, sizeof(infoHeader));
	if (infoHeader.bitCount == 32) {
		fout.write((const char*)&colorHeader, sizeof(colorHeader));
	}
	fout.write((const char*)data, infoHeader.imageSize);
}

void Bitmap::Create(int32_t height, int32_t width, uint16_t bitCount, RGBColor * pixelData)
{
	if (data) delete[] data;
	infoHeader.height = height;
	infoHeader.width = width;

	assert(bitCount == 24 || bitCount == 32);
	infoHeader.bitCount = bitCount;
	int size = height * width;
	fileHeader.fileSize = size * (bitCount / 8) + fileHeader.offsetData;
	infoHeader.size = sizeof(BMPInfoHeader);
	infoHeader.imageSize = size * (bitCount / 8);
	switch (infoHeader.bitCount)
	{
	case 24:
		data = new RGBColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
		break;
	case 32:
		data = new RGBAColor[size];
		fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);
		break;
	}
	for (int i = 0; i < size; i++)
	{
		data[i] = pixelData[i];
	}

}
