# Digital Image Open GL / Web GL practice  
Some Digital Image Coding Projects on my journey to learn Web and Open Gl!

✅ - Complete ⌛ - Not online yet 
## Project 1 - Create-Display-Read & Write color images

### Part 1 - Make a program that can read & display an PPM image
✅
Tool used - Open GL ( C++ ) 
Folder name - OpenGL
Instructions - Simply download the file and run the Main.cpp file. 

### Part 2 - Make my own procedurally generated image 
Tool used - Open GL ( C++ ) 
Folder Name - OpenGL - Procedure 
Instructions - Run the file titled Hmk1.cpp. 

### Extra credit - I made the program also work in WebGL 
Tool used - WebGL ( Javascript )
Folder Name - Hmk 1 
Instructions - Just visit https://solajr.github.io/CSCE-646-Digital-image/hmk1/index or load it yourself. 

## Project 2 - 	Simple Vector to Raster Conversion and Antializing


Your program(s) should create at least one half-plane, one circle, a shape defined by a function in the form of f(x,y)<0. You can choose any color and any shape. We also want to see close-up images that demonstrate that the antialising is working. And as a fun little trick; I also made it so if you refresh the page, you can get a brand new color pallet for the Triangles! Their is a 1 out of 10000000000000000 chance you will make the red circles blue. Try your odds at luck!! 

Give it at try! 
Tool used - WebGL ( Javascript ) 
https://solajr.github.io/CSCE-646-Digital-image/WebGL-Hmk2/index.html

## Project 3 -Complex Vector to Raster Conversion 
✅

Your program(s) should create at least one convex, one star shape, one blobby shape and one shaded shape. In addition, create a height field image defined by a function in the form of y=f(x). You can choose any color and any shape. We also want to see close-up images that demonstrate that the antialising is working. My personal goal was to limit the number of files used on this one to JUST 1 SINGLE HTML FILE! 😲 

Give it a try! 
Tool used - WebGL ( Javascript / html ) 
https://solajr.github.io/CSCE-646-Digital-image/WebGL-Hmk3/index.html
## Project 4 -Image Manipulations
⌛

#### Main project 
Replace Hues in an image taking hues from another image. For the information about how to compute hues, see below.

#### Bonus 
Interface so you can control the value by entering a hex  

## Project 5 -Basic Convolution Filters
⌛

#### Part 1 
Convolution filter with Partition of Unity Property: These are fileters such blur or motion blur. In this case, coefficients of filter kernels add up to 1.
#### Part 2 
Derivative type Filters: These are filters when applied to a constant image gives 0. In this case, direct application of convolution filters can give you negative numbers. Therefore, in this case, we need to make one more conversion to obtain an image consists of colors, i.e. positive numbers.
#### Part 3
Morphological filters: Dilation and/or Erosion filter.
#### Bonus 
Bonus: Any additional work can give you bonus points up to half of the project credit. For instance, you can create Smart Blur or Bi-directional Low-Pass filter.


## Project 6 -Filtering with Non-stationary Kernels 
⌛
#### Part 1 
Convolution filter - Motion Blur. In this case the direction and the size of the motion blur will be controlled by a vector field. (A Simple way of creating a vector field is to use an image. For instance, red and green channels of an image can be converted into x,y by a simple linear transformation.). This will give you look of Line Integral Convolution.

#### Part 2
Morphological Non-Stationary filter - In this case the size and shape of the Dilation and/or Erosion filter will be controlled by another image.

#### Part 3
Bonus: Any additional work can give you bonus points up to half of the project credit. For instance, you can create Smart Blur or Bi-directional Low-Pass filter.

#### Part 1 

## Project 7 -Transforming and Warmping 
⌛

#### Part 1 
You will develop an affine transformation tool that uses 3x3 matrices to transform images.

## Project 8 -Compositing 
⌛

#### Part 1 
In this assignment you will develop operations for compositing and blue screening. The goal of this project is to learn how opacity/transparency is used to create aestetic results. These are the operations you can use for combining layers in Photoshop.

## Project 9 -Dithering & Screening 
⌛

#### Part 1 
You will develop a dithering tool that includes Error diffusion and Ordered Dither.

#### Bonus 
Any additional work can give you bonus points up to half of the project credit. For instance, you can create an interactive dithering using the camera of your PC.

## Project 10 -Sketching & Carving 
⌛

#### Part 1 
Image Recombination: A software that can seamlessly combine two similar images into one. Your algorithm will find the best seam that can go through both of the images. Using this seam, your program will combine the two images into one such that one side of the final image will come from first image and other side will come from second image.
#### Part 2 
Image Retargeting by Seam Carving: A software that can change the size of the image by removing least energy seams.

## Project 11 -2D Diffuse Shader
Tool - WebGL(Javascript) 
⌛
#### Part 1 - Chose the Lense Affect Project 
Video Processing: Turn one of your previous works into video processing. Your program must be able to take an few input videos, that can be given a set of images. From these videos, it will create a final video to be shown semester end show.
Diffuse (Lambertian) Illumination Shader: You will read a normal map image and illuminate it with a light source. You will only use basic shading with diffuse reflections. Shader will be described by two color texture images instead of single color: diffuse and ambient. You will make an animation by moving the light source direction or position.
Specular Highlight Shader: You will add specular highlights to your diffuse shader. Shader will be described by three color texture images instead of single color: diffuse, ambient and specular. You will make an animation by moving the light source direction or position.

## Project 12 -2D Reflection & Refraction Shader
### You will implement a simple global shader.
⌛

Tool - WebGL(Javascript) 
Reflection Shader: A normal map will reflect a foreground image. You will animate by moving texture.
Ref raction Shader: A normal map will refract a background image. You will animate by either moving texture or changing index of refraction.
Fresnel Shader: You will combine reflection and refraction using Fresnel.
For the required parts of the project, implement your operations only using the basic programming operations such as while or for loops and basic mathematical operations such as addition, subtraction, multiplication, division and power. In other words, no high level operation provided by some programming languages is allowed.
