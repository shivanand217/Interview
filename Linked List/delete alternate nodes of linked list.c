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
void delete_alternate(struct node **head) {
    if(*head == NULL)
        return;
    if((*head)->next == NULL) {
        printf("One Node only\n");
        return;
    }
    struct node *prev = *head;
    struct node *tmp = (*head)->next;
    while(tmp != NULL) {
        prev->next = tmp->next;
        free(tmp);
        prev=prev->next;
        if(prev == NULL){
            return;
        }
        tmp=prev->next;
    }
}
void recursive_delete(struct node *head) {
    if(head == NULL || head->next == NULL)
        return;
    if(head->next->next == NULL) {
        struct node *tmp = head->next;
        head->next = NULL;
        free(tmp);
        return;
    } else {
        struct node *tmp = head->next;
        head->next = head->next->next;
        free(tmp);
        recursive_delete(head->next);
    }
}
int main() {
    struct node *head = NULL;

    insert_at_back(&head, 5);
    insert_at_back(&head, 4);
    insert_at_back(&head, 3);
    insert_at_back(&head, 2);
    insert_at_back(&head, 1);
    insert_at_back(&head, 49);
    insert_at_back(&head, 53);
    insert_at_back(&head, 17);
    insert_at_back(&head, 18);
    insert_at_back(&head, 19);
    insert_at_back(&head, 20);
    insert_at_back(&head, 22);
    insert_at_back(&head, 24);
    insert_at_back(&head, 27);
    insert_at_back(&head, 29);
    insert_at_back(&head, 30);
    insert_at_back(&head, 31);

    display(&head);

    delete_alternate(&head);
    display(&head);

    recursive_delete(head);
    display(&head);

    return 0;
}
