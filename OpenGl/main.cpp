#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#pragma warning(disable : 4996)

GLubyte* FBuffer;
int Width, Height;


char file[] = "Rectangle.ppm";


void ReadPPM(char* PPMfileName) // Doesn't read ascii ppm files (P3) yet
{
    // LOAD FROM A BINARY .PPM FILE  
    int Color;
    int NumComponents;
    char Buffer[100];
    FILE* FilePtr = fopen(PPMfileName, "rb");
    
    if (FilePtr == NULL)
    {
        fprintf(stderr, "ERROR: unable to open %s!\n", PPMfileName); exit(1);
    }
    fgets(Buffer, 99, FilePtr);
    if (Buffer[0] != 'P' || Buffer[1] != '6')
    {
        fprintf(stderr, "Not a binary ppm file: %s\n", PPMfileName); exit(1);
    }
    if (Buffer[2] == 'A')
        NumComponents = 4;
    else
        NumComponents = 3;

    Buffer[0] = getc(FilePtr);
    while (Buffer[0] == '#' || Buffer[0] == '\n')
    {
        ungetc(Buffer[0], FilePtr);
        fgets(Buffer, 99, FilePtr);
        Buffer[0] = getc(FilePtr);
    }

    ungetc(Buffer[0], FilePtr);

    fscanf(FilePtr, "%d %d %d\n", &Width, &Height, &Color);
    if (Color != 255)
    {
        fprintf(stderr, "File does not have True color?\n"); exit(1);
    }
    printf("Reading %dx%d image (%d Component) from [%s]. . .\n",
        Width, Height, NumComponents, PPMfileName);

    int LineWidth = Width * NumComponents;

    GLubyte* fBuffer = new GLubyte[Height * LineWidth];

    FBuffer = fBuffer;
    fBuffer += (Height * LineWidth - LineWidth); // Help the compiler optimize

    for (int i = Height; i > 0; i--)
    { // Have to read in reverse for OpenGL windows.
        fread(fBuffer, LineWidth, 1, FilePtr); // Let File buffer manage disk access
        fBuffer -= LineWidth;
    }
    fclose(FilePtr);

    return;
}

void Quit()
{
    delete[] FBuffer;
    exit(1);
}

void KeyBoardHandler(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        Quit();
}

void Reshape(int w, int h)
{

    // set dimensionsos of the view 
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);

    // load the perpindicular plane boundries 
    glPixelZoom((GLfloat)w / Width, (GLfloat)h / Height);
    // cleare the bits for when I reuse this function 
    glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Just to be sure
    //glRasterPos2i(0, glutGet(GLUT_WINDOW_HEIGHT)); // Just to be sure

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, FBuffer);
}

void Init(int argc, char* argv[])
{

    if (4 < 2) { printf("No ppm File Specified\n"); exit(1); }

    ReadPPM(file);
    printf("read ppm is done");

    glutInit(&argc, argv);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Sola's PPM Viewer");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutDisplayFunc(display);
    glutKeyboardFunc(KeyBoardHandler);
    glutReshapeFunc(Reshape);
}

//char file[] = { "R","e","c","t","a","n","g","l","e",".","p","p","m" };

int main(int argc, char* argv[])
{
    Init(argc, argv);

    glutMainLoop();
}