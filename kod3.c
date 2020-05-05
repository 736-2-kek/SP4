#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter matrix size:\n");
    scanf("%d", &size);
    uint8_t* matrix1 = (uint8_t*)malloc(sizeof(uint8_t)*size*size);
    uint8_t* matrix2 = (uint8_t*)malloc(sizeof(uint8_t)*size*size);
    srand(time(NULL));
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            matrix1[i * size + j] = rand()%10;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrix1[i * size + j]);
        }
        printf("\n");
    }
    printf("\n");
    asm(
        "mov %%rdi, %%rcx\n\t"
        "mov %%rdi, %%rax\n\t"
        "sub:\n\t"
        "push %%rbx\n\t"
        "mov (%%rbx), %%rbx\n\t"
        "mov %%rbx, (%%rdx)\n\t"
        "pop %%rbx\n\t"
        "inc %%rdx\n\t"
        "add %%rdi, %%rbx\n\t"
        "loop sub\n\t"
        "mov %%rdi, %%rcx\n\t"
        "restore:\n\t"
        "sub %%rdi, %%rbx\n\t"
        "dec %%rdx\n\t"
        "loop restore\n\t"
        "inc %%rbx\n\t"
        "add %%rdi, %%rdx\n\t"
        "mov %%rdi, %%rcx\n\t"
        "dec %%rax\n\t"
        "cmp $0, %%rax\n\t"
        "jne sub\n\t"
        :
        :"b"(matrix1), "d"(matrix2), "D"(size)
        :
    );
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrix2[i * size + j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}