#include "sd.h"

SdFat sd;
Adafruit_ImageReader reader(sd);
SdFile sdFile;

void sd_init(){
    sd.begin(SD_CS);
}

int bitmapWidth(const char *image){
    int32_t width32, height32;

    reader.bmpDimensions(image, &width32, &height32);
    return String(width32).toInt();
}

int bitmapHeight(const char *image){
    int32_t width32, height32;

    reader.bmpDimensions(image, &width32, &height32);
    return String(height32).toInt();
}

boolean writeFile(const char *name, String text){
    if (!sdFile.open(name, O_RDWR | O_CREAT | O_AT_END)) {
        return false;
    }
    sdFile.println(text);
    sdFile.close();
    return true;
}

String readFile(const char *name){
    String result = "";

    if (!sdFile.open(name, O_READ)) {
        return "";
    }

    int data;
    while ((data = sdFile.read()) >= 0) {
        //Serial.write(data);
        result += char(data);
    }
    sdFile.close();
    return result;
}

boolean deleteFile(const char *name){
    if (!sdFile.open(name, O_READ | O_WRITE) || !sdFile.remove())
        return false;
    return true;
}

void listFiles(const char * directory){
  File dir;
  File f;

  if (!dir.open(directory)){
      Serial.println("Directory not found");
    return;
  }
  
  while (f.openNext(&dir, O_RDONLY)) {
    f.printFileSize(&Serial);
    Serial.write(' ');
    f.printModifyDateTime(&Serial);
    Serial.write(' ');
    f.printName(&Serial);
    if (f.isDir()) {
      // Indicate a directory.
      Serial.write('/');
    }
    Serial.println();
    f.close();
  }
  if (dir.getError()) {
    Serial.println("openNext failed");
  }
}
