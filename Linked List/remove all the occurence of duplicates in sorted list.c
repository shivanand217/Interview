#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_at_back(struct node **head,int data) {
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
    if(*head == NULL){
        printf("empty list\n");
        return;
    }
    struct node *tmp = *head;
    while( tmp != NULL ) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
void remove_all(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *tmp = *head;
    int val;
    struct node *prev = NULL;
    struct node *rem = NULL;
    while(tmp->next != NULL) {
        if(tmp->data == tmp->next->data) {
            val = tmp->data;
            while(tmp->data == val) {
                if((*head)->data == val) {
                    rem = (*head);
                    (*head) = (*head)->next;
                    tmp = tmp->next;
                    free(rem);
                } else {
                    rem=tmp;
                    tmp=tmp->next;
                    free(rem);
                }
                if(*head == NULL) {
                    return;
                }
            }
            if(prev != NULL) {
                prev->next = tmp;
            }
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}
int main() {
    struct node *head = NULL;

    insert_at_back(&head, 11);
    insert_at_back(&head, 12);
    insert_at_back(&head, 12);
    insert_at_back(&head, 12);
    insert_at_back(&head, 14);
    insert_at_back(&head, 14);
    insert_at_back(&head, 14);
    insert_at_back(&head, 16);
    insert_at_back(&head, 17);
    insert_at_back(&head, 18);
    insert_at_back(&head, 18);
    insert_at_back(&head, 44);
    insert_at_back(&head, 48);

    display(&head);

    remove_all(&head);
    display(&head);

    return 0;
}
