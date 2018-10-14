#include "stb_image.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "texture_gl.h"
using namespace std;
int main() {
	int width, height, nrComponents;
	unsigned char *data = stbi_load("x.png", &width, &height, &nrComponents, 0);
	string l((const char*)(data+ 1440000));
	if (data) {
		cout << "R" << "\t" << "G" << "\t" << "B"<<endl;
		//for (int i = 599; i < height; i++) {
		//	for (int j = 799; j < width; j++) {
		//		int R = data[(i*width + j)*3];
		//		int G = data[(i*width + j) * 3 +1];
		//		int B = data[(i*width + j) * 3 +2];
		//		//char A = data[(i*width + j) * 3 + 3];
		//		cout << R << "\t" << G << "\t" << B <<endl;
		//	}
		//}
		int R = data[(0 * width + 799) * 3];//255
		int G = data[(0 * width + 799) * 3 + 1];//255
		int B = data[(0 * width + 799) * 3 + 2];//255
		cout << R << "\t" << G << "\t" << B <<endl;
	}
	stbi_image_free(data);
	return 0;
}