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
void insert_at_front(struct node **head, int data) {
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

void segregate(struct node **head1,struct node **head2) {
    if(*head1 == NULL)
        return;

    if( (*head1)->next == NULL ) {
        return;
    }

    /** even linked list head1 , odd head2 **/
    struct node *tmp1 = *head1;
    struct node *tmp2 = *head2;
    struct node *prev = NULL;

    while(tmp1 != NULL) {
        if(tmp1->data % 2 == 1) {
            if( prev == NULL ) {
                if((*head1) != NULL)
                    (*head1) = (*head1)->next;
                if((*head2) == NULL) {
                    (*head2) = tmp1;
                    tmp2 = (*head2);
                } else {
                    tmp2->next = tmp1;
                    tmp2 = tmp2->next;
                }
            } else {
                if((*head2) == NULL) {
                    (*head2) = tmp1;
                    tmp2 = (*head2);
                } else {
                    tmp2->next = tmp1;
                    tmp2 = tmp2->next;
                }
                prev->next = NULL;
            }
        } else {
            if(prev != NULL) {
                prev->next = tmp1;
            }
            prev=tmp1;
        }
        tmp1 = tmp1->next;
    }
    tmp2->next = NULL;

}

void merge(struct node **head1,struct node **head2) {
    if(*head1 == NULL || *head2 == NULL)
        return;

    struct node *tmp1 = *head1;
    struct node *tmp2 = *head2;

    while(tmp1->next != NULL) {
        tmp1 = tmp1->next;
    }

    /** link to odd list **/
    tmp1->next = (*head2);
}

int main() {

    struct node *head1 = NULL;
    insert_at_back(&head1, 17);
    insert_at_back(&head1, 15);
    insert_at_back(&head1, 8);
    insert_at_back(&head1, 12);
    insert_at_back(&head1, 10);
    insert_at_back(&head1, 5);
    insert_at_back(&head1, 4);
    insert_at_back(&head1, 1);
    insert_at_back(&head1, 7);
    insert_at_back(&head1, 6);
    insert_at_back(&head1, 9);

    display(&head1);

    struct node *head2 = NULL;

    segregate(&head1, &head2);

    display(&head1);
    display(&head2);

    merge(&head1, &head2);
    display(&head1);

    return 0;
}
