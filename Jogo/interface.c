#include <stdio.h>
#include "mapa.h"

char desenhoparede[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenhofantasma[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhopersonagem[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void imprimeparte(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void imprimeMapa(MAPAJOGO* p){
	for(int i = 0; i < p->linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < p->colunas; j++) {

				switch(p->matriz[i][j]) {
					case FANTASMA:
						imprimeparte(desenhofantasma, parte);
						break;
					case PERSONAGEM:
						imprimeparte(desenhopersonagem, parte);
						break;
					case PILULA:
						imprimeparte(desenhopilula, parte);
						break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						imprimeparte(desenhoparede, parte);
						break;
					case POSICAOVAZIA:
						imprimeparte(desenhovazio, parte);
						break;
				}
				
			}
			printf("\n");
		}

	}
}