xdata at 0x8004 unsigned char LCD_CMD;
xdata at 0x8005 unsigned char LCD_DATA;

xdata at 0x9006 unsigned char KL1;
xdata at 0x9005 unsigned char KL2;
xdata at 0x9003 unsigned char KL3;

void delay16(unsigned int i) { do { } while(--i); }

main(){
	int position = 128;
	int shift = 0;
	delay16(30000); LCD_CMD = 0;
	
	delay16(150); LCD_CMD = position;
	delay16(150); LCD_DATA = 0x3C;
	delay16(10000);
	
	while(1){
		//bottom
		if(KL2 == 0xFB){
			delay16(30000); LCD_CMD = 0;
			if(position > 127 && position < 128+10){
				position += 40;
				shift += 40;
			}
			else if(position > 128+39 && position < 128+50){
				position -= 30;
				shift -= 30;
			}
			else if(position > 128+9 && position < 128+20){
				position += 40;
				shift += 40;
			}
			delay16(150); LCD_CMD = position;
			delay16(150); LCD_DATA = 0x76;
			delay16(10000);
		}
		//top
		if(KL2 == 0xFE){
			delay16(30000); LCD_CMD = 0;
			if(position > 128+39 && position < 128+50){
				position -= 40;
				shift -= 40;
			}
			else if(position > 128+9 && position < 128+20){
				position += 30;
				shift += 30;
			}
			else if(position > 128+49 && position < 128+60){
				position -= 40;
				shift -= 40;
			}
			delay16(150); LCD_CMD = position;
			delay16(150); LCD_DATA = 0x5E;
			delay16(10000);
		}
		//left
		if (KL1 == 0xFD){
			delay16(30000); LCD_CMD = 0;
			if(position > 128 + shift){
				position--;
			}
			delay16(150); LCD_CMD = position;
			delay16(150); LCD_DATA = 0x3C;
			delay16(10000);
			
		}
		//right
		if (KL3 == 0xFD){
			delay16(30000); LCD_CMD = 0;
			if(position < 137 + shift){
				position++;
			}
			delay16(150); LCD_CMD = position;
			delay16(150); LCD_DATA = 0x3E;
			delay16(10000);
			
		}
	}
	
}