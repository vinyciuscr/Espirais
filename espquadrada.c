#include <stdlib.h> 
#include <stdio.h>

int main(){

    int direcao;         // Indica a direção atual do movimento
    int x = 0, y = 0;    // Coordenadas do ponto atual (iniciando na origem)

    int step_size = 1;   // Quantidade de passos em uma mesma direção
    int atual = 1;       // Contador de passos dentro da direção atual
    int passagem = 0;    // Conta quantas direções diferentes já percorremos
    int i = 0;           // Controla qual direção será seguida (módulo 4)
    int ponto_atual = 0; // Conta quantos pontos já percorremos
    int n;               // Índice do ponto alvo (entrada do usuário)
    int f = 1;           // Flag de controle para encerrar o loop principal

    scanf("%d", &n);     // Leitura da entrada (índice do ponto desejado)

    while(f) {           // Loop principal: simula o avanço pela espiral

        if(n == 0) {     // Caso especial: origem (0, 0)
            f = 0;
            break;
        }

        direcao = i % 4; // Define a direção atual (0: ↑, 1: ←, 2: ↓, 3: →)

        // Executa os passos na direção atual
        while(atual <= step_size) {
            if (direcao == 0) y += 1;      // Cima
            if (direcao == 1) x -= 1;      // Esquerda
            if (direcao == 2) y -= 1;      // Baixo
            if (direcao == 3) x += 1;      // Direita

            ponto_atual++;   // Avança para o próximo ponto
            atual++;         // Conta mais um passo nessa direção

            if(ponto_atual == n) { // Se chegou no ponto n, encerra
                f = 0;
                break;
            }
        }

        passagem++; // Contabiliza que mudamos de direção

        // A cada duas direções, aumenta o número de passos (step_size)
        if(passagem % 2 == 0) {
            step_size++;
        }

        atual = 1; // Reinicia o contador de passos para a nova direção
        i++;       // Avança para a próxima direção (mod 4)

    }

    printf("(%d, %d)", x, y); // Imprime as coordenadas finais do ponto n

    return 0;
}
