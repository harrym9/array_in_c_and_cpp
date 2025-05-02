#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[20];
    int size;
    int length;
};


void Display(struct Array array){
    for(int i = 0; i < array.length; i++){
        printf("%d ", array.A[i]);
    }
}


void Append(struct Array *array, int x){
    if (array->length < array->size) {
        array->A[array->length++] = x;
    }
}


void Insert(struct Array *array, int index, int x){
    if (index >= 0 && array->length < array->size && index <= array->length) {
        for (int i = array->length; i > index; i--) {
            array->A[i] = array->A[i-1];
        }
        array->A[index] = x;
        array->length++;
    }
}


int main(int argc, const char * argv[]) {
    struct Array my_array = {{2, 4, 1, 5, 2}, 10, 5};
    
    Append(&my_array, 8);
    Insert(&my_array, 2, 5);
    Display(my_array);
    printf("\n");
    
    return 0;
}
