import processing.serial.*;

Serial arduino;

void setup() {
  String portName = "COM3";
  arduino = new Serial(this, portName, 9600);
  size(400, 400);
}

void draw() {
  background(255);
  stroke(0);
  line(width/2, 0, width/2, height);
  line(0, height/2, width, height/2);
}

void mousePressed() {
  if (mouseY < height/2) {
    if (mouseX > width/2) {
      arduino.write('0');
    }
    else {
      arduino.write('1');
    }
  }
  else {
    if (mouseX > width/2) {
      arduino.write('3');
    }
    else {
      arduino.write('2');
    }
  }
}
