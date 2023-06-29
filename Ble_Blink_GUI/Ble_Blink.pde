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
  /*
  line(width/2, 0, width/2, height);
  line(0, height/2, width, height/2);
  */
  line(0,height/3,width, height/3);
  line(0,2*height/3,width, 2*height/3);
  line(width/3, height/3, width/3, 2*height/3);
  line(2*width/3, height/3, 2*width/3, 2*height/3);
  fill(0);
  text("FORWARD", width/3, height/6);
  text("BACKWARD", width/3, 5*height/6);
  text("LEFT", width/9, height/2);
  text("RIGHT", 7*width/9, height/2);
  text("HORN", 4*width/9, height/2);
}

void mousePressed() {
  /*
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
  */
  if (mouseY < height/3) {
    arduino.write('F');
  }
  else if (mouseY > 2*height/3) {
    arduino.write('B');
  }
  else {
    if (mouseX < width/3) {
      arduino.write('L');
    }
    else if (mouseX > 2*width/3) {
      arduino.write('R');
    }
    else {
      arduino.write('H');
    }
  }
}
