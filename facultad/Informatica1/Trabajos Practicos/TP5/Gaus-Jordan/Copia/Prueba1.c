#include<stdio.h>
#define N 3
int i,j,k,col,fila;
char op,op1,op2; 
float v[N][N+1]={0} /*b[N][N+1]={0}*/;


void pidedatos()
{
	printf("Programa para resolver sistemas de ecuaciones de hasta 10000*10000 incognitas");
	printf("\nIngrese los Valores: ");
	printf("\n\n");
	
	for(i=0; i<=N-1 ;i++)
	{
		for(j=0; j<=N; j++)
		{
			printf("M%d:",i);	
			printf("[%d][%d] = ",i,j);
			scanf("%f",&v[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


void gaussjordan()
{
	for(i=0; i<=N-1; i++)
	{
		for(j=N; j>=0; j--)
		{
			v[i][j]=v[i][j]/v[i][i];
			/*b[i][j]=a[i][j];*/
			
		}
		for(k=i+1; k<=N-1; k++)
		{
			for(j=N; j>=0; j--)
			{
				v[k][j]=v[k][j]-v[k][i]*v[i][j];
			}
		}
		for(k=0; k<=i-1; k++)
		{
			for(j=N; j>=0; j--)
			{
				v[k][j]=v[k][j]-v[k][i]*v[i][j];
			}
		}
	}
}


void mat_imp(){
	printf("\nSu matriz es: \n\n");
	for(i=0; i<=N-1; i++)
	{
		for(j=0; j<=N; j++)
		{
			printf("|%.1f|",v[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


void correjir(){
	do{
		printf("\nHay algun error? s/n: ");
		scanf("%s",&op2);
		if(op2 == 's')
		{
			do{
				printf("\nSeleccione la fila ---> ");
				printf("   [i] = ");
				scanf("%d",&fila);
				printf("\nSeleccione la columna ---> ");
				printf("[j] = ");
				scanf("%d",&col);
				printf("\nQue valor es?: ");
				scanf("%f",&v[fila][col]);
				printf("\nTiene otro error? s/n: ");
				scanf("%s",&op);
			}while(op == 's');
			mat_imp();
		}
	}while(op == 's');
	printf("\n");
}


void imprime()
{
	
	printf("Excelente!\n");	
	
	printf("\nSu matriz reducida es: \n\n");
	for(i=0; i<=N-1; i++)
	{
		for(j=0; j<=N; j++)
		{
			printf("|%.1f|",v[i][j]);
		}
		printf("\n");
	}

	
	printf("\n\nSus resultados son:\n");
	for(i=0; i<=N-1; i++)
	{
		printf("\nX[%d] = %.1f",i,v[i][N]);
	}
	printf("\n\n");
}


int main()
{
	
	char op;
	do
	{
		pidedatos();
		mat_imp();
		correjir();
		gaussjordan();
		imprime();
		printf("Quieres otro calculo?\ns/n ");
		scanf("%s",&op);
	}
	
	while(op=='s');
	printf("\n\n");
	
	return 0;
}
