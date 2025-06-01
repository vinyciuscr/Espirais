#include <stdlib.h> 
#include <stdio.h>

int main(){


    int direcao; //direção da "seta"
    int x = 0, y = 0; //ponto incial

    int step_size = 1; // o quanto cada direção irá se repetir
    int atual = 1; // variável auxiliar para a contagem dos steps
    int passagem = 0; // contagem de direções para a cada duas aumentar o número de steps
    int i = 0; // variável auxiliar
    int ponto_atual = 0; // variável auxiliar para cálcular até a entrada n
    int n; // entrada
    int f = 1; //flag para o loop

    scanf("%d",&n); //comando para entrada de n


    while(f){ //loop infinito

    if(n == 0){ //caso n seja a origem
        f = 0;
        break;
    }

    direcao = i % 4; //como são quatro direções que formam um ciclo. O módulo 4 indicada qual direção estamos com base na ordem: cima, esquerda, baixo, direita

        while(atual <= step_size){ //a variável faz o loop repetir até que o número de steps seja atingido
            if (direcao == 0) { // dependendo da direção ocorre o incremento ou decremento do valor de x ou y
                y = y + 1; 
            }
            if (direcao == 1) {
                x = x - 1;  
            }
            if (direcao == 2) {
                y = y - 1;  
            }
            if (direcao == 3) {
                x = x + 1;  
            }
        ponto_atual++; // a cada incremento/decremento se avança um ponto
        atual++; //o atual avança para a direção repetir até o número de steps
        if(ponto_atual == n){ //condicional para verificar se n já foi atingido
            f = 0; // caso seja verdadeiro, a flag irá passar a ser falsa e iremos sair do while
            break;
        }
        }

        passagem++; //o número de direções diferentes que andamos

        if(passagem % 2 == 0){ // a cada duas direções o número de steps é incrementado em 1
            step_size++;
        }

        atual = 1; //atual volta a ser 1 para poder auxiliar o novo número de steps
        i++; //incremento para mudar o módulo de 4, logo a direção.

    }

    printf("%d %d", x, y); //imprime as coordenadas de n

    return 0;
}
