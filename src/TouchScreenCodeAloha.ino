//==== Including Libraries
#include <UTFT.h> 
#include <URTouch.h>
#include <EEPROM.h>


//==== Creating Objects
UTFT    myGLCD(ILI9341_16,38,39,40,41); //Parameters should be adjusted to your Display/Schield model
URTouch  myTouch(6, 5, 4, 3, 2);

//==== Defining Variables
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

extern unsigned int coconuttree[];
extern unsigned int coconut[];
extern unsigned int podium[];
extern unsigned int gears[];
extern unsigned int backarrow[];

unsigned long previousMillis = 0;
const long titlescreendelay = 500;

int titlecount = 0;
int x, y;
int players = 1;

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
  unsigned long currentMillis = millis();
  // put your main code here, to run repeatedly:
  if (currentPage == '0') {
    if (currentMillis - previousMillis >= titlescreendelay && titlecount == 0) {
      previousMillis = currentMillis;
      myGLCD.setColor(255,167,25);
      myGLCD.fillRect(95,150,225,180);
      titlecount = 1;
    }
    if (currentMillis - previousMillis >= titlescreendelay && titlecount == 1) {
      previousMillis = currentMillis;
      myGLCD.setBackColor(255,167,25);
      myGLCD.setColor(0,0,0);
      myGLCD.print("press anywhere", CENTER, 150);
      myGLCD.print("to play", CENTER, 165);
      titlecount = 0;
    }
    if (myTouch.dataAvailable()) {
      currentPage = '1'; // Indicates that we are progressing to the main menu screen
      myGLCD.clrScr(); // Clears the screen
      drawMainMenuScreen();
    }
  }

  // Main Menu Screen
  if (currentPage == '1') {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed

      // If the gamemode1 button is pressed
      if ((x>=35) && (x<=285) && (y>=60) && (y<=100)) {
        drawFrame (35, 60, 285, 100);
        currentPage = '2';
        myGLCD.clrScr();
        drawGamemode1Screen();
      }

      // If the gamemode2 button is pressed
      if ((x>=35) && (x<=285) && (y>=110) && (y<=150)) {
        drawFrame (35, 110, 285, 150);
        currentPage = '3';
        myGLCD.clrScr();
        drawGamemode2Screen();
      }
      
      // If the gamemode3 button is pressed
      if ((x>=35) && (x<=285) && (y>=160) && (y<=200)) {
        drawFrame (35, 160, 285, 200);
        currentPage = '4';
        myGLCD.clrScr();
        drawGamemode3Screen();
      }

      // If the standings button is pressed
      if ((x>=5) && (x<=50) && (y>=5) && (y<=50)) {
        drawFrame (5,5,50,50);
        currentPage = '5';
        myGLCD.clrScr();
        drawHighScoresMenu();
      }

      // If the settings button is pressed
      if ((x>=270) && (x<=315) && (y>=5) && (y<=50)) {
        drawFrame(270,5,315,50);
        currentPage = '6';
        myGLCD.clrScr();
        drawSettingsScreen();
      }

      // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '0';
        myGLCD.clrScr();
        drawNameScreen();
      }

    }
  }

   // Gamemode 1 Screen
  while (currentPage == '2') {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed

      // If 1 Player Mode is Selected
      if ((x>=45) && (x<=125) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(195,150,275,190);
        drawSteadyFrame(45,150,125,190);
        players = 1;
      }

      // If 2 Player Mode is Selected
      if ((x>=195) && (x<=275) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(45,150,125,190);
        drawSteadyFrame(195,150,275,190);
        players = 2;
      }

      // If Begin Game is Selected
      if ((x>=110) && (x<=210) && (y>=195) && (y<=235)) {
        drawFrame (110,195,210,235);
        delay(500);
        //PlayGamemode1();
      }

      // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '1';
        myGLCD.clrScr();
        drawMainMenuScreen();
        players = 1;
      }
    }
  }

  // Gamemode 2 Screen
  while (currentPage == '3') {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed

      // If 1 Player Mode is Selected
      if ((x>=45) && (x<=125) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(195,150,275,190);
        drawSteadyFrame(45,150,125,190);
        players = 1;
      }

      // If 2 Player Mode is Selected
      if ((x>=195) && (x<=275) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(45,150,125,190);
        drawSteadyFrame(195,150,275,190);
        players = 2;
      }

      // If Begin Game is Selected
      if ((x>=110) && (x<=210) && (y>=195) && (y<=235)) {
        drawFrame (110,195,210,235);
        delay(500);
        //PlayGamemode2();
      }

      // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '1';
        myGLCD.clrScr();
        drawMainMenuScreen();
        players =1;
      }
    }
  }

  // Gamemode 3 Screen
  while (currentPage == '4') {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed

      // If 1 Player Mode is Selected
      if ((x>=45) && (x<=125) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(195,150,275,190);
        drawSteadyFrame(45,150,125,190);
        players = 1;
      }

      // If 2 Player Mode is Selected
      if ((x>=195) && (x<=275) && (y>=150) && (y<=190)) {
        undrawSteadyFrame(45,150,125,190);
        drawSteadyFrame(195,150,275,190);
        players = 2;
      }

      // If Begin Game is Selected
      if ((x>=110) && (x<=210) && (y>=195) && (y<=235)) {
        drawFrame (110,195,210,235);
        delay(500);
        //PlayGamemode3();
      }

      // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '1';
        myGLCD.clrScr();
        drawMainMenuScreen();
        players =1;
      }
    }
  }

  //High Scores Screen
  while (currentPage == '5') {
   if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed

  // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '1';
        myGLCD.clrScr();
        drawMainMenuScreen();
      }
    }
  }
  
  //Settings Screen
  while (currentPage == '6') {
   if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); // X-Coordinate where the screen was pressed
      y=myTouch.getY(); // Y-Coordinate where the screen was pressed
      
  // If the back arrow is pressed
      if ((x>=5) && (x<=30) && (y>=213) && (y<=238)) {
        drawFrame(5,213,30,238);
        currentPage = '1';
        myGLCD.clrScr();
        drawMainMenuScreen();
      }
    }
  }

}


  // ====== Custom Funtions ======
// drawNameScreen - Custom Function
void drawNameScreen() {
  // Background
  myGLCD.fillScr(66,200,244); // Sets the background color of the screen to baby blue
  myGLCD.drawBitmap(240,70,80,120,coconuttree);
  myGLCD.drawBitmap(20,155,30,30,coconut);
  myGLCD.setColor(255,167,25);
  myGLCD.fillCircle(160,195,85);
  myGLCD.setColor(238,214,175); //Sets to sand color
  myGLCD.fillRect(0,185,319,240); // Draws tan filled rectangle at bottom of screen to represent sand
    
  // Words
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(66,200,244);
  myGLCD.print("Aloha!", CENTER, 25);
  myGLCD.setFont(SmallFont); 
  myGLCD.print("kulia i ka nu'u", CENTER, 60);
  myGLCD.print("(reach for the highest)", CENTER, 80);  
}

// drawMainMenuScreen - Custom Function
void drawMainMenuScreen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(172,212,227); // Sets the color to dutch boy hawaiian sky
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  // Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Main Menu", CENTER, 20);

  //Settings button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect(270,5,315,50);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect(270,5,315,50);
  myGLCD.drawBitmap(273,8,40,40,gears);

  //High Scores button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect(5,5,50,50);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect(5,5,50,50);
  myGLCD.drawBitmap(8,13,40,30,podium);

  //Gamemode 1 button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (35, 60, 285, 100); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (35, 60, 285, 100); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("Gamemode 1", CENTER, 72); // Prints the string

  //Gamemode 2 button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (35, 110, 285, 150);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (35, 110, 285, 150);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Gamemode 2", CENTER, 122);

  //Gamemode 3 button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (35, 160, 285, 200);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (35, 160, 285, 200);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Gamemode 3", CENTER, 172);
}

// drawGamemode1Screen - Custom Function
void drawGamemode1Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  // Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Gamemode 1", CENTER, 5);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this mode, the player must score",CENTER,30);
  myGLCD.print("the coconut through a series of 10",CENTER,50);
  myGLCD.print("holes. Each target hole is glowing",CENTER,70);
  myGLCD.print("green and a higher score will be",CENTER,90);
  myGLCD.print("awarded for scoring quickly.",CENTER,110);
  myGLCD.print("You have 4 lives.",CENTER,130);



 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (45, 150, 125, 190); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (45, 150, 125, 190); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1P", 70, 162); // Prints the string
  drawSteadyFrame(45,150,125,190);

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (195, 150, 275, 190);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (195, 150, 275, 190);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2P", 220, 162);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 195, 210, 235);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 195, 210, 235);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 207);
}

// drawGamemode2Screen - Custom Function
void drawGamemode2Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  // Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Gamemode 2", CENTER, 5);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this mode, you must feed the angry",CENTER,30);
  myGLCD.print("monkeys (represented by red holes)",CENTER,50);
  myGLCD.print("with the coconuts without letting",CENTER,70);
  myGLCD.print("the anger meter reach 999",CENTER,90);
  
 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (45, 150, 125, 190); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (45, 150, 125, 190); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1P", 70, 162); // Prints the string
  drawSteadyFrame(45,150,125,190);

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (195, 150, 275, 190);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (195, 150, 275, 190);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2P", 220, 162);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 195, 210, 235);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 195, 210, 235);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 207);
}

// drawGamemode3Screen - Custom Function
void drawGamemode3Screen() {
  // Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  // Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Gamemode 3", CENTER, 5);
  myGLCD.setFont(SmallFont);
  myGLCD.print("In this mode, you must attempt to",CENTER,30);
  myGLCD.print("feed every monkey in the forest",CENTER,50);
  myGLCD.print("with a coconut. But remember,",CENTER,70);
  myGLCD.print("each monkey is only allowed",CENTER,90);
  myGLCD.print("one coconut.",CENTER,110);

 // 1 Player Button
  myGLCD.setColor(196,33,33); // Sets red color
  myGLCD.fillRoundRect (45, 150, 125, 190); // Draws filled rounded rectangle
  myGLCD.setColor(255,255,255); // Sets color to white
  myGLCD.drawRoundRect (45, 150, 125, 190); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(196,33,33); // Sets the background color of the area where the text will be printed to red, same as the button
  myGLCD.print("1P", 70, 162); // Prints the string
  drawSteadyFrame(45,150,125,190);

  // 2 Players Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (195, 150, 275, 190);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (195, 150, 275, 190);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("2P", 220, 162);

  //Play Button
  myGLCD.setColor(196,33,33);
  myGLCD.fillRoundRect (110, 195, 210, 235);
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (110, 195, 210, 235);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(196,33,33);
  myGLCD.print("Begin", CENTER, 207);
}

//Draws Settings Menu
void drawSettingsScreen() {
  //Background
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  //Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Settings", CENTER, 5);
}

//Draws High Score Menu
void drawHighScoresMenu() {
  myGLCD.fillScr(255,224,149); // Sets the background color of the screen to tan
  myGLCD.setColor(25,132,69); // Sets the color to a dark green
  myGLCD.fillRect(0,210,319,240); // Draws bottom border bar
  myGLCD.drawBitmap (5,213,25,25,backarrow);

  //Words
  myGLCD.setColor(0,0,0);
  myGLCD.setBackColor(255,224,149);
  myGLCD.setFont(BigFont);
  myGLCD.print("Highscores", CENTER, 5);
}

// Highlights the button when pressed
void drawFrame(int x1, int y1, int x2, int y2) {
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  delay(300);
  while (myTouch.dataAvailable())
    myTouch.read();
    myGLCD.setColor(255,255,255);
    myGLCD.drawRoundRect (x1, y1, x2, y2);
  
}

void drawSteadyFrame(int x1, int y1, int x2, int y2) {
  myGLCD.setColor(255,0,0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

void undrawSteadyFrame(int x1, int y1, int x2, int y2) {
  myGLCD.setColor(255,255,255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}
