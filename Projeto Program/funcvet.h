#include <stdio.h>
#include <locale.h>
#include <math.h>

void impressao(int vetor[], int qtd){ 
	
	printf("DADOS ORDENADOS:\n");
    for (int x=0; x < qtd ; x++)
    printf("V[%d]: %d \n", x, vetor[x]); 
}

void troca(int *A, int *B){ 
	
	int temp;
    temp = *A;
    *A = *B;
    *B = temp; 
}
 
void ordemCrescente(int vetor[], int n){

    int i, j, temp;
    for (i=0; i<n; i++){
        for(j = i + 1; j < n; j++){
     		if(vetor[i] > vetor[j]){
     		    temp = vetor[i];
     			vetor[i] = vetor[j];
     			vetor[j] = temp;
			}
	    }
	}

}

int menorvalor (int vetor[]){
	
	int menor;
	menor = vetor[0];
	return menor;
}

int maiorvalor(int vetor[], int numeroElementos){
	
	int maior;
	maior = vetor [numeroElementos-1];
	return maior;
}

int amplitude(int menor, int maior){
	
	int resultado = maior - menor;
	return resultado;
}

float media(int vetor[], int numeroElementos){
	
	float resultado;
	float soma = 0;
	int numAtual;
	for(numAtual = 0 ; numAtual < numeroElementos ; numAtual++)
	soma += vetor[numAtual];
	resultado = soma / numeroElementos;
	return resultado;
}

float mediana(int vetor[], int numeroElementos){
	
	float valormedio, resultado;
	int valorAnt, valorPost, mediointeiro;

	if (numeroElementos%2 == 0){
		valorPost = numeroElementos / 2;
		valorAnt = valorPost - 1;
		valormedio = (vetor[valorPost] + vetor[valorAnt]) / 2.0;
		resultado = valormedio;
	}
	else 
	{
		valormedio = (numeroElementos/2)+0.5;
	    mediointeiro = valormedio;
	    resultado = vetor[mediointeiro];
	}
	return resultado;
}

float desvioPadrao (int vetor[], int numeroElementos, float media){
	
	int numAtual;
	float soma, resultado;

	for(numAtual=0 ; numAtual < numeroElementos ; numAtual++)
	    soma += pow(vetor[numAtual] - media, 2);
	resultado = sqrt(soma / numeroElementos);

	return resultado;
}

void frequencia (int Vetor[],int numeroElementos){
	
	int valorAtual = Vetor[0], contador = 0, numeroVezes = 1;

	while (contador < numeroElementos){
		contador++;
		if (Vetor[contador]==valorAtual)
		    numeroVezes++;
		else{
		    printf("\nFrequencia do valor %d = %d\n",valorAtual,numeroVezes);
		    valorAtual= Vetor[contador];
		    numeroVezes = 1; 
		}
	}	
}
