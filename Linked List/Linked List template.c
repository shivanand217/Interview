#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_at_back(struct node **head, int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next=(struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp->data=data;
    tmp->next=NULL;
}
void insert_at_front(struct node **head,int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}
void delete_last(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *last = *head;
    struct node *prev_last;
    while( last->next != NULL ) {
        prev_last = last;
        last = last->next;
    }
    prev_last->next=NULL;
    free(last);
}
void delete_front(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *tmp = *head;
    if(tmp->next == NULL) {
        *head=NULL;
        free(tmp);
        return;
    }
    (*head) = tmp->next;
    free(tmp);
}
void display(struct node **head) {
    if(*head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("%d\n",tmp->data);
}
int main() {

    struct node *head = NULL;

    insert_at_back(&head, 23);
    insert_at_back(&head, 28);
    insert_at_back(&head, 28);
    insert_at_back(&head, 35);
    insert_at_back(&head, 49);
    insert_at_back(&head, 49);
    insert_at_back(&head, 53);
    insert_at_back(&head, 53);
    insert_at_back(&head, 17);
    insert_at_back(&head, 18);
    insert_at_back(&head, 18);
    insert_at_back(&head, 44);

    display(&head);
    delete_front(&head);
    display(&head);

    delete_last(&head);
    display(&head);

    insert_at_front(&head, 222);
    display(&head);

    return 0;
}
