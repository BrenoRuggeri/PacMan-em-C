#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include "mapa.h"
#include "interface.h"

MAPAJOGO p;
POSICAO personagem;

int pegouPilula = 0;


int moveFantasma(int xatual,int yatual, int* xdestino, int* ydestino ){

  int opcoes[4][2] = { 
		{ xatual   , yatual+1 }, 
		{ xatual+1 , yatual   },  
		{ xatual   , yatual-1 }, 
		{ xatual-1 , yatual   }
	};

    srand(time(0));
    for (int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if (podeAndar(&p, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){

            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }
    return 0;
}

void andaFantasma(){

    MAPAJOGO copia;

    copiaMapa(&copia,&p);

     for(int i = 0; i < p.linhas; i++){
        for(int j = 0; j < p.colunas; j++){
            if (copia.matriz[i][j] == FANTASMA){
               
                int xdestino, ydestino;

                int achou = moveFantasma(i, j, &xdestino, &ydestino);

                if (achou){
                    andaNoMapa(&p, i, j, xdestino, ydestino);
                }
            }
        } 

     } 

     liberaMapa(&copia);
        
}

int ehDirecao(char direcao) {
    return direcao == 'a' || 
            direcao == 'w' || 
            direcao == 's' || 
            direcao == 'd';
        
}

void movePersonagem(char direcao) {

    if(!ehDirecao(direcao)){
        return;
    }

    int atualizaX = personagem.x, atualizaY = personagem.y;

    switch(direcao){
       
        case CIMA:
            atualizaX--;
            break;

        case ESQUERDA:
            atualizaY--;
            break;

        case BAIXO:
            atualizaX++;
            break;
            
        case DIREITA:
            atualizaY++;
            break;
        
    }

    if(!podeAndar(&p,PERSONAGEM, atualizaX, atualizaY)){
        return;
    }

    if(ehPersonagem(&p,PILULA, atualizaX, atualizaY)){
        pegouPilula = 1;
    }

    andaNoMapa(&p,personagem.x, personagem.y, 
        atualizaX, atualizaY);
        personagem.x = atualizaX;
        personagem.y = atualizaY;
    
}

int acabou() {

    POSICAO pos;

	int perdeu = !encontraPersonagem(&p, &pos, PERSONAGEM);
	int ganhou = !encontraPersonagem(&p, &pos, FANTASMA);

	return ganhou || perdeu;

}

void explode(){

    if(!pegouPilula) return;

    usaEspecial(personagem.x, personagem.y, 0, 1, 3);
    usaEspecial(personagem.x, personagem.y, 0, -1, 3);
    usaEspecial(personagem.x, personagem.y, 1, 0, 3);
    usaEspecial(personagem.x, personagem.y, -1, 0, 3);

    pegouPilula = 0;
}

void usaEspecial(int x, int y,int somax, int somay, int qtd){

    if (qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;

    if(!verificaLimiteMapa(&p,novox,novoy)) return;    
    if(ehParede(&p,novox,novoy)) return;

    p.matriz[novox][novoy] = POSICAOVAZIA;
    usaEspecial(novox, novoy,somax, somay, qtd -1);
}

int main() {

    lerMapa(&p);
    encontraPersonagem(&p, &personagem, PERSONAGEM);

    do{
        printf("Pegou pilula: %s\n",(pegouPilula ? "SIM" : "NÃO"));
        imprimeMapa(&p);
        char tecla;
        scanf(" %c", &tecla);
        movePersonagem(tecla);
        andaFantasma();

        if(tecla == ESPECIAL){
            explode();
        }

    }while(!acabou());

    liberaMapa(&p);
    
}
