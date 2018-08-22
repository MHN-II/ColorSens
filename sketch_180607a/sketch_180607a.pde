import processing.serial.*; 
Serial port; 

//varaiables to use 
String R = ""; 
String G = ""; 
String B = ""; 
String temp = ""; 
String data = "";
int index =0; 
PFont font; 

void setup()
{
  size (800,150);
  port = new Serial(this, "/dev/cu.usbmodem1431", 9600);
  port.bufferUntil('.');
  font = loadFont("AgencyFB-Bold-100.vlw");
  textFont(font, 80); 
}

void draw()
{
  background(0,0,0);
  fill(255,0,0);
  text(R, 0, 0); 
  fill(0,255,0); 
  text(G, 250, 100); 
  fill(0,0,255);
  text(B, 500, 100); 
  
}

void serialEvent(Serial port)
{
  data = port.readStringUntil('.'); 
  data = data.substring(0, data.length() -1); 
  
  index = data.indexOf(",");
  R = data.substring(0, index); 
  temp = data.substring(index+1, data.length());
  index= temp.indexOf(",");
  G = temp.substring(0, index);
  B= temp.substring(index+1, temp.length()); 
}
