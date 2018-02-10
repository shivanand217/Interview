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
                printf("%d\n",tmp->data);
                break;
            } else {
                printf("%d %d\n",tmp->data,tmp->next->data);
                break;
            }
        }
        tmp=tmp->next;
    }
    return;
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

    int cnt_nodes=count(&head);
    printf("%d\n",cnt_nodes);
    middle_node(&head, cnt_nodes);

    return 0;
}
