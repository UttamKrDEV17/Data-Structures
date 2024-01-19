/*this code is for double linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node * next;
    struct node * prev;
};


/*adding node from the beggining*/
void addnode(struct node ** head,int data){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->info=data;
    newnode->next=*head;
    newnode->prev=NULL;
    if(*head!=NULL){
        (*head)->prev=newnode;
    }
    *head=newnode;
}

void print_lisr(struct node * head){
    while(head!=NULL){
        printf("%d\t",head->info);
        head=head->next;
    }
    printf("NULL");
}

int main(){
    struct node * head = NULL;

    addnode(&head,10);
    addnode(&head,20);
    addnode(&head,30);
    addnode(&head,40);

    print_lisr(head);

    return 0;
}