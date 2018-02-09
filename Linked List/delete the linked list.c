#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head,int data) {
    if(*head == NULL) {
        (*head)=(struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next=(struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp->data=data;
    tmp->next=NULL;
}
void insert_front(struct node **head,int data) {
    if(*head == NULL) {
        (*head)=(struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}
void delete_list(struct node **head) {
    if(*head == NULL)
        return;
    struct node *tmp = *head;
    struct node *current = *head;
    while(tmp != NULL) {
        tmp=tmp->next;
        free(current);
        current=tmp;
    }
    *head = NULL;
    printf("list deleted\n");
}
void display(struct node **head) {
    if(*head == NULL)
        return;
    struct node *tmp = *head;
    while( tmp != NULL ) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
int main() {
    struct node *head = NULL;

    insert_front(&head,12);
    insert_front(&head,13);
    insert_front(&head,14);
    insert_front(&head,15);

    insert_back(&head,16);
    insert_back(&head,17);

    display(&head);

    delete_list(&head);
    display(&head);

    return 0;
}
