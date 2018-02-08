#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head,int data) {
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
void insert_front(struct node **head,int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    (*head)=(*head)->next;
    free(tmp);
}
void display(struct node **head) {
    struct node *tmp = *head;
    while(tmp != NULL) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
void nth_node(struct node **head, int n) {
    if(*head == NULL) {
        return;
    }
    n--;
    struct node *one = *head;
    struct node *two = *head;
    while(n > 0) {
        two = two->next;
        n -= 1;
    }
    while(two->next!=NULL) {
        one=one->next;
        two=two->next;
    }
    printf("%d\n",one->data);
}
int main() {

    struct node *head = NULL;
    insert_back(&head,18);
    insert_back(&head,12);
    insert_back(&head,17);
    insert_back(&head,20);
    insert_back(&head,25);
    insert_back(&head,28);
    insert_back(&head,30);

    display(&head);
    nth_node(&head,7);

    return 0;
}
