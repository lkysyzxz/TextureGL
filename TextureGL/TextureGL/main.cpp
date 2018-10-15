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
	TextureGL texture("water_bump.png");
	cout << "R" << "\t" << "G" << "\t" << "B" << endl;
	for (int h = 0;h< texture.GetHeight(); h++) {
		for (int w = 0;w< texture.GetWidth(); w++) {
			Color color = texture.GetColor(w, h);
			cout << color.r << "\t" << color.g << "\t" << color.b << endl;
		}
	}
	
	//stbi_image_free(data);
	return 0;
}