#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert(struct node **head, int data) {
    if(*head == NULL) {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    struct node *tmp = *head;
    while( tmp->next != NULL ) {
        tmp=tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp->data=data;
    tmp->next=NULL;
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
void convert_to_circular(struct node **head) {
    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    struct node *tmp = *head;
    if( *head == NULL )
        return;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next = *head;
    return;
}
void display_circular(struct node **head) {
    if(*head == NULL)
        return;
    struct node *tmp = *head;
    int cnt = 0;
    while(tmp->next != NULL) {
        if( tmp->data == (*head)->data ) {
            printf("%d ", tmp->data);
            cnt++;
        } else {
            printf("%d ", tmp->data);
        }
        if(cnt==2)
            break;
        tmp=tmp->next;
    }
}
int main() {
    struct node *head = NULL;
    insert(&head,11);
    insert(&head,12);
    insert(&head,13);
    insert(&head,14);
    insert(&head,15);

    display_normal(&head);
    convert_to_circular(&head);
    display_circular(&head);

    return 0;
}
