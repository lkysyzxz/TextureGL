#ifndef TEXTURE_GL_H
#define TEXTURE_GL_H
#include "stb_image.h"
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
		this->data = (filename, &this->width, &this->height, &this->numComponents, 0);
		if (!data) {
			std::cout << "Load image " << filename << " faile." << std::endl;
		}
	}

	Color GetColor(int w, int h) {
		Color res;
		res.r = data[(w*width + h) * 3];
		res.g = data[(w*width + h) * 3+1];
		res.b = data[(w*width + h) * 3+2];
		return res;
	}

	Color GetColor(float u, float v) {
		int w = width * u;
		int h = height * v;
		return GetColor(w, h);
	}
	

	~TextureGL() {
		stbi_image_free(this->data);
	}
};
#endif