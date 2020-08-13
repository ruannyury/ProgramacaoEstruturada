#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "funcvet.h"

int main(){
int vetor[1000];
int numElementos;
int numAtual;
printf("Digite a quantidade de elementos: ");
scanf("%d", &numElementos);
for (numAtual=0;numAtual<numElementos;numAtual++){
printf("V[%d]: ",numAtual);
scanf("%d", &vetor[numAtual]);
}
ordemCrescente(vetor,numElementos);
impressao(vetor,numElementos);
printf("O maior valor e: %d", maiorvalor(vetor,numElementos));
printf("\nO menor valor e: %d", menorvalor(vetor));
printf("\nA amplitude e: %d", amplitude(vetor[0],maiorvalor(vetor,numElementos)));
printf("\nMedia e: %f", media(vetor,numElementos));
printf("\nA mediana e: %.2f", mediana(vetor,numElementos));
printf("\nO desvio padrao e; %f", desvioPadrao(vetor,numElementos,media(vetor,numElementos)));
frequencia(vetor, numElementos);
} 
