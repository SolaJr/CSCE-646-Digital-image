// Sola Babatunde ( with influence from Dr Ankleman's Digital Image class ) 

#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

#include <fstream>
#include <cassert>
#include <sstream>
#include <string>

#pragma warning(disable : 4996)

using namespace std;

// =============================================================================
// These variables will store the input ppm image's width, height, and color
// =============================================================================
int width, height, maxVal, pixelSize; //Image characteristics from ppm file
unsigned char* pixmap;
char filename[] = "Rectangle.ppm";



// =============================================================================
// setPixels()
//
// This function stores the RGB values of each pixel to "pixmap."
// Then, "glutDisplayFunc" below will use pixmap to display the pixel colors.
// =============================================================================
void setPixels()
{/*
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int i = (y * width + x) * 3;
			pixmap[i++] = 255;
			pixmap[i++] = 0xFF; //Do you know what "0xFF" represents? Google it!
			pixmap[i] = 0x00; //Learn to use the "0x" notation to your advantage.
		}
	}*/
	FILE* inFile; //File pointer
	char buffer[100]; //Input buffer
	GLubyte* theTexture; //Texture buffer pointer
	unsigned char c; //Input character
	int width, height, maxVal, pixelSize; //Image characteristics from ppm file


	//Try to open the file for reading
	if ((inFile = fopen(filename, "rb")) == NULL) {
		fprintf(stderr, "cannot open %s\n", filename);
		exit(-1);
	}

	//Read file type identifier (magic number)
	fgets(buffer, sizeof(buffer), inFile);
	if ((buffer[0] != 'P') || (buffer[1] != '6')) {
		fprintf(stderr, "not a binary ppm file %s\n", filename);
		exit(-1);
	}

	if (buffer[2] == 'A')
		pixelSize = 4;
	else
		pixelSize = 3;

	//Read image size
	do fgets(buffer, sizeof(buffer), inFile);
	while (buffer[0] == '#');
	sscanf(buffer, "%d %d", &width, &height);

	//Read maximum pixel value (usually 255)
	do fgets(buffer, sizeof(buffer), inFile);
	while (buffer[0] == '#');
	sscanf(buffer, "%d", &maxVal);

	//Allocate RGBA texture buffer
	int memSize = width * height * 4 * sizeof(GLubyte);
	pixmap= (GLubyte*)malloc(memSize);

	// read RGB data and set alpha value
	for (int i = 0; i < memSize; i++) {
		if ((i % 4) < 3 || pixelSize == 4) {
			c = fgetc(inFile);
			pixmap[i] = (GLubyte)c;
		}
		else pixmap[i] = (GLubyte)255; //Set alpha to opaque
	}
	fclose(inFile);

}



// =============================================================================
// OpenGL Display and Mouse Processing Functions.
//
// You can read up on OpenGL and modify these functions, as well as the commands
// in main(), to perform more sophisticated display or GUI behavior. This code
// will service the bare minimum display needs for most assignments.
// =============================================================================
static void windowResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, (w / 2), 0, (h / 2), 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
static void windowDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixmap);
	glFlush();
}
static void processMouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
		exit(0);               // Exit on mouse click.
}
static void init(void)
{
	glClearColor(1, 1, 1, 1); // Set background color.
}

// =============================================================================
// main() Program Entry
// =============================================================================
int main(int argc, char* argv[])
{

	//initialize the global variables
	width = 2240;
	height = 2000;
	pixmap = new unsigned char[width * height * 3];  //Do you know why "3" is used?

	setPixels();


	// OpenGL Commands:
	// Once "glutMainLoop" is executed, the program loops indefinitely to all
	// glut functions.  
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100); // Where the window will display on-screen.
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Homework Zero");
	init();
	glutReshapeFunc(windowResize);
	glutDisplayFunc(windowDisplay);
	glutMouseFunc(processMouse);
	glutMainLoop();

	return 0; //This line never gets reached. We use it because "main" is type int.
}

/*#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}*/
