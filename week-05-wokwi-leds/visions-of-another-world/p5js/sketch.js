// "The Glitch": visions of another world
//
// A calm, normal landscape that breaks apart into a digital world as you
// push the Wokwi slider up. The further you push, the more it glitches.

let socket;
let sensorValue = 0; // the slider's value, 0 to 65535

// Bright "digital" colours for the glitch blocks
let neon = ["#ff00ff", "#00ffff", "#39ff14", "#ff3131", "#ffffff"];

function setup() {
  createCanvas(600, 400);

  // Connect to the Python bridge (same as the test sketch)
  socket = new WebSocket("ws://localhost:8765");
  socket.onmessage = (event) => {
    sensorValue = Number(event.data);
  };
}

function draw() {
  // Turn the slider value into a glitch amount from 0 (calm) to 1 (broken)
  let glitch = map(sensorValue, 0, 65535, 0, 1);

  // How far shapes can jump about: 0 when calm, up to 30 pixels
  let shake = glitch * 30;

  noStroke();

  // Sky: sometimes flickers black, more often the more it glitches
  if (random() < glitch * 0.3) {
    background(0);
  } else {
    background(150, 200, 255);
  }

  // Sun with a colour split: red and cyan copies slide out to the sides
  let sunX = 450 + random(-shake, shake);
  let split = glitch * 20;
  fill(255, 0, 0, 150);
  circle(sunX - split, 100, 80);
  fill(0, 255, 255, 150);
  circle(sunX + split, 100, 80);
  fill(255, 220, 80);
  circle(sunX, 100, 80);

  // Hills and ground, shaking when glitched
  fill(80, 160, 90);
  ellipse(150 + random(-shake, shake), 330, 400, 200);
  ellipse(470 + random(-shake, shake), 340, 450, 220);
  fill(60, 130, 70);
  rect(0, 330, 600, 70);

  // Glitch blocks: none when calm, up to 150 when fully glitched
  let blocks = int(glitch * 150);
  for (let i = 0; i < blocks; i++) {
    fill(random(neon));
    // snap each block to a 20-pixel grid so it looks like pixels
    square(int(random(30)) * 20, int(random(20)) * 20, 20);
  }

  // Near the top of the slider, the world gives up
  if (glitch > 0.85) {
    fill(255);
    textSize(32);
    text("SIGNAL LOST", random(100, 350), random(100, 300));
  }
}
