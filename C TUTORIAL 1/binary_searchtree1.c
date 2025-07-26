#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*l;
    struct node*r;
    
};
struct node* createnode(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->r=NULL;
    newnode->l=NULL;
    return newnode;
};
int isBST(struct node* root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->l)){
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->r);
    }
    else{
        return 1;
    }
}
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->l);
        printf("%d",root->data);
        inOrder(root->r);
    }
}
int main(){
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);

    p->l=p1;
    p->r=p2;
    p1->l=p3;
    p1->r=p4;
    inOrder(p);
    printf("\n%d \n",isBST(p));
}
