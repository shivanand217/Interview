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
    if( (*head)->next == NULL ) {
        struct node *tmp = *head;
        free(tmp);
        *head = NULL;
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
int max(int x,int y) {
    if( x < y )
        return y;
    else
        return x;
}
void reverse_list(struct node **head) {
    if(*head == NULL || (*head)->next == NULL ) {
        return;
    }
    struct node *prev = NULL;
    struct node *next;
    struct node *current = (*head);
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}
void solve(struct node **head) {
    if( *head == NULL || (*head)->next == NULL )
        return;

    display(head);
    reverse_list(head);
    display(head);

    int max_now = (*head)->data;
    struct node *tmp = *head;
    struct node *prev = NULL;
    struct node *curr;

    while(tmp != NULL) {
        if(tmp->data < max_now) {
            prev->next = tmp->next;
            curr = tmp;
            tmp=tmp->next;
            free(curr);
        } else {
            prev = tmp;
            max_now = max(max_now,tmp->data);
            tmp=tmp->next;
        }
    }

    reverse_list(head);
    display(head);
    return;
}
int main() {
    struct node *head = NULL;

    insert_at_back(&head, 10);
    insert_at_back(&head, 20);
    insert_at_back(&head, 30);
    insert_at_back(&head, 40);
    insert_at_back(&head, 50);
    insert_at_back(&head, 60);

    solve(&head);
    int i;

    head = NULL;
    insert_at_back(&head, 12);
    insert_at_back(&head, 15);
    insert_at_back(&head, 10);
    insert_at_back(&head, 11);
    insert_at_back(&head, 5);
    insert_at_back(&head, 6);
    insert_at_back(&head, 2);
    insert_at_back(&head, 3);

    solve(&head);

    return 0;
}
