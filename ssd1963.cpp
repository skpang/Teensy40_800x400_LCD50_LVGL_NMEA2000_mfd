
#include "Arduino.h"
#include "ssd1963.h"

SSD1963::SSD1963()
{
}

SSD1963::SSD1963(int RS, int WR,int CS, int RST)
{ 
  pinMode(DB_0, OUTPUT);
  pinMode(DB_1, OUTPUT);
  pinMode(DB_2, OUTPUT);
  pinMode(DB_3, OUTPUT);
  pinMode(DB_4, OUTPUT);
  pinMode(DB_5, OUTPUT);
  pinMode(DB_6, OUTPUT);
  pinMode(DB_7, OUTPUT);
  
  pinMode(DB_8, OUTPUT);
  pinMode(DB_9, OUTPUT);
  pinMode(DB_10, OUTPUT);
  pinMode(DB_11, OUTPUT);
  pinMode(DB_12, OUTPUT);
  pinMode(DB_13, OUTPUT);
  pinMode(DB_14, OUTPUT);
  pinMode(DB_15, OUTPUT);
	
  pinMode(RS,OUTPUT);
	pinMode(WR,OUTPUT);
	pinMode(CS,OUTPUT);
	pinMode(RST,OUTPUT);
  digitalWriteFast(B_RST, HIGH); 
  B_RS = RS;
  B_WR = WR;
  B_CS = CS;
  B_RST = RST;
}

void SSD1963::LCD_Writ_Bus16(uint16_t data)
{
    digitalWriteFast(B_RS, HIGH); 
    ((data & 0x8000) != 0) ? digitalWriteFast(DB_15, HIGH) : digitalWriteFast(DB_15, LOW);
    ((data & 0x4000) != 0) ? digitalWriteFast(DB_14, HIGH) : digitalWriteFast(DB_14, LOW);
    ((data & 0x2000) != 0) ? digitalWriteFast(DB_13, HIGH) : digitalWriteFast(DB_13, LOW);
    ((data & 0x1000) != 0) ? digitalWriteFast(DB_12, HIGH) : digitalWriteFast(DB_12, LOW);
    ((data & 0x0800) != 0) ? digitalWriteFast(DB_11, HIGH) : digitalWriteFast(DB_11, LOW);
    ((data & 0x0400) != 0) ? digitalWriteFast(DB_10, HIGH) : digitalWriteFast(DB_10, LOW);
    ((data & 0x0200) != 0) ? digitalWriteFast(DB_9, HIGH) : digitalWriteFast(DB_9, LOW);
    ((data & 0x0100) != 0) ? digitalWriteFast(DB_8, HIGH) : digitalWriteFast(DB_8, LOW);
    ((data & 0x80) != 0) ? digitalWriteFast(DB_7, HIGH) : digitalWriteFast(DB_7, LOW);
    ((data & 0x40) != 0) ? digitalWriteFast(DB_6, HIGH) : digitalWriteFast(DB_6, LOW);
    ((data & 0x20) != 0) ? digitalWriteFast(DB_5, HIGH) : digitalWriteFast(DB_5, LOW);
    ((data & 0x10) != 0) ? digitalWriteFast(DB_4, HIGH) : digitalWriteFast(DB_4, LOW);
    ((data & 0x08) != 0) ? digitalWriteFast(DB_3, HIGH) : digitalWriteFast(DB_3, LOW);
    ((data & 0x04) != 0) ? digitalWriteFast(DB_2, HIGH) : digitalWriteFast(DB_2, LOW);
    ((data & 0x02) != 0) ? digitalWriteFast(DB_1, HIGH) : digitalWriteFast(DB_1, LOW);
    ((data & 0x01) != 0) ? digitalWriteFast(DB_0, HIGH) : digitalWriteFast(DB_0, LOW);
   
    digitalWriteFast(B_WR, LOW); 
    digitalWriteFast(B_WR, HIGH); 
}

void SSD1963::LCD_Writ_Bus(char ch,char cl)
{
    ((ch & 0x80) != 0) ? digitalWriteFast(DB_15, HIGH) : digitalWriteFast(DB_15, LOW);
    ((ch & 0x40) != 0) ? digitalWriteFast(DB_14, HIGH) : digitalWriteFast(DB_14, LOW);
    ((ch & 0x20) != 0) ? digitalWriteFast(DB_13, HIGH) : digitalWriteFast(DB_13, LOW);
    ((ch & 0x10) != 0) ? digitalWriteFast(DB_12, HIGH) : digitalWriteFast(DB_12, LOW);
    ((ch & 0x08) != 0) ? digitalWriteFast(DB_11, HIGH) : digitalWriteFast(DB_11, LOW);
    ((ch & 0x04) != 0) ? digitalWriteFast(DB_10, HIGH) : digitalWriteFast(DB_10, LOW);
    ((ch & 0x02) != 0) ? digitalWriteFast(DB_9, HIGH) : digitalWriteFast(DB_9, LOW);
    ((ch & 0x01) != 0) ? digitalWriteFast(DB_8, HIGH) : digitalWriteFast(DB_8, LOW);
    ((cl & 0x80) != 0) ? digitalWriteFast(DB_7, HIGH) : digitalWriteFast(DB_7, LOW);
    ((cl & 0x40) != 0) ? digitalWriteFast(DB_6, HIGH) : digitalWriteFast(DB_6, LOW);
    ((cl & 0x20) != 0) ? digitalWriteFast(DB_5, HIGH) : digitalWriteFast(DB_5, LOW);
    ((cl & 0x10) != 0) ? digitalWriteFast(DB_4, HIGH) : digitalWriteFast(DB_4, LOW);
    ((cl & 0x08) != 0) ? digitalWriteFast(DB_3, HIGH) : digitalWriteFast(DB_3, LOW);
    ((cl & 0x04) != 0) ? digitalWriteFast(DB_2, HIGH) : digitalWriteFast(DB_2, LOW);
    ((cl & 0x02) != 0) ? digitalWriteFast(DB_1, HIGH) : digitalWriteFast(DB_1, LOW);
    ((cl & 0x01) != 0) ? digitalWriteFast(DB_0, HIGH) : digitalWriteFast(DB_0, LOW);

    digitalWriteFast(B_WR, LOW); 
    digitalWriteFast(B_WR, HIGH); 
}

void SSD1963::LCD_Write_DATA(char VL)
{
    digitalWriteFast(B_RS, HIGH); 
		LCD_Writ_Bus(0x00,VL);

}

void SSD1963::LCD_Write_DATA(char VH,char VL)
{
    digitalWriteFast(B_RS, HIGH); 
		LCD_Writ_Bus(VH,VL);
}

void SSD1963::LCD_Write_COM(char VL)  
{   
    digitalWriteFast(B_RS, LOW); 
		LCD_Writ_Bus(0x00,VL);

}

void SSD1963::InitLCD(void)
{

  digitalWriteFast(B_RST, LOW); 
	delay(10);

  digitalWriteFast(B_RST, HIGH); 
	delay(10);

  digitalWriteFast(B_CS, LOW); 

  LCD_Write_COM(0xE2);		//PLL multiplier, set PLL clock to 120M
	LCD_Write_DATA(0x1E);	    //N=0x36 for 6.5M, 0x23 for 10M crystal
	LCD_Write_DATA(0x02);
	LCD_Write_DATA(0x54);
	LCD_Write_COM(0xE0);		// PLL enable
	LCD_Write_DATA(0x01);
	delay(10);
	LCD_Write_COM(0xE0);
	LCD_Write_DATA(0x03);
	delay(10);
	LCD_Write_COM(0x01);		// software reset
	delay(50);
	LCD_Write_COM(0xE6);		//PLL setting for PCLK, depends on resolution
	LCD_Write_DATA(0x03);
	LCD_Write_DATA(0xFF);
	LCD_Write_DATA(0xFF);

	LCD_Write_COM(0xB0);		//LCD SPECIFICATION
	LCD_Write_DATA(0x24);
	LCD_Write_DATA(0x00);
	LCD_Write_DATA(0x03);		//Set HDP	799
	LCD_Write_DATA(0x1F);
	LCD_Write_DATA(0x01);		//Set VDP	479
	LCD_Write_DATA(0xDF);
	LCD_Write_DATA(0x00);

	LCD_Write_COM(0xB4);		//HSYNC
	LCD_Write_DATA(0x03);		//Set HT	928
	LCD_Write_DATA(0xA0);
	LCD_Write_DATA(0x00);		//Set HPS	46
	LCD_Write_DATA(0x2E);
	LCD_Write_DATA(0x30);		//Set HPW	48
	LCD_Write_DATA(0x00);		//Set LPS	15
	LCD_Write_DATA(0x0F);
	LCD_Write_DATA(0x00);

	LCD_Write_COM(0xB6);		//VSYNC
	LCD_Write_DATA(0x02);		//Set VT	525
	LCD_Write_DATA(0x0D);
	LCD_Write_DATA(0x00);		//Set VPS	16
	LCD_Write_DATA(0x10);
	LCD_Write_DATA(0x10);		//Set VPW	16
	LCD_Write_DATA(0x00);		//Set FPS	8
	LCD_Write_DATA(0x08);

	LCD_Write_COM(0xBA);
	LCD_Write_DATA(0x0F);		//GPIO[3:0] out 1

	LCD_Write_COM(0xB8);
	LCD_Write_DATA(0x07);	  //GPIO3=input, GPIO[2:0]=output
	LCD_Write_DATA(0x01);		//GPIO0 normal

	LCD_Write_COM(0x36);		//rotation
	//LCD_Write_DATA(0x22);
  LCD_Write_DATA(0x08);

	LCD_Write_COM(0xF0);		//pixel data interface
	LCD_Write_DATA(0x03);   // 011 16-bit (565 format)

	delay(10);

	LCD_Write_COM(0x29);		//display on

	LCD_Write_COM(0xBE);		//set PWM for B/L
	LCD_Write_DATA(0x06);
	LCD_Write_DATA(0xf0);
	LCD_Write_DATA(0x01);
	LCD_Write_DATA(0xf0);
	LCD_Write_DATA(0x00);
	LCD_Write_DATA(0x00);

	LCD_Write_COM(0xd0); 
	LCD_Write_DATA(0x0d);	

	LCD_Write_COM(0x2C); 

  digitalWriteFast(B_CS, HIGH); 

}

void SSD1963::setBackColor(byte r, byte g, byte b)
{
	bch=((r&248)|g>>5);
	bcl=((g&28)<<3|b>>3);

}
void SSD1963::setColor(byte r, byte g, byte b)
{
	fch=((r&248)|g>>5);
	fcl=((g&28)<<3|b>>3);
}

void SSD1963::setXY(word x1, word y1, word x2, word y2)
{
   
	LCD_Write_COM(0x2a); 
 	LCD_Write_DATA(x1>>8);
 	LCD_Write_DATA(x1);
 	LCD_Write_DATA(x2>>8);
 	LCD_Write_DATA(x2);
	LCD_Write_COM(0x2b); 
 	LCD_Write_DATA(y1>>8);
 	LCD_Write_DATA(y1);
 	LCD_Write_DATA(y2>>8);
 	LCD_Write_DATA(y2);
	LCD_Write_COM(0x2c); 

}


void SSD1963::_fast_fill_16(int ch, int cl, long pix)
{
	long blocks;

		((ch & 0x80) != 0) ? digitalWriteFast(DB_15, HIGH) : digitalWriteFast(DB_15, LOW);
		((ch & 0x40) != 0) ? digitalWriteFast(DB_14, HIGH) : digitalWriteFast(DB_14, LOW);
		((ch & 0x20) != 0) ? digitalWriteFast(DB_13, HIGH) : digitalWriteFast(DB_13, LOW);
		((ch & 0x10) != 0) ? digitalWriteFast(DB_12, HIGH) : digitalWriteFast(DB_12, LOW);
		((ch & 0x08) != 0) ? digitalWriteFast(DB_11, HIGH) : digitalWriteFast(DB_11, LOW);
		((ch & 0x04) != 0) ? digitalWriteFast(DB_10, HIGH) : digitalWriteFast(DB_10, LOW);
		((ch & 0x02) != 0) ? digitalWriteFast(DB_9, HIGH) : digitalWriteFast(DB_9, LOW);
		((ch & 0x01) != 0) ? digitalWriteFast(DB_8, HIGH) : digitalWriteFast(DB_8, LOW);
		((cl & 0x80) != 0) ? digitalWriteFast(DB_7, HIGH) : digitalWriteFast(DB_7, LOW);
		((cl & 0x40) != 0) ? digitalWriteFast(DB_6, HIGH) : digitalWriteFast(DB_6, LOW);
		((cl & 0x20) != 0) ? digitalWriteFast(DB_5, HIGH) : digitalWriteFast(DB_5, LOW);
		((cl & 0x10) != 0) ? digitalWriteFast(DB_4, HIGH) : digitalWriteFast(DB_4, LOW);
		((cl & 0x08) != 0) ? digitalWriteFast(DB_3, HIGH) : digitalWriteFast(DB_3, LOW);
		((cl & 0x04) != 0) ? digitalWriteFast(DB_2, HIGH) : digitalWriteFast(DB_2, LOW);
		((cl & 0x02) != 0) ? digitalWriteFast(DB_1, HIGH) : digitalWriteFast(DB_1, LOW);
		((cl & 0x01) != 0) ? digitalWriteFast(DB_0, HIGH) : digitalWriteFast(DB_0, LOW);

	  blocks = pix/16;
	  for (int i=0; i<blocks; i++)
	  {
 
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
        digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
	}
  
	if ((pix % 16) != 0)
		for (int i=0; i<(pix % 16); i++)
		{
      digitalWriteFast(B_WR, LOW); digitalWriteFast(B_WR, HIGH);
		}
}

void SSD1963::fillRect(int x1, int y1, int x2, int y2)
{
  uint16_t temp;
	if (x1>x2)
	{
    temp = x1;
    x1=x2;
    x2 = temp;
	}
	if (y1>y2)
	{
    temp = y1;
    y1 = y2;
    y2 =temp;
	}

    digitalWriteFast(B_CS, LOW); 
		setXY(x1, y1, x2, y2);
    digitalWriteFast(B_RS, HIGH); 

		_fast_fill_16(fch,fcl,((long(x2-x1)+1)*(long(y2-y1)+1)));

    digitalWriteFast(B_CS, HIGH); 
	
}

void SSD1963::writeRect(int16_t x, int16_t y, int16_t w, int16_t h, const uint16_t *pcolors)
{
    digitalWriteFast(B_CS, LOW); 

    setXY(x, y, x+w-1, y+h-1);
    for(y=h; y>0; y--) {
      for(x=w; x>1; x--) {
        LCD_Writ_Bus16(*pcolors++);
      }
      LCD_Writ_Bus16(*pcolors++);
    }
    
    digitalWriteFast(B_CS, HIGH); 
}

void SSD1963::drawLine(int x1, int y1, int x2, int y2)
{
		unsigned int	dx = (x2 > x1 ? x2 - x1 : x1 - x2);
		short			xstep =  x2 > x1 ? 1 : -1;
		unsigned int	dy = (y2 > y1 ? y2 - y1 : y1 - y2);
		short			ystep =  y2 > y1 ? 1 : -1;
		int				col = x1, row = y1;

    digitalWriteFast(B_CS, LOW); 
		if (dx < dy)
		{
			int t = - (dy >> 1);
			while (true)
			{
        setXY (col, row, col, row);
				LCD_Write_DATA (fch, fcl);
				if (row == y2)
					return;
				row += ystep;
				t += dx;
				if (t >= 0)
				{
					col += xstep;
					t   -= dy;
				}
			} 
		}
		else
		{
			int t = - (dx >> 1);
			while (true)
			{
				setXY (col, row, col, row);
				LCD_Write_DATA (fch, fcl);
				if (col == x2)
					return;
				col += xstep;
				t += dy;
				if (t >= 0)
				{
					row += ystep;
					t   -= dx;
				}
			} 
		}

    digitalWriteFast(B_CS, HIGH); 
}




