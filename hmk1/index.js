
init();
async function init() {
    
// upload a image to use 
    var img = new Image();
    img.crossOrigin = "Anonymous";
    img.src = "https://solajr.github.io/CSCE-646-Digital-image/hmk1/image.jpg";
    await new Promise( r=> img.onload = r);
//  Set canvas dimensions 
    var canvas = document.createElement("canvas");
    canvas.height = img.height;
    canvas.width = img.width;
// get Web GL to start the party! 
    var gl = canvas.getContext("webgl");
// Assign the proper dimensions to be equal to any photo added
    Object.assign(canvas.style, {
        maxWidth: "100vw",
        maxHeight: "100vh",
        objectFit: "contain",
    })

    document.body.appendChild(canvas);
//Create your buffer for the dimensions of a square
    var buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([
        -1, -1, -1, 1,
        1, -1, 1, 1,
    ]), gl.STATIC_DRAW);

//create a vertex shader 
    gl.vertexAttribPointer(0, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(0);
// attributes of a vertext shader ( this is probably where most of our vector editing will take place e)
    var vshader = `
    attribute vec2 pos;
    varying vec2 vpos;
    void main(){
        vpos = pos*-0.5 + vec2(0.5);
        gl_Position = vec4(pos, 0.0, 1.0);
    }
    `

    var vs = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vs, vshader);
    gl.compileShader(vs);
// Create the fragment shader. This is straight forward, but the 
// fragment shader will dictate the color 
// The highp float stores the hex number we are refering to for the color of an individual pixle 
// Vpos is the position of a given vector 
// Uniform sampler 2D holds the image static array of all the hex codes accross the image 
// The depth is a tool I am playing with for extra credit. I will let you know if it work with a section about it.  
//The uniform sampler 2D Image is used to store the 
    var fshader = `
    precision highp float;
    uniform sampler2D img;
    uniform sampler2D depth;
    varying vec2 vpos;
    void main(){
        float dp = texture2D(depth, vpos).x;
        gl_FragColor = texture2D(img, vpos);
    }
    `

    // Fragment shader creation 
    var fs = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fs, fshader);
    gl.compileShader(fs);

    // Attach the fragmenet shader and the vertex shader . Then  link allows the program to be run in the context of the browser. 
    var program = gl.createProgram();
    gl.attachShader(program, fs);
    gl.attachShader(program, vs);
    gl.linkProgram(program);
    gl.useProgram(program);

    //Setting the stxture is basically creating the image

    function setTexture(im,name, num) {
        var texture = gl.createTexture();

        // create a texture and let i t be easily manipulatiable 
        gl.activeTexture(gl.TEXTURE0 + num);
        gl.bindTexture(gl.TEXTURE_2D, texture);

        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);

        gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, im);
        gl.uniform1i(gl.getUniformLocation(program, name), num);
    }

    setTexture(img, "img", 0);
    // Ignore loop for now. I am trying to get extra credit. I will mention it when ( or if ) it is working. 
    loop();

    function loop() {
        gl.clearColor(0.25, 0.65, 1, 1);
        gl.clear(gl.COLOR_BUFFER_BIT);
        gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
        requestAnimationFrame(()=>loop());
    }
}
