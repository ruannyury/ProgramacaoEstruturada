/*
    PROJETO DE PROGRAMAÇÃO ESTRUTURADA
    *****P5 DE INFORMÁTICA*****
    ALUNOS: RAFAEL PINHEIRO, AMANDA SÁ, ISRAEL LEITE, RUANN YURY, TIAGO DE TARSO
    PROFESSOR: DAVIS
*/

#include <stdio.h> // Biblioteca padrão
#include <stdlib.h> // Biblioteca necessária pra função system()
#include <string.h> // Biblioteca necessária pra função strcpy()
#include <math.h> // Biblioteca necessária pras funções sqrt() e pow()
#include <locale.h> // Biblioteca necessária pra linguagem pt-br
#include "funcvet.h" // Funções estatísticas

// DEFINIÇÃO DAS ESTRUTURAS:
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

typedef struct{
    int codigo;
    int idade;
    int notaAlta;
}registro_dadospessoa;


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

    registro_nota nota[numElementos]; /* Declara uma variável vetor estrutura do tipo 
                                         registro_nota com o número de elementos igual
                                         ao número de alunos. */
   
    int e = 5, j = 10; // Variáveis responsáveis pelo código de cada nota e de cada aluno, respectivamente

    for(int i = 0; i < numElementos; ++i){ // Roda o loop tanto quanto for o número de alunos na sala
        /*
            Armazenando cada nome da variável nome_sobrenome na variável 
            pessoa[i].nomeString com a função strcpy():
        */
        printf("Nome e sobrenome do aluno %d: ", i + 1); scanf(" %[^\n]", nome_sobrenome);

        pessoa[i].codigo = j; strcpy(pessoa[i].nomeString, nome_sobrenome);

        /*
            Armazenando cada idade da variável idade_aluno na variável 
            idade[i].codigo:
        */
        printf("Idade: "); scanf("%d", &idade_aluno);
        idade[i].codigo = i + 1; idade[i].idade = idade_aluno; 

        /*
            Armazenando as notas desses alunos em vetor_notas e em nota[i].notaAlta:
        */
        printf("Número de notas iguais ou superiores à média 6: "); scanf(" %d", &vetor_notas[i]);
        
        nota[i].codigo = e; nota[i].notaAlta = vetor_notas[i];

        e += 5; // Encrementa a variável responsável pelo código de cada nota
        j += 10; // Encrementa a variável responsável pelo código de cada aluno

        
    }    

    registro_dadospessoa dados[numElementos]; /* Declara uma variável vetor estrutura do tipo 
                                                 registro_dadospessoa com o número de elementos igual
                                                 ao número de alunos. */

    for (int i = 0; i < numElementos; i++){
        dados[i].codigo = pessoa[i].codigo; dados[i].idade = idade[i].codigo; dados[i].notaAlta = nota[i].codigo;
    }/*         ^                                         ^                                  ^ 
                |                                         |                                  |
                |                    ----------------------       ----------------------------
                |                    |                            |
        dados[i].codigo = 10; dados[i].idade = 1; dados[i].notaAlta = 5;
        dados[i].codigo = 20; dados[i].idade = 2; dados[i].notaAlta = 10;
        dados[i].codigo = 30; dados[i].idade = 3; dados[i].notaAlta = 15;
        dados[i].codigo = 50; dados[i].idade = 4; dados[i].notaAlta = 20;
        dados[i].codigo = 60; dados[i].idade = 5; dados[i].notaAlta = 25;
                .                     .                   .
                .                     .                   .
                .                     .                   .
                .                     .                   .  repete num número de vezes
                                                             igual a numElementos

    */

    system("clear"); // Limpa a tela

    printf("\n!=== PESSOAS E SEUS DADOS ===!");
    printf("\n");

    int x, y, z, w; // Variáveis controladoras dos loops principal e menores

    x = 0;
    while(x <= numElementos){ // O loop principal rodará tanto quanto for o número de alunos na sala
        y = 0;
        while (y <= numElementos){ // Loop para mostrar o nome do aluno em questão

            if(dados[x].codigo == pessoa[y].codigo)
                printf("%s, de idade ", pessoa[y].nomeString);
            y++;
        }
        z = 0;
        while(z <= numElementos){ // Loop para mostrar a idade do aluno em questão
            
            if(dados[x].idade == idade[z].codigo)
                printf("%d, teve ", idade[z].idade);
            z++;

        }
        w = 0;
        while(w <= numElementos){ // Loop para mostrar quantas notas altas esse aluno em questão conseguiu

            if(dados[x].notaAlta == nota[w].codigo)
                printf("%d notas altas\n", nota[w].notaAlta);
            w++;

        }
        
        x++;
    }

    // Declara as variáveis que armazenaram os resultados estatísticos
    float Media, Mediana, Amplitude, MaiorValor, MenorValor;
    float DesvioPadrao;

    // Ordena o vetor 'vetor_notas' e em seguida o imprime de forma ordenada
    ordemCrescente(vetor_notas, numElementos);
    impressao(vetor_notas, numElementos);

    // Armazenando nas variáveis os resultados das funções quando passados seus parâmetros
    Media = media(vetor_notas, numElementos);
    Mediana = mediana(vetor_notas, numElementos);
    MaiorValor = maiorvalor(vetor_notas, numElementos);
    MenorValor = menorvalor(vetor_notas);
    Amplitude = amplitude(MenorValor, MaiorValor);
    DesvioPadrao = desvioPadrao(vetor_notas, numElementos, Media);

    // Mostrando os resultados com no máximo três casas decimais
    printf("\nMédia das notas: %.3f", Media);
    printf("\nMediana das notas: %.3f", Mediana);
    printf("\nMaior número de notas altas: %.3f", MaiorValor);
    printf("\nMenor número de notas altas: %.3f", MenorValor);
    printf("\nAmplitude: %.3f", Amplitude);
    printf("\nFrequência:\n");
    frequencia(vetor_notas, numElementos);

    return 0;

} 