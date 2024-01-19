#include<stdio.h>
#include<stdlib.h>

// A Single linked list node
struct node {
    int data;
    struct node * next;
};

/* Given a reference (pointer to pointer) to the head of a
   list
   and an int,  inserts a new node on the front of the list.
 */
void addnode(struct node ** head,int value){
    /* 1. allocate node */
    struct node * newnode = malloc(sizeof(struct node));
    /* 2. put in the data  */
    newnode->data = value;
    /* 3. Make next of new node as head */
    newnode->next = *head;
    /* 4. move the head to point to the new node */
    *head = newnode;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertafter(struct node **head, int val, int position)
{
    /*allocate a newnode*/
struct node *newNode;
newNode = malloc(sizeof(struct node));
    /*Putting the data in newnode*/
newNode->data = val;
    /*creating a pointer struct to traverse within list*/
struct node *temp = *head;

    /*now traverse to find the position that in which data to be inserted*/
for(int i=1; i < position; i++)
{  
    if(temp->next != NULL) 
        {
            temp = temp->next; 
        }
}
    /**/
newNode->next = temp->next;
temp->next = newNode; 
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void insert_end(struct node ** head,int value){
    /*1.Allocate node*/
    struct node * newnode = malloc(sizeof(struct node));
    struct node * temp = *head;
    /*2.put data*/
    newnode->data=value;
    /*3.newnode is going to be last node thus memory address will be*/
    newnode->next=NULL;
    /*4.if list is empty then our newnode will be 1st node*/
    if(*head == NULL){
        *head=newnode;
        return;
    }
    /*5.else traverse till the end of list*/
    while(temp->next!=NULL){
        temp=temp->next;
    }
    /*6.Change the next of last node*/
    temp->next=newnode;
    return;
}

/*for printing the linked list*/
void print_list(struct node * head){
    struct node * temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    struct node * head =NULL;

    int alone,n,i,x;

    printf("Enter the number of node in linked list.");
    scanf("%d",&n);

    for(i=n;i>0;i--){
        printf("Enter the  node %d here:\t",i);
        scanf("%d",&x);
        addnode(&head,x);
    }

    printf("link list here:\n");
    print_list(head);

    printf("***MENU***\n");
    printf("1.NODE AT FIRST POSITION\n");
    printf("2.NODE AT SPECIFIC POSITION\n");
    printf("3.NODE AT LAST POSITION\n");
    printf("4.PRINT LINKED LIST\n");
    printf("5.EXIT\n");

    do
    {
        printf("ENTER YOUR CHOICE");
        scanf("%d",&alone);
        int val,position;
        switch (alone)
        {
        case 1:
            printf("enter the value for first node:\t");
            scanf("%d",&val);
            addnode(&head,val);
            printf("\n");
            break;

        case 2:
            printf("enter the value for specific node:\t");
            scanf("%d",&val);
            printf("enter specific position here:\t");
            scanf("%d",&position);
            insertafter(&head,val,position);
            printf("\n");
            break;

        case 3:
            printf("enter the value for last node:\t");
            scanf("%d",&val);
            insert_end(&head,val);
            printf("\n");
            break;

        case 4:
            printf("linked list here:\n");
            print_list(head);
            break;

        default:
            printf("ERROR 404\n");
            exit(1);
            break;
            
        }
    }while(alone>=5);

    return 0;
}
