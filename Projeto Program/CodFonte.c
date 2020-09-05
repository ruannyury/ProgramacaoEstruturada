/*
    PROJETO DE PROGRAMAÇÃO ESTRUTURADA
    *****P5 DE INFORMÁTICA*****
    ALUNOS: RAFAEL PINHEIRO, AMANDA SÁ, ISRAEL LEITE, RUANN YURY
    PROFESSOR: DAVIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "funcvet.h"

typedef struct {
    int codigo;
    char nomeString[31];
}registro_nome;

typedef struct{
    int codigo;
    int idade;
}registro_idade;

typedef struct{
    int codigo;
    int notaAlta;
}registro_nota;

int main(){

    setlocale(LC_ALL, "Portuguese");

    int numElementos; // Número de alunos na sala
    char nome_sobrenome[41]; // Onde serão armazenados os nomes dos alunos
    int idade_aluno; 

    puts("****PROJETO DE PROGRAMAÇÃO ESTRUTURADA!!!****");
    puts("\nEsse programa irá fazer cálculos estatísticos com os dados obtidos.");
    puts("Dados: EM QUANTAS PROVAS O ALUNO TIROU NOTA ALTA (IGUAL OU SUPERIOR À MÉDIA 6).");

    printf("Quantidade de alunos na classe: "); scanf("%d", &numElementos);
    printf("\n");

    int vetor_notas[numElementos]; // Vetor onde as notas dos alunos serão armazenadas

    registro_nome pessoa[numElementos]; /* Declara uma variável vetor estrutura do tipo 
                                           registro_nome com o número de elementos igual
                                           ao número de alunos. */

    registro_idade idade[numElementos]; /* Declara uma variável vetor estrutura do tipo 
                                           registro_idade com o número de elementos igual
                                           ao número de alunos. */
   
    int j = 10;

    for(int i = 0; i < numElementos; ++i){ // Roda o loop tanto quanto for o número de alunos na sala
        /*
            Armazenando cada nome da variável nome_sobrenome na variável 
            pessoa[i].nomeString com a função strcpy():
        */
        printf("Nome e sobrenome do aluno %d:\n", i + 1); scanf(" %[^\n]", nome_sobrenome);

        pessoa[i].codigo = j; strcpy(pessoa[i].nomeString, nome_sobrenome);

        /*
            Armazenando cada idade da variável idade_aluno na variável 
            idade[i].codigo:
        */
        printf("Idade: "); scanf("%d", &idade_aluno);
        idade[i].codigo = i + 1; idade[i].idade = idade_aluno; 

        /*
            Armazenando as notas desses alunos em vetor_notas:
        */
        printf("Número de notas iguais ou superiores à média 6: "); scanf(" %d", &vetor_notas[i]);
        
        j += 10; // Encrementa a variável responsável pelo código de cada aluno
        
    }    



    return 0;
} 
