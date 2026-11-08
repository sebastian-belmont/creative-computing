// "Rain Garden": an interactive 3D garden
//
// The garden only grows if you look after it. Rain makes the flowers grow;
// leave it alone and they slowly wilt.
//
// Controls:
//   move the mouse left/right -> spin the garden
//   click                     -> plant a new flower
//   R                         -> rain on/off (flowers grow while it rains)
//   N                         -> day/night
//   C                         -> clear the garden

let plants = [];
let raining = false;
let night = false;
let colours = ["#ff6b9a", "#ffd166", "#c77dff", "#ff8c42", "#f1faee"];

function setup() {
  createCanvas(700, 500, WEBGL);

  // Start with a few flowers
  for (let i = 0; i < 5; i++) {
    plantSeed();
  }
}

function draw() {
  // Sky and light change between day and night
  if (night) {
    background(10, 15, 35);
    ambientLight(30);
    directionalLight(80, 90, 160, 0.3, 1, -0.5);
  } else {
    background(170, 215, 255);
    ambientLight(110);
    directionalLight(255, 250, 230, 0.3, 1, -0.5);
  }

  // Camera above and in front, looking down at the middle of the garden
  camera(0, -350, 600, 0, 0, 0, 0, 1, 0);

  // Spin the garden with the mouse, plus a slow turn on its own
  rotateY(map(mouseX, 0, width, -PI, PI) + frameCount * 0.002);

  noStroke();

  // Ground: a flat plane
  push();
  rotateX(HALF_PI);
  fill(80, 150, 70);
  plane(450, 450);
  pop();

  // Four trees in the corners: a cylinder trunk and a sphere on top
  for (let x = -180; x <= 180; x += 360) {
    for (let z = -180; z <= 180; z += 360) {
      push();
      translate(x, -30, z);
      fill(110, 75, 45);
      cylinder(6, 60);
      translate(0, -50, 0);
      fill(40, 110, 60);
      sphere(30);
      pop();
    }
  }

  // A few rocks: boxes
  fill(140);
  push();
  translate(-60, -8, 150);
  box(30, 16, 20);
  pop();
  push();
  translate(120, -6, -40);
  box(18, 12, 18);
  pop();

  // The flowers
  for (let p of plants) {
    // Grow while it's raining, slowly wilt when it isn't
    if (raining && p.h < 150) {
      p.h = p.h + 0.5;
    } else if (!raining && p.h > 10) {
      p.h = p.h - 0.03;
    }

    // Stem: a cylinder that gets taller
    push();
    translate(p.x, -p.h / 2, p.z);
    fill(60, 140, 60);
    cylinder(2, p.h);
    pop();

    // Flower head: a sphere with a torus (ring) of petals round it
    let size = p.h / 12 + 3;
    push();
    translate(p.x, -p.h, p.z);
    fill(p.colour);
    sphere(size);
    rotateX(HALF_PI);
    torus(size + 4, 2);
    pop();
  }

  // Rain: lots of thin boxes in random places each frame
  if (raining) {
    fill(200, 220, 255);
    for (let i = 0; i < 60; i++) {
      push();
      translate(random(-220, 220), random(-300, 0), random(-220, 220));
      box(1, 10, 1);
      pop();
    }
  }
}

// Adds a new small flower somewhere random in the garden
function plantSeed() {
  plants.push({
    x: random(-150, 150),
    z: random(-150, 150),
    h: 5,
    colour: random(colours),
  });
}

function mousePressed() {
  plantSeed();
}

function keyPressed() {
  if (key === "r" || key === "R") {
    raining = !raining;
  }
  if (key === "n" || key === "N") {
    night = !night;
  }
  if (key === "c" || key === "C") {
    plants = [];
  }
}