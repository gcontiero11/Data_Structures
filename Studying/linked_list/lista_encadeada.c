#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int item;
    struct _node* next;
}t_node;

typedef struct{
    t_node* head;
    t_node* tail;
    int size;
}t_list;


int create_node(t_node** new_node,int elem){
    (*new_node) = malloc(sizeof(t_node));
    (*new_node)->item = elem;
    (*new_node)->next = NULL;
    return 1;
}

int create_list(t_list** list){
    (*list) = malloc(sizeof(t_list));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
}


int destroy_list(t_list* list){
    t_node* current_node = list->head;
    t_node* next_node;
    while (current_node != list->tail){
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(current_node);
    free(list);
    return 1;
}

int is_empty(t_list* list){
    if (list->size == 0 || list->head == NULL){
        return 1;
    }
    return 0;
}

int size(t_list* list){
    return list->size;
}

int append(t_list* list,int elem){
    t_node* new_node;
    create_node(&new_node,elem);
    if (is_empty(list)){
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
}

int insert(t_list* list,int index,int elem){
    t_node* new_node;
    create_node(&new_node,elem);
    t_node* current_node = list->head;
    if (index >= size(list) || index < 0){
        return 0;
    }
    int i = 0;
    while (i<size(list)){
        if (i==index){
            new_node->next = current_node->next;
            current_node ->next = new_node;
            list->size++;
            return 1;
        }
        i++;
    }
    return 0;
}

int remove_item(t_list* list,int item){
    t_node* current_node = list->head;
    if (item == list->head->item){
        t_node* free_node = list->head;
        list->head = list->head->next;
        free(free_node);
        return 1;
    }
    for (int i = 0; i < size(list) - 1; i++){
        if (item == current_node->next->item){
            t_node* free_node = current_node->next;
            current_node->next = current_node->next->next;
            free(free_node);
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

t_node* get_node_item(t_list* list,int item){
    t_node* current_node = list->head;
    for (int i = 0; i < size(list); i++){
        if (item == current_node->item){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

t_node* get_item_by_index(t_list* list,int index){
    if (index>= size(list) || index<0){
        return NULL;
    }
    t_node* current_node = list->head;
    for (int i = 0; i < size(list); i++){
        if (index == i){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

int clear(t_list* list){
    t_node* current_node = list->head;
    for (int i = 0; i < size(list) - 1; i++){    
        list->head = current_node->next;
        free(current_node);
        current_node = list->head->next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return 1;
}

void print_list(t_list* list){
    t_node* current_node = list->head;
    while (current_node != list->tail){
        printf("%d|",current_node->item);
        current_node = current_node->next;
    }
    printf("%d\n",current_node->item);
}


int main(int argc, char const *argv[]){
    t_list* list;
    create_list(&list);
    append(list,10);
    append(list,20);
    append(list,30);
    print_list(list);
    insert(list,1,15);
    print_list(list);
    remove_item(list,20);
    print_list(list);
    get_item_by_index(list,-1);
    printf("%d\n",get_node_item(list,10)->item);
    clear(list);
    print_list(list);
    destroy_list(list);
    print_list(list);
    return 0;
}
