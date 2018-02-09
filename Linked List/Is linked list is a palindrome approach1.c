#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
    struct node *next;
};
void insert_at_back(struct node **head, char data) {
    if(*head == NULL) {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next=(struct node *)malloc(sizeof(struct node));
    tmp = tmp->next;
    tmp->data = data;
    tmp->next = NULL;
}
void insert_at_front(struct node **head, char data) {
    if( *head == NULL ) {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void display(struct node **head) {
    if( *head == NULL ) {
        return;
    }
    struct node *tmp = *head;
    while( tmp != NULL ) {
        printf("%c ", tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
int length(struct node **head) {
    if( *head == NULL ) {
        return 0;
    }
    int cnt = 0;
    struct node *tmp = *head;
    while( tmp != NULL ) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void palindrome(struct node **head, int len) {
    char str[len + 1];
    int i = 0;
    struct node *tmp = *head;
    while(tmp != NULL) {
        str[i++] = tmp->data;
        tmp = tmp->next;
    }
    int j=i-1;
    for(j=0; j < i; j++) {
        printf("%c",str[j]);
    }
}
int main() {
    char str1[] = "abcab";
    char str2[] = "KKKKK";

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int i;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(i = 0; i < len1; i++) {
        insert_at_back(&head1, str1[i]);
    }
    int len = length(&head);
    //display(&head1);

    return 0;
}
