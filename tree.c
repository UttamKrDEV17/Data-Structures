#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * create(){
    int val;
    struct node * newnode = malloc(sizeof(struct node));
    printf("\nEnter the value:(-1 for no node.)");
    scanf("%d",&val);
    if(val==-1){
        return 0;
    }
    newnode->data=val;
    printf("\nEnter the value for left node of %d",val);
    newnode->left=create();
    printf("\nEnter the value for right node of %d",val);
    newnode->right=create();
    return newnode;
}

int countLeafNodes(struct node * tree){
    if(tree == NULL){
        return 0;
    }
    if(tree->left == NULL && tree->right == NULL){
        return 1;
    }
    return countLeafNodes(tree->left) + countLeafNodes(tree->right);
}

int main(){
    struct node * root;
    root=0;
    root = create();
    if(countLeafNodes(root)==0){
        printf(" 0 leaf node\n");
    }
    else
    printf("\n%d leaf are present in the tree.",countLeafNodes(root));
    return 0;
}