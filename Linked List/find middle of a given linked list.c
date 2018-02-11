#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head, int data) {
    if(*head == NULL) {
        *head=(struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp = tmp->next;
    tmp->data=data;
    tmp->next=NULL;
    return;
}
void insert_front(struct node **head, int data) {
    if(*head == NULL) {
        *head=(struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next = (*head);
    *head = tmp;
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
int count(struct node **head) {
    if(*head == NULL){
        return 0;
    }
    int cnt = 0;
    struct node *tmp = *head;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void middle_node(struct node **head,int cnt_nodes) {
    if(*head == NULL){
        return;
    }
    int cnt=0;
    struct node *tmp = *head;
    int middle = (cnt_nodes/2);
    while(cnt <= (middle)) {
        cnt++;
        if( cnt == middle ) {
            if( cnt_nodes%2 == 1) {
                tmp=tmp->next;
                printf("middle node is %d\n",tmp->data);
                break;
            } else {
                printf("middle node is %d and %d\n",tmp->data,tmp->next->data);
                break;
            }
        }
        tmp=tmp->next;
    }
    return;
}
void display(struct node **head){
    if(*head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct node *tmp = *head;
    while(tmp != NULL) {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
int main() {
    struct node *head = NULL;

    insert_back(&head, 18);
    insert_back(&head, 12);
    insert_back(&head, 17);
    insert_back(&head,20);
    insert_back(&head,25);
    insert_back(&head,28);
    insert_back(&head,30);
    insert_back(&head,31);

    int cnt_nodes=count(&head);
    printf("total nodes are %d\n",cnt_nodes);
    display(&head);
    middle_node(&head, cnt_nodes);

    return 0;
}
