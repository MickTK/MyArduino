#include <Adafruit_ImageReader.h>
#include <SdFat.h>
#include <Adafruit_SPIFlash.h>

// Pins
// SD_GND  -> GND
// SD_VCC  -> 5v
// SD_MISO -> 12
// SD_MOSI -> 11
// SD_SCK  -> 13
#define SD_CS 10

extern SdFat sd;
extern Adafruit_ImageReader reader;
extern SdFile sdFile;

void sd_init();
void listFiles(const char * directory);

int bitmapWidth(const char *image);
int bitmapHeight(const char *image);

boolean writeFile(const char *name, String text);
String readFile(const char *name);
boolean deleteFile(const char *name);

/*
    sd.mkdir("/relative/path");
    sd.chdir("/absolute/path");
    reader.drawBMP(image, screen, 50, 50);
*/
