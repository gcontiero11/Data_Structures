#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int* itens;
    int index;
    int start;
    int number_of_elem;
}t_line;

int create_line(t_line** line){
    (*line) = malloc(sizeof(t_line));
    (*line)->itens = malloc(sizeof(int) * 10);
    (*line)->size = 1;
    (*line)->index = 0;
    (*line)->start = 0;
    (*line)->number_of_elem = 0;
    return 1;
}

int is_empty(t_line* line){
    if (line->number_of_elem == 0){
        return 1;
    }
    return 0;
}

int in(t_line* line,int elem){
    line->itens[line->index] = elem;
    if (line->index == line->start){
        line->start = (line->start+1)%10;
    }
    line->index = (line->index+1)%10;
    if (line->number_of_elem < 10){
        line->number_of_elem++;
    }
    return 1;
}

int out(t_line* line,int* removed_elem){
    *removed_elem = line->start;
    line->start = (line->start+1)%10;
    line->number_of_elem--;
    return 1;
}

void print_line_entry_order(t_line* line){
    int aux_index = line->start;
    while (aux_index != line->index-1){
        printf("%d \n",line->itens[aux_index]);
        aux_index = (aux_index+1)%10;
    }
    printf("%d \n",line->itens[aux_index]);	
    printf("\n");
}

int main(int argc, char const *argv[]){
    t_line* line;
    int elem;
    create_line(&line);
    in(line,10);
    in(line,20);
    in(line,30);
    in(line,40);
    in(line,50);
    in(line,60);
    in(line,70);
    in(line,80);
    in(line,90);
    in(line,100);
    in(line,110);
    in(line,120);
    in(line,130);
    print_line_entry_order(line);
    return 0;
}
