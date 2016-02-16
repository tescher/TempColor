// LED Driver Pins (Ethernet shield uses 10-13 for network stuff, so don't use those)
#define LED_RED 9
#define LED_GREEN 10
#define LED_BLUE 11

// Color definitions, using 0x0RGB.
#define RED 0x0F00
#define GREEN 0x00F0
#define BLUE 0x000F
#define WHITE 0x0FFF
#define YELLOW 0x0FF0
#define GREY 0x0444
#define BLACK 0x0000
#define PURPLE 0x0F0F
#define LIGHTGREEN 0x08F8
#define LIGHTBLUE 0x088F
#define LIGHTRED 0x0F88

// Temp interpretation
#define TEMP_HOT 80 
#define TEMP_WARM 75 
#define TEMP_COOL 70 
#define TEMP_COLD 65 

// Debugging config
#define DEBUG 1        // Conditional Compilation
float temp;
int current_Color = 0;
String inString = "";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
// Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();

    if (inChar != '\n') {

      // As long as the incoming byte
      // is not a newline,
      // convert the incoming byte to a char
      // and add it to the string
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value as a float:
    else {
      temp = inString.toFloat();
      if (temp > TEMP_HOT) {
        LED_Display(RED, current_Color, true);
        current_Color = RED;
      } else if (temp > TEMP_WARM) {
        LED_Display(YELLOW, current_Color, true);
        current_Color = YELLOW;
      } else if (temp > TEMP_COOL) {
        LED_Display(GREEN, current_Color, true);
        current_Color = GREEN;
      } else {
        LED_Display(BLUE, current_Color, true);
        current_Color = BLUE;
      }
      // clear the string for new input:
      inString = "";
    }
  }
}
