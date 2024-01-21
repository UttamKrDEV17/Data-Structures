#include<stdio.h>
#include<stdlib.h>

struct node {
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
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

/*delete element from the end*/
void delete_end(struct node ** head){
    struct node * temp;
    struct node * current = *head;
    while(current->next!=NULL){
        temp=current;
        current=current->next;
    }
    temp->next=NULL;
    free(current);
}  

/*delete element at beginning*/
void delete_beg(struct node ** head){
    *head = (*head)->next;
    free(head);
}

/*Deletion in singly linked list after the specified node*/
void deleteNode(struct node **head, int position) {
  struct node *temp, *prev;
  int i;

  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (position == 1) {
    *head = (*head)->next;
    free(temp);
    return;
  }
  temp = *head;
  for (i = 1; i < position; i++) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  free(temp);
}

int main(){
    struct node * head = NULL;
    int n,value,a;
    printf("Enter the no. of node to be present in the linked list:\t");
    scanf("%d",&n);
    printf("\nEnter the node here:\t");
    for(int i=1;i<=n;i++){
        scanf("%d",&value);
        addnode(&head,value);
    }
    printlist(head);
    printf("Enter the value of position here:\t");
    scanf("%d",&a);
    deleteNode(&head,a);
    printlist(head);
    return 0;
}
