#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v; // Ponteiro para o vetor que iremos alocar

    int tamanho_vetor; // Tamanho do vetor a ser alocado

    int i; // Variável de controle do FOR

    int valor; // Variável que irá guardar o valor temporário da posicao do vetor

    int pesquisa; // Variável que irá conter o elemento que estamos procurando

    int controle_pesquisa = 1; /* Variável de controle de pesquisa,
                                * identifica se o elemento foi encontrado */

    int inicio, meio, final; // Variáveis de controle do vetor durante a pesquisa binária

    printf("Digite um tamanho para o vetor: ");


    scanf("%d", &tamanho_vetor); // Recebe o tamanho do vetor


    v = (int *) malloc(tamanho_vetor * sizeof(int)); /* Aloca dinâmicamente
                                                      * o espaco de memoria do vetor */


    if (v == NULL) // Verifica se houve erro na alocacao de memoria
    {
        printf("Problema ao alocar vetor!");
        return(1);
    }
    else
    {
        for (i = 0; i < tamanho_vetor; i++) // Preenche o vetor
        {
            printf("Digite a posicao %d do vetor: ", i);
            scanf("%d", &valor);
            v[i] = valor;
        }


        printf("Digite o elemento que deseja pesquisa no vetor: "); /* Recebe o valor a
                                                                     * ser pesquisado no vetor */
        scanf("%d", &pesquisa);

        // Definição do inicio e do fim do vetor. (Fim do vetor é: seu_tamanho - 1 )
        inicio = 0;
        final = tamanho_vetor - 1;

        // Loop que irá realizar a pesquisa binária
        while (inicio <= final)
        {
            meio = (inicio + final) / 2;

            if (pesquisa == v[meio])
            {
                controle_pesquisa = 0;
                break;
            }

                /**
                * Se a pesquisa for menor que o meio do vetor,
                * então o fim do vetor será o meio atual -1
                */
            else if (pesquisa < v[meio])
            {
                final = meio - 1;
                continue;
            }

                /**
                * Se a pesquisa for maior que o meio do vetor, então a pesquisa
                * comecará a partir do meio atual do vetor
                */
            else if(pesquisa > v[meio])
            {
                inicio = meio + 1;
                continue;
            }

                /**
                * Caso nada seja encontrado, define o controle_pesquisa = 1
                */
            else
            {
                controle_pesquisa = 1;
                break;
            }

        }

        /**
        * Verificaçã da variavel de controle que indica se o elemento foi encontrado ou nao.
        * Se for 0, o elemento foi encontrado, caso contrário, o elemento nao foi
        * encontrado. Basta entao exibir as mensagens.
        */
        if (controle_pesquisa == 0){
            printf("Elemento %d encontrado! Posicao: %d - Valor: %d", pesquisa, meio, v[meio]);
        } else {
            printf("Elemento %d nao encontrado!", pesquisa);
        }

        return (0);

    }

}