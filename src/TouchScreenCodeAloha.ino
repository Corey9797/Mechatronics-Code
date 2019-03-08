//==== Including Libraries
#include <UTFT.h> 
#include <UTouch.h>
#include <Arduino.h>

//==== Creating Objects
UTFT    myGLCD(SSD1289,38,39,40,41); //Parameters should be adjusted to your Display/Schield model
UTouch  myTouch( 6, 5, 4, 3, 2);

//==== Defining Variables
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

int x, y;

char currentPage;

void setup() {
  // put your setup code here, to run once:
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  // Defining Pin Modes
  
  drawNameScreen();  // Draws the Name screen
  currentPage = '0'; // Indicates that we are at the name screen
}

void loop() {
  // put your main code here, to run repeatedly:

  // NameScreen
  if (currentPage== '0') {
    if (myTouch.dataAvailable()) {
      currentPage == '1'; // Indicates that we are progressing to the main menu screen
      myGLCD.clrScr(); // Clears the screen
      drawMainMenuScreen();
    }
  }





  // ====== Custom Funtions ======
// drawNameScreen - Custom Function
void drawNameScreen() {
  // Background
  myGLCD.fillScr(66,200,244); // Sets the background color of the screen to baby blue
  myGLCD.setColor(238,214,175); //Sets to sand color
  myGLCD.fillRect(0,185,320,240); // Draws tan filled rectangle at bottom of screen to represent sand
    
  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(BigFont);
  myGLCD.print("Aloha!", CENTER, 50);
  myGLCD.setFont(MediumFont); 
  myGLCD.print("Kulia i ka nu'u", CENTER, 100);
  myGLCD.setFont(SmallFont);
  myGLCD.print("press anywhere to play", CENTER, 175);
  
}

// drawMainMenuScreen - Custom Function
void drawMainMenuScreen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(172,212,227); // Sets the color to dutch boy hawaiian sky
  myGLCD.fillRect(0,0,320,10); // Draws top border bar
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,320,240); // Draws bottom border bar

  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(MediumFont);
  myGLCD.print("Main Menu", CENTER, 10);

  //Settings button
  myGLCD.setColor(204,210,;221);
  myGLCD.fillRoundRect(290,15,315,40);
  myGLCDq.setColor(255,255,255);
  myGLCD.drawRoundRect(290,15,315,40);
  myGLCD.drawBitmap(290,15,25,25,gear);

  //High Scores button
  myGLCD.setColor(204,210,221);
  myGLCD.fillRoundRect(5,15,30,40);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect(5,15,30,40);
  myGLCD.drawBitmap(5,15,25,25,standings);

  //Gamemode 1 button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (35, 50, 285, 90); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (35, 50, 285, 90); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("Gamemode 1", CENTER, 102); // Prints the string

  //Gamemode 2 button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (35, 100, 285, 140);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (35, 100, 285, 140);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Gamemode 2", CENTER, 112);

  //Gamemode 3 button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (35, 150, 285, 190);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (35, 150, 285, 190);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Gamemode 3", CENTER, 162);
}

// drawGamemode1Screen - Custom Function
void drawGamemode1Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(172,212,227); // Sets the color to dutch boy hawaiian sky
  myGLCD.fillRect(0,0,320,10); // Draws top border bar
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,320,240); // Draws bottom border bar

  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(MediumFont);
  myGLCD.print("Gamemode 1", CENTER, 10);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this mode, the player must score the coconut through a series of 10 holes. Each target hole is glowing green and a higher score will be awarded for scoring quickly. You have 4 lives", 10,40);

 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (35, 140, 135, 180); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (35, 140, 135, 180); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1 Player", CENTER, 152); // Prints the string

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (185, 140, 285, 180);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (185, 140, 285, 180);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2 Players", CENTER, 152);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 190, 210, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 190, 210, 230);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 202);

}

// drawGamemode2Screen - Custom Function
void drawGamemode2Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(172,212,227); // Sets the color to dutch boy hawaiian sky
  myGLCD.fillRect(0,0,320,10); // Draws top border bar
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,320,240); // Draws bottom border bar

  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(MediumFont);
  myGLCD.print("Gamemode 2", CENTER, 10);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this mode, the player must feed the angry monkeys (represented by red holes) with the coconut balls without letting the anger meter reach 999", 10,40);

 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (35, 140, 135, 180); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (35, 140, 135, 180); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1 Player", CENTER, 152); // Prints the string

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (185, 140, 285, 180);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (185, 140, 285, 180);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2 Players", CENTER, 152);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 190, 210, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 190, 210, 230);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 202);
}

// drawGamemode3Screen - Custom Function
void drawGamemode3Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(172,212,227); // Sets the color to dutch boy hawaiian sky
  myGLCD.fillRect(0,0,320,10); // Draws top border bar
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,320,240); // Draws bottom border bar

  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(MediumFont);
  myGLCD.print("Gamemode 3", CENTER, 10);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this gamemode, you must attempt to feed every monkey in the forest with a coconut. But remember, each monkey is only allowed one cocount", 10,40);

 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (35, 140, 135, 180); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (35, 140, 135, 180); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1 Player", CENTER, 152); // Prints the string

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (185, 140, 285, 180);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (185, 140, 285, 180);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2 Players", CENTER, 152);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 190, 210, 230);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 190, 210, 230);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 202);
}

// Highlights the button when pressed
void drawFrame(int x1, int y1, int x2, int y2) {
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
    myTouch.read();
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (x1, y1, x2, y2);
}





}
