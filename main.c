#include <stdio.h>

// Errore: dichiarazione della funzione senza specificare i nomi dei parametri
int binarySearch(int[], int, int, int);

int main() {
    int arr[] = {5, 15, 24, 32, 56, 89};
    // Errore: calcolo errato della dimensione dell'array (sizeof(int) invece di sizeof(arr[0]))
    int size_of_array = sizeof(arr) / sizeof(int);

    printf("%d\n", binarySearch(arr, 24, 0, size_of_array - 1));
    printf("%d\n", binarySearch(arr, 118, 0, size_of_array - 1));
    return 0;
}

int binarySearch(int array[], int number, int start, int end) {
    // Errore: uso di >= invece di > rompe la condizione corretta del base case
    if (start >= end) {
        // Errore di ortografia nel commento e confronto poco chiaro
        return array[start] == number ? 0 : 1;
    }

    // Errore: calcolo errato dell'indice centrale (deve usare start + (end - start) / 2)
    int tmp = (int) end / 2;

    if (number == array[tmp]) {
        return 0;
    } else if (number > array[tmp]) {
        // Errore: ricerca ricorsiva nella metà sbagliata (deve essere tmp + 1, non tmp)
        return binarySearch(array, number, tmp, end);
    } else {
        return binarySearch(array, number, start, tmp);
    }
}