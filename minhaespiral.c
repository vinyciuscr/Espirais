#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    int x = 0, y = 0; // Coordenadas iniciais na origem (0, 0)

    // Vetores de variação de x e y para cada uma das 8 direções da espiral em formato de coração
    int variacao_x[8] = {-1, 0, 1, 1, 1, 1, 0, -1};
    int variacao_y[8] = { 1, 1, 0, -1, 1, 0, -1, -1};

    // Vetor com o número de passos (steps) para cada direção
    int steps[8] = {2, 1, 1, 1, 1, 1, 2, 2};

    int f = 1;               // Flag de controle principal
    int ponto_atual = 0;     // Contador de quantos pontos já percorremos
    int n = 0;               // Índice do ponto desejado (entrada)

    scanf("%d", &n);         // Leitura da entrada

    while(f) {

        if(n == 0) {         // Caso especial: ponto de índice 0 (a própria origem)
            f = 0;
            break;
        }

        // Percorre todas as 8 direções da espiral
        for(int i = 0; i < 8; i++) {

            // Executa os steps necessários na direção i
            for (int j = 0; j < steps[i]; j++) {
                x += variacao_x[i];  // Atualiza x com base na direção
                y += variacao_y[i];  // Atualiza y com base na direção
                ponto_atual++;       // Avança para o próximo ponto

                if(ponto_atual == n) {
                    f = 0;           // Chegou no ponto desejado
                    break;
                }
            }

            if(f == 0) break; // Sai do loop externo se o ponto foi atingido

            // Ao fim de uma volta completa (após a última direção), aumenta os steps
            if(i == 7) {
                for(int k = 0; k < 8; k++) {
                    // As direções 3 e 4 não aumentam seus steps, pois seguem padrão fixo
                    if(k != 3 && k != 4) {
                        steps[k]++;
                    }
                }
            }
        }

        if(f == 0) break; // Sai do loop principal se ponto n foi encontrado
    }

    printf("(%d, %d)", x, y); // Imprime as coordenadas finais do ponto n
    return 0;
}
