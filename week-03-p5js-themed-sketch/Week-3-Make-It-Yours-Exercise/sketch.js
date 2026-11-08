// Make the system yours (Session 5 in-class exercise)
// Starts from the class sketch (a row of circles, a palette, movement, mouse control, a mouse-press condition) and changes it.
//
// What I changed from the class version:
// 1. Shape: squares instead of circles
// 2. Direction: the row moves up and down instead of left and right
// 3. Palette: my own colours
// 4. Number of elements: 10 instead of 8
// 5. Mouse: mouseX controls the size, mouseY controls the speed
// 6. Mouse press: switches to a second palette
// 7. A second moving pattern: a row of circles going the opposite way

let palette = ["#1b1b1e", "#3a86ff", "#8338ec", "#ff006e", "#fb5607"];
let pressedPalette = ["#f1faee", "#a8dadc", "#457b9d", "#e63946", "#ffb703"];

let y = 0;          // vertical position of the squares
let goingDown = true;

function setup() {
  createCanvas(700, 400);
  rectMode(CENTER);
}

function draw() {
  background(240);
  noStroke();

  // mouseX controls the size of the shapes (10 to 60 pixels)
  let size = map(mouseX, 0, width, 10, 60);

  // mouseY controls the speed (1 to 6 pixels per frame)
  let speed = map(mouseY, 0, height, 1, 6);

  // Move up and down, turning round at the edges
  if (goingDown) {
    y = y + speed;
    if (y > height) {
      goingDown = false;
    }
  } else {
    y = y - speed;
    if (y < 0) {
      goingDown = true;
    }
  }

  // Pick which palette to use: a different one while the mouse is pressed
  let colours = palette;
  if (mouseIsPressed) {
    colours = pressedPalette;
  }

  // Pattern 1: a row of 10 squares moving up and down
  for (let i = 0; i < 10; i++) {
    let x = 35 + i * 70;
    fill(colours[i % colours.length]); // go through the palette in order
    square(x, y, size);
  }

  // Pattern 2: a row of circles moving the opposite way
  for (let i = 0; i < 10; i++) {
    let x = 35 + i * 70;
    fill(colours[(i + 2) % colours.length]);
    circle(x, height - y, size / 2);
  }
}