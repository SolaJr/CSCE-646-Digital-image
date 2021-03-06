var InitDemo = function () {
	console.log('This is working');

//	var canvas = document.getElementById('game-surface');
//	var gl = canvas.getContext('webgl');

    const canvas = document.createElement('canvas');
    document.body.appendChild(canvas);

    // get the web gl 
    const gl = canvas.getContext('webgl');

	if (!gl) {
		console.log('WebGL not supported, falling back on experimental-webgl');
		gl = canvas.getContext('experimental-webgl');
	}

	if (!gl) {
		alert('Your browser does not support WebGL');
	}

    // set the size of the canvas and the basic origin
    gl.viewport(0,0, gl.drawingBufferWidth, gl.drawingBufferHeight);

    // make gl clear so we can easily see where we are on the screen
    gl.clearColor (1.0,.2,.5,1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    //vertext Shader  = select position triangulalry
    const vShaderSource = `

        attribute vec2 position;
        void main(){
            gl_Position = vec4(position, 0,1.0);
        }
    `;

    // Fragment Shader = select color
    const fShaderSource =`
        precision highp float;
        void main(){
            gl_FragColor = vec4(0.9,.1, 1.0,1.0);
        }
    `;

    //create reusable handles for the shaders
    const vertShader = gl.createShader(gl.VERTEX_SHADER);
    const fragShader = gl.createShader(gl.FRAGMENT_SHADER);

    // Connect the above consts to their respective fragment / vertext shader formula. 
    // this means to edit the color, you just need to change the numbers above same for position. 
    // line 20 and 28 specitifically 
    gl.shaderSource(vertShader, vShaderSource);
    gl.shaderSource(fragShader,fShaderSource);

    gl.compileShader(vertShader);
    gl.compileShader(fragShader);

    // create the basic program for the Canvas to run
    const program = gl.createProgram();

    // attach the program for each shader ( note only one shader at a time)
    gl.attachShader(program, vertShader);
    gl.attachShader(program, fragShader);

    gl.linkProgram(program);
    gl.useProgram(program);

    // Set up your image using custom verties 
    // Give custom positions to chose the shape in question
    const vertices = new Float32Array([
        // Format ( x , y ) for 2 triangles
        -.34,-.64,
        -1,1,
        1,1,
    // other triangles 
        -1,-1,
        1,1,
        1,-1

    ]);

    // send the above verticies to the 
    // vertex shader to change hte position 

    // vertext buffer
    const vBuffer = gl.createBuffer();
    // select 2 buffers to run 
    gl.bindBuffer( gl.ARRAY_BUFFER,vBuffer )
    gl.bufferData(gl.ARRAY_BUFFER,vertices, gl.STATIC_DRAW);

    // position in the shader location needs to be stored 
    const positionLocation = gl.getAttribLocation(program, 'position');

    // how should the shader take and inteprert the data . 
    gl.vertexAttribPointer(positionLocation,2,gl.FLOAT, false, 0,0 );
    gl.enableVertexAttribArray(positionLocation); 

    // reserach draw awaysbut honestly, it just takes the 3 pairs of 2 
    // and makes it know it is taking 6 peices of data as triangles 
    gl.drawArrays(gl.TRIANGLES, 0,6);

    // now we have 2 drawn rectangles on top. 
};