/*
    PROJETO DE PROGRAMAÇÃO ESTRUTURADA
    *****P5 DE INFORMÁTICA*****
    ALUNOS: RAFAEL PINHEIRO, AMANDA SÁ, ISRAEL LEITE, RUANN YURY
    PROFESSOR: DAVIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "funcvet.h"

typedef struct {
    char nome[31];
    int idade;
    int nota;
    int codigo;
}registro_aluno;

int main(){

    setlocale(LC_ALL, "Portuguese");

    int numElementos;
    int numAtual;

    puts("****PROJETO DE PROGRAMAÇÃO ESTRUTURADA!!!****");
    puts("\nEsse programa irá fazer cálculos estatísticos com os dados obtidos.");
    puts("Dados: EM QUANTAS PROVAS O ALUNO TIROU NOTA ALTA (IGUAL OU SUPERIOR À MÉDIA 6).");

    printf("\nDigite quantos alunos responderam à pesquisa: ");
    scanf("%d", &numElementos);

    int vetor[numElementos];

    for (numAtual=0;numAtual<numElementos;numAtual++){
        printf("Em quantas provas o aluno %d tirou notas igual ou acima da média: ", numAtual + 1);
        scanf("%d", &vetor[numAtual]);
    }

    ordemCrescente(vetor,numElementos);
    impressao(vetor,numElementos);

    puts("******EIS AS ESTATÍSTICAS DOS DADOS:******");

    printf("\nO maior valor é: %d", maiorvalor(vetor,numElementos));
    printf("\nO menor valor é: %d", menorvalor(vetor));
    printf("\nA amplitude é: %d", amplitude(vetor[0],maiorvalor(vetor,numElementos)));
    printf("\nA média é: %f", media(vetor,numElementos));
    printf("\nA mediana é: %.2f", mediana(vetor,numElementos));
    printf("\nO desvio padrão é: %f\n", desvioPadrao(vetor,numElementos,media(vetor,numElementos)));

    frequencia(vetor, numElementos);
} 
