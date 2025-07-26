#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*l;
    struct node*r;
};

struct node* cnode(int d){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->l=NULL;
    n->r=NULL;
    return n;
}
int main(){
    struct node* p=cnode(9);
    struct node* p1=cnode(9);
    struct node* p2=cnode(9);
    p->l=p1;
    p->l=p2;
    return 0;
}
