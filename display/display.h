#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "colors.h"

#define TFT_CS         4
#define TFT_RST        8
#define TFT_DC         9

extern Adafruit_ST7735 screen;

void init_display();

int textWidth(const char *text);
int textHeight(const char *text);
int textX1(const char *text);
int textY1(const char *text);

/*
    screen.fillScreen(BLACK);
    screen.setCursor(0, 0);
    screen.setTextColor(WHITE);
    screen.setTextWrap(true);
    screen.setTextSize(3);
    screen.print("Ciao");
    screen.drawPixel(x, y, BLACK);
    screen.drawLine(x0, y0, x1, y1, WHITE);
    screen.fillRect(screen.width()/2 -x/2, screen.height()/2 -x/2 , x, x, color1);
    screen.drawRect(screen.width()/2 -x/2, screen.height()/2 -x/2 , x, x, color2);
    screen.drawCircle(x, y, radius, color);
    screen.fillCircle(x, y, radius, color);
    screen.width();
    screen.height();
*/