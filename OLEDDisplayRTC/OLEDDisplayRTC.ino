#include <Wire.h>
#include <RTClib.h>
#include <U8glib.h>

RTC_DS3231 rtc;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

char timeStr[9];
char dateStr[11];

void setup() {
  Wire.begin();
  rtc.begin();
  u8g.setFont(u8g_font_6x10);
  // Set the time format (year ,month, day, hour, minute, secods) 24hr format time
  // rtc.adjust(DateTime(2023, 4, 13, 23, 15, 0));
}

void loop() {
  DateTime now = rtc.now();
  
  // Format the time and date strings using sprintf()
  sprintf(timeStr, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  sprintf(dateStr, "%02d/%02d/%04d", now.day(), now.month(), now.year());
  
  // Start the display using firstPage() method of the U8GLIB_SSD1306_128X64 class.
  u8g.firstPage();
  
  // Draw the time and date strings on the OLED display using drawStr() method of the U8GLIB class.
  do {
    u8g.drawStr(0, 10, timeStr);
    u8g.drawStr(0, 20, dateStr);
  } while (u8g.nextPage());
  
  // Wait for 1 second before repeating
  delay(1000);
}