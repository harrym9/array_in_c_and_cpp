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


int Delete(struct Array *array, int index){
    if (index >= 0 && array->length < array->size && index <= array->length) {
        int x = array->A[index];
        for (int i = index; i < array->length - 1; i++) {
            array->A[i] = array->A[i+1];
        }
        array->length--;
        return x;
    }
    return 0;
}


int LinearSearch(struct Array *array, int key){
    for (int i = 0; i < array->length; i++){
        if (key == array->A[i]){
            printf("%d Found at index %i\n",key, i);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *array, int key){
    int low = 0;
    int high = array->length-1;
    int mid = (low + high) / 2;
    while (low <= high){
        if (array->A[mid] == key){
            return mid;
        }
        else if (key < array->A[mid]){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    struct Array my_array = {{1, 2, 3, 4, 5}, 10, 5};
    
    printf("index number is %d\n", BinarySearch(&my_array, 3));
    Display(my_array);
    printf("\n");
    
    return 0;
}
