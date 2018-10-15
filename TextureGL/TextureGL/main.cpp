#include "stb_image.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "texture_gl.h"
using namespace std;
int main() {
	//int width, height, nrComponents;
	//nsigned char *data = stbi_load("x.png", &width, &height, &nrComponents, 0);
	TextureGL texture("x.png");
	texture.SaveImageAsPng("y");
	
	//stbi_image_free(data);
	return 0;
}