#include <stdio.h>

int buscaBinaria(int vetor[], int inicio, int final, int x); // Corrigido a declaração da função

int main() {
    int i, n; // Declare 'n' para armazenar o tamanho do vetor
    printf("Quantos elementos você deseja adicionar ao vetor?:\n");
    scanf("%d", &n); // 
    
    int vetor[n]; // Criação do vetor com tamanho 'n'
    
    // Lê os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]); 
    }
    
    // Ordenação do vetor (bubble sort)
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { 
            if (vetor[j] > vetor[j + 1]) {
                int auxiliar = vetor[j]; // Declare a variável aqui
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }
   
    printf("Qual elemento você deseja encontrar?\n");
    int x; // Declare 'x' para armazenar o valor que será buscado
    scanf("%d", &x); // 

    int resultado = buscaBinaria(vetor, 0, n - 1, x); 

    if (resultado != -1) {
        printf("Elemento encontrado no indice %d\n", resultado);
    } else {
        printf("Elemento não encontrado no vetor\n"); 
    }

    return 0; // Retorno da função main
}

// Função de busca binária
int buscaBinaria(int vetor[], int inicio, int final, int x) {
    while (inicio <= final) {
        int meio = (inicio + final) / 2; // Cálculo do meio
        if (vetor[meio] == x) {
            return meio; // Retorna o índice se o elemento for encontrado
        } else if (vetor[meio] < x) {
            inicio = meio + 1; // Ajusta o início
        } else {
            final = meio - 1; // Ajusta o final
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}
