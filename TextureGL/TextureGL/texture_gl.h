#ifndef TEXTURE_GL_H
#define TEXTURE_GL_H
#include "stb_image.h"
#include "stb_image_write.h"
#include <string>
#include <iostream>
struct Color {
	float r;
	float g;
	float b;
};

class TextureGL {
private:
	unsigned char *data;
	int width;
	int height;
	int numComponents;
public:
	TextureGL(const char *filename) {
		this->data = stbi_load(filename, &this->width, &this->height, &this->numComponents, 0);
		if (!data) {
			std::cout << "Load image " << filename << " faile." << std::endl;
		}
	}

	Color GetColor(int w, int h) {
		Color res;
		res.r = data[(h*width + w) * numComponents];
		res.g = data[(h*width + w) * numComponents + 1];
		res.b = data[(h*width + w) * numComponents + 2];
		res.r /= 255.0f;
		res.g /= 255.0f;
		res.b /= 255.0f;
		return res;
	}

	Color GetColor(float u, float v) {
		int w = width * u;
		int h = height * v;
		return GetColor(w, h);
	}

	unsigned int GetWidth() { return this->width; }

	unsigned int GetHeight() { return this->height; }

	void SetColor(int w, int h, Color color) {
		data[(h*width + w) * numComponents] = 255 * color.r;
		data[(h*width + w) * numComponents + 1] = 255 * color.g;
		data[(h*width + w) * numComponents + 2] = 255 * color.b;
	}

	int SaveImageAsPng(std::string filename) {
		filename += ".png";
		return stbi_write_png(filename.c_str(), this->width, this->height,
			this->numComponents, &(this->data[0]), 0);
	}

	~TextureGL() {
		stbi_image_free(this->data);
	}
};
#endif