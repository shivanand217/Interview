#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_at_back(struct node **head, int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
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
        (*head)->data = data;
        (*head)->next = NULL;
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
void identical_lists( struct node **head1, struct node **head2, int *flag ) {
    struct node *tmp1 = *head1;
    struct node *tmp2 = *head2;
    while(tmp1 != NULL && tmp2 != NULL) {
        if( tmp1->data != tmp2->data ) {
            flag = 0;
            return;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if(tmp1 == NULL && tmp2 == NULL) {
        *flag=1;
        return;
    }
    return;
}
int main() {

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    insert_at_back(&head1, 23);
    insert_at_back(&head1, 28);
    insert_at_back(&head1, 29);
    insert_at_back(&head1, 35);
    insert_at_back(&head1, 89);

    insert_at_back(&head2, 23);
    insert_at_back(&head2, 28);
    insert_at_back(&head2, 29);
    insert_at_back(&head2, 35);
    insert_at_back(&head2, 800);

    display(&head1);
    display(&head2);

    int flag = 0;
    identical_lists(&head1, &head2, &flag);

    if(flag == 0) {
        printf("Lists are not identical\n");
    } else {
        printf("Lists are Identical\n");
    }

    return 0;
}
