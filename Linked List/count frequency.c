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
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}
void display(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *tmp = *head;
    while(tmp != NULL) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
int solve(struct node **head,int data) {
    if(*head == NULL)
        return 0;
    struct node *tmp = *head;
    int cnt=0;
    while( tmp != NULL ) {
        if(tmp->data == data) {
            cnt++;
        }
        tmp=tmp->next;
    }
    return cnt;
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

    insert_front(&head,20);

    display(&head);
    int cnt = solve(&head,20);
    printf("%d\n",cnt);

    return 0;
}
