#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(SCL, SDA, U8X8_PIN_NONE);

void setup(void)
{ 
  u8x8.begin();
  u8x8.setPowerSave(0);
}

void loop(void)
{ 
  u8x8.setFont(u8x8_font_px437wyse700a_2x2_f);
  u8x8.drawString(0,0,"I2C OLED");
  u8x8.drawString(2,3,"128x64");
  u8x8.drawString(0,6,"0.96 Inc");
  u8x8.refreshDisplay();  
  delay(2000);
}
