#ifndef _JOGO_H_
#define _JOGO_H_

#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define ESPECIAL 'b'

void movePersonagem(char direcao);
int acabou();
int ehDirecao(char direcao);
void andaFantasma();
int moveFantasma(int xatual,int yatual, int* xdestino, int* ydestino);
void usaEspecial();
void explode();
void usaEspecial(int x, int y,int somax, int somay, int qtd);

#endif