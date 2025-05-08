#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};


void Display(struct Array array)
{
    for (int i = 0; i < array.length; i++)
    {
        printf("%d ", array.A[i]);
    }
}


void Append(struct Array* array, int x)
{
    if (array->length < array->size)
    {
        array->A[array->length++] = x;
    }
}


void Insert(struct Array* array, int index, int x)
{
    if (index >= 0 && array->length < array->size && index <= array->length)
    {
        for (int i = array->length; i > index; i--)
        {
            array->A[i] = array->A[i - 1];
        }
        array->A[index] = x;
        array->length++;
    }
}


void InsertSort(struct Array* array, int x)
{
    if (array->length == array->size)
    {
        return;
    }

    int i = array->length - 1;

    while (i >= 0 && array->A[i] > x)
    {
        array->A[i + 1] = array->A[i];
        i--;
    }
    array->A[i + 1] = x;
    array->length++;
}


int Delete(struct Array* array, int index)
{
    if (index >= 0 && array->length < array->size && index <= array->length)
    {
        int x = array->A[index];
        for (int i = index; i < array->length - 1; i++)
        {
            array->A[i] = array->A[i + 1];
        }
        array->length--;
        return x;
    }
    return 0;
}


int LinearSearch(struct Array array, int key)
{
    for (int i = 0; i < array.length; i++)
    {
        if (key == array.A[i])
        {
            printf("%d Found at index %i\n", key, i);
            return i;
        }
    }
    return -1;
}


int BinarySearch(struct Array array, int key)
{
    int low = 0;
    int high = array.length - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array.A[mid] == key)
        {
            return mid;
        }
        else if (key < array.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}


int RBinarySearch(struct Array array, int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (array.A[mid] == key)
    {
        return mid;
    }
    else if (key > array.A[mid])
    {
        return RBinarySearch(array, mid + 1, high, key);
    }
    else
    {
        return RBinarySearch(array, low, mid - 1, key);
    }
    return -1;
}


int Get(struct Array array, int index)
{
    if (index < 0 && index >= array.length)
        return -1;
    return array.A[index];
}


void Set(struct Array* array, int index, int new_key)
{
    if (index < 0 || index >= array->length)
    {
        printf("Index exceeded current length or too low");
        return;
    }
    array->A[index] = new_key;
    printf("Success");
}


int Max(struct Array array)
{
    int max = array.A[0];
    for (int i = 1; i < array.length; i++)
    {
        if (array.A[i] > max)
        {
            max = array.A[i];
        }
    }
    return max;
}


int Min(struct Array array)
{
    int min = array.A[0];
    for (int i = 1; i < array.length; i++)
    {
        if (array.A[i] < min)
        {
            min = array.A[i];
        }
    }
    return min;
}


int Sum(struct Array array)
{
    int sum = 0;
    for (int i = 0; i < array.length; i++)
        sum += array.A[i];
    return sum;
}


float Average(struct Array array)
{
    return (float)Sum(array) / array.length;
}


void ReverseWithCopy(struct Array* array)
{
    int length = array->length;
    int* temp_array = (int*)malloc(length * sizeof(int));

    for (int i = 0, j = length - 1; i < length; i++, j--)
    {
        temp_array[i] = array->A[j];
    }

    for (int i = 0; i < length; i++)
    {
        array->A[i] = temp_array[i];
    }
}


void ReverseWithSwap(struct Array* array)
{
    for (int i = 0, j = array->length - 1; i <= j; i++, j--)
    {
        const int temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
    }
}


bool IsSorted(struct Array array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array.A[i] > array.A[i + 1])
        {
            return false;
        }
    }
    return true;
}


int main(int argc, const char* argv[])
{
    struct Array my_array = {{1, 2, 3, 4, 5, 6, 8, 10}, 10, 8};

    InsertSort(&my_array, 9);
    Display(my_array);

    return 0;
}
