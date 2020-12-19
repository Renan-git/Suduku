#include<stdlib.h>
#include<stdio.h>
#include"mecanica.h"


int main ()
{
int x[TAM],y[TAM],z[TAM],i,j,achou=1;
int **suduku;
suduku=criaMapa(suduku,TAM,TAM);
carregaMapa(suduku,TAM,TAM);

while(achou)
{
achou=0;
for (i=0;i<TAM;i++)
	for (j=0;j<TAM;j++)
		if(suduku[i][j]==0)
		{
			achou=1;
			Search(suduku,i,j);
		}
}
printMapa(suduku,TAM,TAM);

limpaMapa(suduku,TAM);
return 0;
}

