#include<stdlib.h>
#include<stdio.h>
#include"mecanica.h"


int main ()
{
int x[TAM],y[TAM],z[TAM],i,j;
int **suduku;
suduku=criaMapa(suduku,TAM,TAM);
carregaMapa(suduku,TAM,TAM);
//printMapa(suduku,TAM,TAM);

//for (i=0;i<TAM;i++)
//	for (j=0;j<TAM;j++)
//		if(suduku[i][3j]==0)
			Search(suduku,4,5);

limpaMapa(suduku,TAM);
return 0;
}

