
#include "Arduino.h"


#ifndef ssd1963_h
#define ssd1963_h

#define DB_0 29
#define DB_1 32
#define DB_2 33
#define DB_3 12
#define DB_4 11
#define DB_5 10
#define DB_6 9
#define DB_7 8
#define DB_8 7
#define DB_9 6
#define DB_10 5
#define DB_11 4
#define DB_12 3
#define DB_13 2
#define DB_14 1
#define DB_15 0

  
class SSD1963{
  
  public:

      SSD1963();
      SSD1963(int RS, int WR,int CS, int RST);
  
      void inline LCD_Writ_Bus(char ch,char cl);
      void InitLCD(void);
      void inline LCD_Write_DATA(char VL);
      void inline LCD_Write_COM(char VL);
     
      void inline LCD_Write_DATA(char VH,char VL);
      void setColor(byte r, byte g, byte b);
      void setBackColor(byte r, byte g, byte b);
     
      void inline setXY(word x1, word y1, word x2, word y2);
      void _fast_fill_16(int ch, int cl, long pix);
      void fillRect(int x1, int y1, int x2, int y2);
      void writeRect(int16_t x, int16_t y, int16_t w, int16_t h, const uint16_t *pcolors);
      void inline LCD_Writ_Bus16(uint16_t data);
      void drawLine(int x1, int y1, int x2, int y2);

      uint8_t			fch, fcl, bch, bcl;
          
      uint8_t			B_RS, B_WR, B_CS, B_RST;
     
      
  private:
   
  
};

#endif
