#include <8051.h>
#define	dados_7seg 0xFFC0
#define select_display 0xFFC1
#define	CHT2	P3_4

static char far at dados_7seg dados; // variavel dados aponta para dados_7seg, far at sao palavras reservadas do compilador
int sw4State;
int n;
static char far at select_display display;
static __code unsigned char  phone[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};



void main(void) {
	display = 0x01;
	dados = 0x3F;
	sw4State = 0;
	n = 1;
	while (1) {
		if(!CHT2 && !sw4State) {
			sw4State = 1;

			dados = phone[n];
			n = n >= 15 ? 0: n+1;

			/*
			switch(n) {
				case 0: dados = 0x3F; break;
				case 1: dados = 0x06; break;
				case 2: dados = 0x5B; break;
				case 3: dados = 0x4F; break;
				case 4: dados = 0x66; break;
				case 5: dados = 0x6D; break;
				case 6: dados = 0x7D; break;
				case 7: dados = 0x07; break;
				case 8: dados = 0x7F; break;
				case 9: dados = 0x67; break;
				case 10: dados = 0x77; break;
				case 11: dados = 0x7C; break;
				case 12: dados = 0x39; break;
				case 13: dados = 0x5E; break;
				case 14: dados = 0x79; break;
				case 15: dados = 0x71;break;
			}
			*/

		}
		else if(CHT2 && sw4State){
			sw4State = 0;
		}
	}
}
