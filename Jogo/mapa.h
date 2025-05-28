#ifndef _MAPA_H_
#define _MAPA_H_

#define PERSONAGEM '@'
#define POSICAOVAZIA '.'
#define FANTASMA 'F'
#define PILULA 'P'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapaJogo {
    char** matriz;
    int linhas, colunas;
};

typedef struct mapaJogo MAPAJOGO;

struct posicao{
    int x, y;
};

typedef struct posicao POSICAO;

void lerMapa(MAPAJOGO* p);
void liberaMapa(MAPAJOGO* p);
void alocaMapa(MAPAJOGO* p);
int encontraPersonagem(MAPAJOGO* mapa, POSICAO* posicao, char c);
int verificaLimiteMapa(MAPAJOGO* p, int x, int y);
int verificaPosicaoVazia(MAPAJOGO* p, int x, int y);
void andaNoMapa(MAPAJOGO* p, int xorigem, int yorigem, int xdestino, int ydestino);
void copiaMapa(MAPAJOGO* copia, MAPAJOGO* copiado);
int podeAndar(MAPAJOGO* p, char personagem, int x, int y) ;
int ehPersonagem(MAPAJOGO* p, char personagem, int x, int y);
int ehParede(MAPAJOGO* p, int x, int y);

#endif