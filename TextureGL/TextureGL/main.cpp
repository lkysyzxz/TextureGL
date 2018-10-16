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
	cout << "R" << "\t" << "G" << "\t" << "B" << endl;
	Color color{ 0,1,0 };
	for (int h = 0;h< texture.GetHeight(); h++) {
		for (int w = 0;w< texture.GetWidth(); w++) {
			//Color color = texture.GetColor(w, h);
			//cout << color.r << "\t" << color.g << "\t" << color.b << endl;
			texture.SetColor(w, h, color);
		}
	}
	texture.SaveImageAsPng("water_bump.png");
	
	//stbi_image_free(data);
	return 0;
}