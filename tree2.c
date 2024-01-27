#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * create(int val){
    struct node * newnode =malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return (newnode);
}

void Preorder(struct node * root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

int main(){
    struct node * root = create(10);
    root->left=create(20);
    root->right=create(30);
    root->left->right=create(40);
    printf("preorder\t");
    Preorder(root);
    return 0;
}