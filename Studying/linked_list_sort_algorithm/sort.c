#include <stdio.h>
#include <stdlib.h>

// ED escolhida: Lista Encadeada
typedef struct _node {
    int item;
    struct _node* next;
} t_node;

typedef struct {
    t_node* head;
    int size;
} t_list;

t_list* create_list(){
    t_list* new_list = malloc(sizeof(t_list));
    new_list->head = NULL;
    new_list->size = 0;
}

int append(t_list* list, int item){
    t_node* new_node = malloc(sizeof(t_node));
    new_node->item = item;
    new_node->next = NULL;
    if (list->size == 0){
        list->head = new_node;
        list->size++;
        return 1;
    }
    t_node* current_node = list->head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    list->size++;
    return 1;
}

void print_list(t_list* list){
    t_node* current_node = list->head;
    int count = 0;
    while (current_node->next != NULL){
        printf("%d|",current_node->item);
        current_node = current_node->next;
        count ++;
    }    
    printf("%d\n",current_node->item);
}

// Complexidade: O(n^2)
int sort(t_list *list) {
    t_node* current_node = list->head;
    t_node* minor_node = current_node;
    t_node* previous_current_node;
    t_node* previous_minor_node;
    for (int i = 0; i < list->size; i++){
        if (current_node->item <= minor_node->item){
            previous_minor_node = previous_current_node;
            minor_node = current_node;
        }
        previous_current_node = current_node;
        current_node = current_node->next;
    }
    previous_minor_node->next = minor_node->next;
    minor_node->next = list->head;
    list->head = minor_node;
    t_node* starter_node = list->head;
    while (starter_node->next != NULL){
        current_node = starter_node->next;
        minor_node = current_node;
        previous_current_node = starter_node->next;
        while (current_node != NULL){
            if (current_node->item <= minor_node->item){
                previous_minor_node = previous_current_node;
                minor_node = current_node;
            }
            previous_current_node = current_node;
            current_node = current_node->next;
        }
        if (minor_node != starter_node->next){
            previous_minor_node->next = minor_node->next;
            minor_node->next = starter_node->next;
            starter_node->next = minor_node;
        }
        starter_node = starter_node->next; 
    }
}

int main(int argc, char const *argv[]){
    t_list* list = create_list();
    append(list,200000);
    append(list,5);
    append(list,10);
    append(list,2025);
    append(list,-42141);
    append(list,2);
    append(list,-10);
    print_list(list);
    sort(list);
    print_list(list);
    return 0;
}
