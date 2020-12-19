#include<stdlib.h>
#include<stdio.h>
#include"mecanica.h"

void printSuduku(int **matriz)
{
int i,j;
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("[%d]",matriz[i][j]);
		printf("\n");
	}
}
int carregaMapa(int  **mapa,int linha,int coluna)
{
	int i,j;
	FILE *ArqMapa;
	ArqMapa=fopen("Mapa.txt","r");
	for(i=0;i<linha;i++)
		for(j=0;j<coluna;j++)
			fscanf(ArqMapa," %d",&mapa[i][j]);
fclose(ArqMapa);
return 0;
}

int** criaMapa(int **mapa,int linha,int coluna)
{
int i;
	mapa = malloc (linha * sizeof (int*)) ;
	for (i=0; i < linha; i++)
	mapa[i] = malloc (coluna * sizeof (int)) ;
return mapa;
}

int printMapa(int **mapa,int linha,int coluna)
{
int i,j;
	for (i=0;i<linha;i++)
	{	for (j=0;j<coluna;j++)
			printf("[%d]",mapa[i][j]);
		printf("\n");
	}
return 0;
}
void limpaMapa(int **mapa,int lin)
{
int i,j;
for (i=0;i<lin;i++)
	free(mapa[i]);
free(mapa);
}
void zeravetor(int v[],int tam)
{
int i;
for (i=0;i<tam;i++)
	v[i]=0;
}
void searchx(int *mapa,int v[],int tam)
{
int aux;
for(aux=0;aux<tam;aux++)
	if(mapa[aux])	
		v[mapa[aux]-1]=1;
}
void searchy(int **mapa,int v[],int tam,int j)
{
int aux;
for(aux=0;aux<tam;aux++)
	if(mapa[aux][j])	
		v[mapa[aux][j]-1]=1;
}
void searchz(int **mapa,int v[],int tam,int i,int j)
{
int aux=0,aux1,aux2,x=((i/3)*3),y=((j/3)*3);

for(aux1=0;aux1<3;aux1++)
{	for(aux2=0;aux2<3;aux2++)
	{
		if(mapa[x][y])
			v[mapa[x][y]-1]=1;
		x++;aux++;
	}y++;x=(i/3)*3;
}
}

int result (int x[],int y[],int z[],int r[],int tam)
{
int i;
for(i=0;i<tam;i++)
	if (!(x[i] || y[i] || z[i]))
		r[i]=1;

return 0;
}

int Search(int **mapa,int i,int j)
{
int x[TAM],y[TAM],z[TAM],r[TAM],aux,p=0;

zeravetor(x,TAM);zeravetor(y,TAM);zeravetor(z,TAM);zeravetor(r,TAM);

searchx(mapa[i],x,TAM);
searchy(mapa,y,TAM,j);
searchz(mapa,z,TAM,i,j);

result(x,y,z,r,TAM);

p=r[0]+r[1]+r[2]+r[3]+r[4]+r[5]+r[6]+r[7]+r[8];

if(p==1)
	for(aux=0;aux<TAM;aux++)
		if(r[aux])
		mapa[i][j]=(aux+1);

return 0;
}
