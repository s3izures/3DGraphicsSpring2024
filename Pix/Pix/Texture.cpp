#include "Texture.h"

namespace
{
#pragma pack(push, 1)
    struct BitmapFileHeader
    {
        uint16_t type;          // magic identifier
        uint32_t size;          // file size in bytes
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;        // byte offset to image data
    };

    struct BitmapInfoHeader
    {
        uint32_t size;                  // header size in bytes
        int width, height;              // width and height of the image
        uint16_t planes;                // number of color planes
        uint16_t bits;                  // bits per pixel
        uint32_t compression;           // compression type
        uint32_t imageSize;             // image size in bytes
        int xResolution, yResolution;   // pixels per meter
        uint32_t numColors;             // number of colors
        uint32_t importantColors;       // important colors
    };

    uint32_t MakeStringAligned(uint32_t rowStride, uint32_t alignStride)
    {
        uint32_t newStride = rowStride;
        while (newStride % alignStride != 0)
        {
            newStride++;
        }

        return newStride;
    }
#pragma pack(pop)
}

void Texture::Load(const std::string& fileName)
{
	mFileName = fileName;

	FILE* file = nullptr;
	fopen_s(&file, fileName.c_str(), "rb");
	if (file == nullptr)
	{
		return;
	}

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    fread(&fileHeader, sizeof(fileHeader), 1, file);
    fread(&infoHeader, sizeof(infoHeader), 1, file);

    if (infoHeader.bits != 24)
    {
        fclose(file);
        return;
    }

    mWidth = infoHeader.width;
    mHeight = infoHeader.height;
    mPixels = std::make_unique<X::Color[]>(mWidth * mHeight);

    fseek(file, fileHeader.offset, SEEK_SET);

    uint32_t rowStride = mWidth * infoHeader.bits / 8;
    uint32_t paddedStride = MakeStringAligned(rowStride, 4);
    std::vector<uint8_t> paddedBytes(paddedStride - rowStride);
    for (int h = 0; h < mHeight; ++h)
    {
        for (int w = 0; w < mWidth; ++w)
        {
            uint8_t r, g, b;
            fread(&b, sizeof(uint8_t), 1, file);
            fread(&g, sizeof(uint8_t), 1, file);
            fread(&r, sizeof(uint8_t), 1, file);
            uint32_t index = w + ((mHeight - h - 1) * mWidth);
            mPixels[index] = { r / 255.0f,g / 255.0f,b / 255.0f , 1.0f};
        }

        fread((char*)paddedBytes.data(), paddedBytes.size(), 1, file);
    }
    fclose(file);
}
const std::string& Texture:: GetFileName() const
{
	return mFileName;
}
X::Color Texture::GetPixel(float u, float v, AddressMode mode, bool filter) const
{
	int uIn = static_cast<int>(u * (mWidth - 1));
	int vIn = static_cast<int>(v * (mHeight - 1));
	return GetPixel(uIn, vIn);
}
X::Color Texture::GetPixel(int x, int y) const
{
	x = std::clamp(x, 0, mWidth - 1);
	y = std::clamp(y, 0, mHeight - 1);
	return mPixels[(x + (y * mWidth))];
}
int Texture::GetWidth() const
{
	return mWidth;
}
int Texture::GetHeight() const
{
	return mHeight;
}