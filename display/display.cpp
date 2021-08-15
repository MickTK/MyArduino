#include "display.h"

Adafruit_ST7735 screen = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void init_display(){
  screen.initR(INITR_BLACKTAB);
  screen.fillScreen(BLACK);
}

int textWidth(const char *text){
  uint16_t width, height;
  int16_t x1, y1;

  screen.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  return width;
}
int textHeight(const char *text){
  uint16_t width, height;
  int16_t x1, y1;

  screen.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  return height;
}
int textX1(const char *text){
  uint16_t width, height;
  int16_t x1, y1;

  screen.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  return x1;
}
int textY1(const char *text){
  uint16_t width, height;
  int16_t x1, y1;

  screen.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  return y1;
}