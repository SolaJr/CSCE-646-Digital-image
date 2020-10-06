function setup() {
    createCanvas(400, 400);
    angleMode(DEGREES);
}

function draw() {
    background(0);
    stroke(255/3);
    noFill();

    strokeWeight(4);
    point(mouseX, mouseY);
    point(150, 50);
    point(250, 60);
    point(0 ,0);
    strokeWeight(9);

    beginShape();

    let spacing = map(mouseX, 0, width, 5, 100);
    for (let a = 0; a < 90; a += spacing) {
        let x = 50 * sin(a) + 200;
        let y = a;
        vertex(x, y);
    }

    curveVertex(mouseX, mouseY);
//    curveVertex(100, 200);
  //  curveVertex(150, 50);
    curveVertex(0,0);
 //   curveVertex(300, 200);
   // curveVertex(300, 200);
    endShape();
}
