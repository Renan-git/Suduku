#ifndef  MECANICA_H
#define  MECANICA_H

#define TAM 9

void printSuduku(int **matriz);
int carregaMapa(int **mapa,int linha,int coluna);
int** criaMapa(int **mapa,int linha,int coluna);
int printMapa(int **mapa,int linha,int coluna);
void limpaMapa(int **mapa,int lin);
int Search(int **mapa,int i,int j);
void zeravetor(int v[],int tam);
void searchx(int *mapa,int v[],int tam);
void searchy(int **mapa,int v[],int tam,int j);
void searchz(int **mapa,int v[],int tam,int i,int j);


#endif  /*FILE_H*/
