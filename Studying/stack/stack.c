#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int itens[10];
    int numberOfItens;
}t_stack;

int create_stack(t_stack** stack){
    (*stack) = malloc(sizeof(t_stack));
    (*stack)->numberOfItens = 0;
    (*stack)->size = 10;
    return 1;
}

int size(t_stack* stack){
    return stack->size;
}

int is_full(t_stack* stack){
    if (stack->numberOfItens == size(stack)){
        return 1;
    }
    return 0;
}

int is_empty(t_stack* stack){
    if (stack->numberOfItens == 0){
        return 1;
    }
    return 0;
}

int push(t_stack* stack,int elem){
    if (is_full(stack)){
        return 0;
    }

    stack->itens[stack->numberOfItens] = elem;
    stack->numberOfItens++;
    return 1;
}

int pop(t_stack* stack,int* elem){
    if (is_empty(stack)){
        return 0;
    }
    *elem = stack->itens[stack->numberOfItens-1];
    stack->numberOfItens--;
    return 1;
}

int getTop(t_stack* stack,int* elem){
    if (is_empty(stack)){
        return 0;
    }
    *elem = stack->itens[stack->numberOfItens-1];
    return 1;
}

int clear(t_stack* stack){
    stack->numberOfItens = 0;
    return 1;
}

int main(int argc, char const *argv[]){
    t_stack* stack;
    int elem = 2;
    create_stack(&stack);
    push(stack,5);
    push(stack,10);
    printf("%d\n",elem);
    getTop(stack,&elem);
    printf("%d\n",elem);
    pop(stack,&elem);
    printf("%d\n",elem);
    getTop(stack,&elem);
    printf("%d\n",elem);
    return 0;
}
