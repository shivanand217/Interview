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
void alternating_split(struct node **head1, struct node **head2) {
    if( *head1 == NULL )
        return;
    if( (*head1)->next == NULL ) {
        return;
    }
    struct node *tmp1 = *head1;
    (*head2) = (*head1)->next;
    struct node *tmp2 = (*head2);
    while(tmp1 != NULL || tmp2 != NULL) {
        if(tmp1 != NULL) {
            if(tmp1->next == NULL) {
                /** do nothing **/
            } else if(tmp1->next->next == NULL){
                tmp1->next = NULL;
            } else {
                tmp1->next = tmp1->next->next;
            }
            tmp1=tmp1->next;
        }
        if(tmp2 != NULL) {
            if(tmp2->next == NULL) {
                /** do nothing **/
            } else if(tmp2->next->next == NULL) {
                tmp2->next = NULL;
            } else {
                tmp2->next = tmp2->next->next;
            }
            tmp2=tmp2->next;
        }
    }
}
int main() {

    struct node *head1 = NULL;
    insert_at_back(&head1, 0);
    insert_at_back(&head1, 1);
    insert_at_back(&head1, 0);
    insert_at_back(&head1, 1);
    insert_at_back(&head1, 0);
    insert_at_back(&head1, 1);
    insert_at_back(&head1, 0);
    insert_at_back(&head1, 1);
    insert_at_back(&head1, 3);
    insert_at_back(&head1, 2);

    display(&head1);

    struct node *head2 = NULL;
    alternating_split(&head1, &head2);

    display(&head1);
    display(&head2);

    return 0;
}

