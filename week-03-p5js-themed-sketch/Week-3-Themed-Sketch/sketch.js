// "Always Watching": a sketch about surveillance and data
//
// Eyes follow your mouse and every movement is logged as data.
// Incognito mode (press I) changes nothing. The only place you're not watched is the tiny "no signal" corner: the middle of nowhere.

let trail = [];        // recent mouse positions
let dataPoints = 0;    // how much data has been collected
let incognito = false; // true after pressing I

function setup() {
  createCanvas(600, 400);
  strokeWeight(2); // thicker lines for the trail and eyes
}

function draw() {
  background(20);

  // The "no signal" corner is the bottom-right 60 x 60 pixels
  let offline = mouseX > 540 && mouseY > 340;

  noStroke();
  fill(40, 120, 60);
  rect(540, 340, 60, 60);
  fill(255);
  textSize(10);
  text("no signal", 547, 373);

  // Log your position, unless you're offline
  if (!offline) {
    trail.push({ x: mouseX, y: mouseY });
    dataPoints = dataPoints + 1;
  }

  // Only keep the last 50 positions
  if (trail.length > 50) {
    trail.shift();
  }

  // Draw the trail
  noFill();
  stroke(255, 60, 60);
  beginShape();
  for (let spot of trail) {
    vertex(spot.x, spot.y);
  }
  endShape();

  // A grid of eyes: 5 across, 3 down
  for (let x = 60; x < 600; x += 120) {
    for (let y = 60; y < 340; y += 100) {
      drawEye(x, y, offline);
    }
  }

  // Text at the bottom
  noStroke();
  fill(255);
  textSize(14);
  text("Data points collected: " + dataPoints, 15, 360);

  if (offline) {
    text("Offline. Nobody's watching... but you can't do anything here either.", 15, 385);
  } else if (incognito) {
    text("Incognito mode: ON. They're still watching.", 15, 385);
  } else {
    text("Press I to go incognito.", 15, 385);
  }
}

// Draws one eye at (x, y). Closed eyes are just a line.
function drawEye(x, y, closed) {
  stroke(200);

  if (closed) {
    line(x - 25, y, x + 25, y);
  } else {
    // White of the eye
    fill(255);
    ellipse(x, y, 50, 30);

    // Pupil goes towards the mouse but stays inside the eye
    let pupilX = constrain(mouseX, x - 12, x + 12);
    let pupilY = constrain(mouseY, y - 6, y + 6);

    // Red pupils in incognito mode: it makes no difference
    noStroke();
    if (incognito) {
      fill(200, 0, 0);
    } else {
      fill(0);
    }
    circle(pupilX, pupilY, 14);
  }
}

// Press I to switch incognito mode on and off
function keyPressed() {
  if (key === "i" || key === "I") {
    incognito = !incognito;
  }
}