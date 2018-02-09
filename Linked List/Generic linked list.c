#include<stdio.h>
#include<stdlib.h>

struct node {
    void *data;
    struct node *next;
};

void insert_at_front(struct node **head, void *new_data, size_t size) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = malloc(size);
    new_node->next = *head;
    int i;
    for( i = 0; i < size; i++ ) {
        /** copying value byte per byte **/
        /** assuming char takes 1 byte **/
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    (*head) = new_node;
}

void insert_at_back(struct node **head, void *new_data, size_t size) {
    if(*head == NULL) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = malloc(size);
        //new_node->next = NULL;
        int i;
        for(i=0; i < size; i++) {
            *(char *)(new_node->data + i) = *(char *)(new_node + i);
        }
        new_node->next = NULL;
        (*head) = new_node;
        return;
    }
    /**struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp = tmp->next;
    int i;
    for( i=0; i < size; i++ ) {
        *(char *)(tmp->data + i) = *(char *)( new_data + i );
    }
    tmp->next = NULL;**/
}

void printInt(void *n) {
    printf("%d ", *(int *)n );
}

void printDouble(void *f) {
    printf("%.1f ", *(double *)f );
}

void printFloat(void *f) {
    printf("%f ", *(float *)f);
}

void printChar(void *p) {
    printf("%c ", *(char *)p);
}

void printList( struct node **head , void(*function_ptr)(void *)) {
    struct node *tmp = (*head);
    while(tmp != NULL) {
        (*function_ptr)(tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    struct node *start = NULL;
    unsigned int int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40};
    int i;

    /** insert into generic linked list **/
    for( i = 0; i < 4; i++) {
        insert_at_front(&start, &arr[i], int_size);
    }
    printList(&start, printInt);
    putchar('\n');

    float arr1[] = {1.0, 2.0, 3.0, 4.0};
    start = NULL;
    unsigned float_size = sizeof(float);

    for( i = 0; i < 4; i++ ) {
        insert_at_front(&start, &arr1[i], float_size);
    }
    printList(&start, printFloat);
    putchar('\n');

    double arr3[] = {1.0, 2.0, 3.0, 4.0};
    start = NULL;
    unsigned double_size = sizeof(double);

    for( i = 0; i < 4; i++ ) {
        insert_at_front(&start, &arr3[i], double_size);
    }
    printList(&start, printDouble);
    putchar('\n');

    char arr2[] = {'a', 'b', 'c', 'd'};
    start=NULL;
    unsigned int char_size = sizeof(char);

    for( i = 0; i < 4; i++ ) {
        insert_at_front(&start, &arr2[i], char_size);
    }
    printList(&start, printChar);
    putchar('\n');

    return 0;
}
