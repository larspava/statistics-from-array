/*
* Instruções:
* - Inserir os valores inteiros dentro do array na main().
* - Inserir a quantidade total de valores adicionados no array na variável "n".
* - Rodar o código.
*/

#include <stdio.h>
#include <stdlib.h>

// Struct para armazenar valores a serem calculados
typedef struct {
    float mean;
    int max;
    int min;
    int* evenArray;
    int evenArraySize;
} Data;


/**
 * Calcula e retorna a média, valor máximo, valor mínimo, uma cópia do array de entrada contendo apenas os números pares do array original e seu tamanho.
 * @param array posição em memória do array.
 * @param size valor inteiro que representa o tamanho do array.
 * @return retorna o resultado os cálculos dentro do struct criado chamado "Data".
 */
Data calculation_function(int* array, int size) {
    Data res;
    
    if (size <= 0 || array == NULL) {
        res.mean = 0;
        res.max = 0;
        res.min = 0;
        res.evenArray = NULL;
        res.evenArraySize = 0;
        return res;
    }

    float soma = 0;
    res.max = array[0];
    res.min = array[0];
    
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            evenCount++;
        }
        soma += array[i];
        if (array[i] > res.max) res.max = array[i];
        if (array[i] < res.min) res.min = array[i];
    }
    
    res.mean = soma / size;
    
    res.evenArray = (int*)malloc(evenCount * sizeof(int));
    res.evenArraySize = evenCount;

    int j = 0; //índice do evenArray
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            res.evenArray[j] = array[i];
            j++;
        }
    }
    
    return res;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Array de valores que será calculado
    int n = 10; //Quantidade de valores no array
    
    Data result = calculation_function(array, n);
    
    printf("Media: %.2f\n", result.mean);
    printf("Maximo: %d\n", result.max);
    printf("Minimo: %d\n", result.min);
    printf("Array de pares (tamanho %d): ", result.evenArraySize);
    for (int i = 0; i < result.evenArraySize; i++) {
        printf("%d ", result.evenArray[i]);
    }
    printf("\n");    
    return 0;
}
