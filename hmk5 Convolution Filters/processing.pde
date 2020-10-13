PImage photo;
int w = 360;

// My given matrix
float[][] matrix = { { -1, -1, 0 },
                     { 0,  9, 0 },
                     { 0, -1, -1 } }; 

void setup() {
  size(800, 980);
  photo = loadImage("profile.PNG"); 
}

void draw() {
  //Drawing photo with certain orgin standards. Delta is the factor that can manipulate the ssize of the convolution 
  image(photo, 0, 0);
  int delta = 2;
  
  // Calculate the change of the rectangles
  int lengthOfRec = constrain(mouseX - w/delta, 0, photo.width);
  int widthOfRec = constrain(mouseY - w/delta, 0, photo.height);
  int lengthOfRec_Delta = constrain(mouseX + w/delta, 0, photo.width);
  int widthOfRec_Delta = constrain(mouseY + w/delta, 0, photo.height);
  int matrixsize = 3;
  loadPixels();
  // Begin our loop for every pixel in the smaller image
  for (int x = lengthOfRec; x < lengthOfRec_Delta; x++) {
    for (int y = widthOfRec; y < widthOfRec_Delta; y++ ) {
      color c = convolution(x, y, matrix, matrixsize, photo);
      int loc = x + y*photo.width;
      pixels[loc] = c;
    }
  }
  updatePixels();
}

color convolution(int x, int y, float[][] matrix, int matrixsize, PImage photo)
{
  float r = 0.0;
  float  g = 0.0;
  float  b = 0.0;
  int offset = matrixsize / 2;
  for (int i = 0; i < matrixsize; i++){
    for (int j= 0; j < matrixsize; j++){
      // Pixel Location!! Lets check it 
      int xloc = x+i-offset;
      int yloc = y+j-offset;
      int loc = xloc + photo.width*yloc;
      // Stay in the boundries 
      loc = constrain(loc,0,photo.pixels.length-1);
      // Calculate the convolution
      r += (red(photo.pixels[loc]) * matrix[i][j]);
       g += (green(photo.pixels[loc]) * matrix[i][j]);
       b += (blue(photo.pixels[loc]) * matrix[i][j]);
    }
  }
  // Define color limits 
  // Red is 200 for the cyan affect. 255 wouldbe white and 0s accross would be 0s etc 
  r = constrain( r, 0, 200);
   g = constrain( g, 0, 255);
   b = constrain( b, 0, 255);
  // return the color output
  return color( r,  g,  b);
}

