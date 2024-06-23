#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definisikan stack
typedef struct {
    int top;
    int capacity;
    char* array;
} Stack;

// Fungsi untuk membuat stack dengan kapasitas tertentu
Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk menambahkan elemen ke stack
void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Fungsi untuk menghapus elemen dari stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Fungsi untuk membalikkan string menggunakan stack
void reverseString(char str[]) {
    int n = strlen(str);
    Stack* stack = createStack(n);

    // Dorong semua karakter string ke stack
    for (int i = 0; i < n; i++)
        push(stack, str[i]);

    // Pop semua karakter dari stack dan masukkan kembali ke string
    for (int i = 0; i < n; i++)
        str[i] = pop(stack);
}

// Fungsi utama
int main() {
    char str[] = "Binus University";
    printf("String asli: %s\n", str);

    reverseString(str);
    printf("String setelah dibalik: %s\n", str);

    return 0;
}
