#include <stdlib.h>
#include <stdio.h>

int main() {
    int *arr_ptr = malloc(5 * sizeof(int));
    if (!arr_ptr) return 1;  

    int length = 5;

    for (int i = 0; i < length; i++) {
        arr_ptr[i] = i;
        printf("%d\n", arr_ptr[i]);  
    }

    free(arr_ptr);
    return 0;
}