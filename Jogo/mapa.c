#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

int ehParede(MAPAJOGO* p, int x, int y) {
    return 
        p->matriz[x][y] == PAREDE_VERTICAL || 
        p->matriz[x][y] == PAREDE_HORIZONTAL;

}

int ehPersonagem(MAPAJOGO* p, char personagem, int x, int y){
    return
        p->matriz[x][y] == personagem;
}

int podeAndar(MAPAJOGO* p, char personagem, int x, int y) {
    return verificaLimiteMapa(p, x, y) && !ehParede(p, x, y) && !ehPersonagem(p, personagem, x, y);
}

void copiaMapa(MAPAJOGO* copia, MAPAJOGO* copiado){
    copia->linhas = copiado->linhas;
    copia->colunas = copiado->colunas;

    alocaMapa(copia);
    for(int i=0; i < copiado->linhas;i++){
        strcpy(copia->matriz[i],copiado->matriz[i]);

    }
}

void andaNoMapa(MAPAJOGO* p, int xorigem, int yorigem, 
    int xdestino, int ydestino) {

        char personagem = p-> matriz[xorigem][yorigem];
        p->matriz[xdestino][ydestino] = personagem;
        p->matriz[xorigem][yorigem] = POSICAOVAZIA;
}

int verificaPosicaoVazia(MAPAJOGO* p, int x, int y){
    return p->matriz[x][y] == POSICAOVAZIA;

}

int verificaLimiteMapa(MAPAJOGO* p, int x, int y) {
    
    if(x >= p->linhas){
        return 0;
    }
    if(y >= p->colunas){
        return 0;
    }

    return 1;

}

int encontraPersonagem(MAPAJOGO* mapa, POSICAO* posicao, char c) {
    for(int i = 0; i < mapa->linhas; i++) {
        for(int j = 0; j < mapa->colunas; j++) {
            if(mapa->matriz[i][j] == c) {
                posicao->x = i;
                posicao->y = j;
                return 1; 
            }
        }
    }
    return 0;
}

void alocaMapa(MAPAJOGO* p) {
    p->matriz = malloc(sizeof(char*) * p->linhas);
    for (int i = 0; i < p->linhas; i++) {
        p->matriz[i] = malloc(sizeof(char) * (p->colunas + 1)); 
    }
}

void lerMapa(MAPAJOGO* p) {
    FILE* f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("Erro ao ler o arquivo do mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(p->linhas), &(p->colunas));
    alocaMapa(p);

    for (int i = 0; i < p->linhas; i++) {
        fscanf(f, "%s", p->matriz[i]);
    }

    fclose(f);
}

void liberaMapa(MAPAJOGO* p) {
    for (int i = 0; i < p->linhas; i++) {
        free(p->matriz[i]);
    }
    free(p->matriz);
}
