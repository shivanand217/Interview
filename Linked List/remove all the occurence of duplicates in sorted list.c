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
    while( tmp->next != NULL ) {
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
                if( *head == NULL ) {
                    return;
                }
                if( tmp == NULL ) {
                    if(prev != NULL) {
                        prev->next = NULL;
                    }
                    return;
                }
            }
            if(*head == NULL) {
                return;
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
    insert_at_back(&head, 44);

    display(&head);

    remove_all(&head);
    display(&head);

    return 0;
}
