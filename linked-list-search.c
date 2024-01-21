#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

int addnode(struct node ** head,int value){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=*head;
    *head=newnode;
}

/*check whether the node is present or not*/
int search(struct node * head,int val){
    struct node * temp = head; //intalize temp
    int count=1;
    while(temp!=NULL){
        if(temp->data==val){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return 0;
}

int main(){
    struct node * head = NULL;
    int x;
    printf("Enter the data to be searched: \n");
    scanf("%d",&x);

    addnode(&head,10);
    addnode(&head,20);
    addnode(&head,30);
    addnode(&head,40);
    addnode(&head,50);
    addnode(&head,60);
    addnode(&head,70);

    int a=search(head,x);
    if(a!=0)
    printf("The searched data is at %d th position:",a);
    else
    printf("data not found....");
    return 0;
}