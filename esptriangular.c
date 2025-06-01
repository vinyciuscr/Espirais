#include <stdlib.h>
#include <stdio.h>

int main() {

    int direcao = 0;           // Direção atual (0: direita, 1: noroeste, 2: sudoeste)
    int x = 0, y = 0;          // Coordenadas atuais, iniciando na origem

    int step_size = 1;         // Controla o número de passos em uma mesma direção
    int atual = 1;             // Número total de passos a serem dados na direção atual
    int i = 0;                 // Auxiliar para alternar entre as direções
    int ponto_atual = 0;       // Conta quantos pontos já percorremos
    int n;                     // Índice do ponto desejado (entrada)
    int f = 1;                 // Flag de controle para encerrar o loop principal

    int direita = 1;           // Inicialização da direção "direita" (nº de passos)
    int noroeste = 1;          // Inicialização da direção "noroeste"
    int sudoeste = 2;          // Inicialização da direção "sudoeste"
    int flag = 0;              // Controla o incremento contínuo da direção "direita" após certo ponto

    scanf("%d", &n);           // Leitura da entrada

    while(f) {

        if(n == 0) {           // Caso especial: ponto de índice 0 (origem)
            f = 0;
            break;
        }

        direcao = i % 3;       // Alternância entre as 3 direções: direita, noroeste, sudoeste

        // Determina quantos passos (atual) serão dados na direção escolhida
        if(direcao == 0) { // Direção: direita
            if(ponto_atual == 0) {
                atual = direita; // Começa com 1 passo
            }
            else if(ponto_atual == 4) {
                atual = direita + 4; // No ponto 4, direita anda 5 vezes
            }
            else if(ponto_atual == 16) {
                atual = direita + 7; // No ponto 16, anda 8 vezes
            }
            else if(ponto_atual > 16) {
                atual = 8 + flag; // A partir daqui, o passo aumenta de 2 em 2
                flag += 2;
            }
        }
        else if(direcao == 1) { // Direção: noroeste
            atual = noroeste;
            noroeste += 2;
        }
        else if(direcao == 2) { // Direção: sudoeste
            atual = sudoeste;
            sudoeste += 2;
        }

        // Move o ponto nas coordenadas conforme o número de steps definidos
        while(step_size <= atual) {
            if(direcao == 0) {
                x += 1;             // Direita: apenas x avança
            }
            if(direcao == 1) {
                x -= 1;             // Noroeste: x diminui, y aumenta
                y += 1;
            }
            if(direcao == 2) {
                x -= 1;             // Sudoeste: x e y diminuem
                y -= 1;
            }

            ponto_atual++;         // Conta mais um ponto visitado
            step_size++;           // Avança dentro dos passos da direção atual

            if(ponto_atual == n) { // Se chegou ao ponto desejado, encerra
                f = 0;
                break;
            }
        }

        step_size = 1;   // Reinicializa para a próxima direção
        atual = 0;       // Zera a contagem da direção atual
        i++;             // Avança para a próxima direção

    }

    printf("(%d, %d)", x, y); // Imprime as coordenadas finais do ponto n
    return 0;
}
