#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node * next;
};

void addnode(struct node ** head,int value){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=*head;
    *head=newnode;
}

void printlist(struct node * head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

void reverse(struct node ** head){
    struct node * prev = NULL;
    struct node * current = *head;
    struct node * next = NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head = prev;
}

int main(){
    clock_t start = clock();
    struct node * head = NULL;
    addnode(&head,10);
    addnode(&head,20);
    addnode(&head,30);
    addnode(&head,40);  
    
    printf("The linked list here:");
    printlist(head);

    reverse(&head);
    printf("The reverse list here:");
    printlist(head);

    clock_t end = clock();
    float seconds =(end - start)/CLOCKS_PER_SEC;
    return 0;
}
