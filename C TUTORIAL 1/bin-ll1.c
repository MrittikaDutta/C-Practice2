#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* l;
    struct node* r;
};
struct node* cnode(int data){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->l=NULL;
    n->r=NULL;
    return n;
};
int main(){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->l=NULL;
    p->r=NULL;
    struct node* p1;
    p=(struct node*)malloc(sizeof(struct node));
    p->l=NULL;
    p->r=NULL;
    struct node* p2;
    p=(struct node*)malloc(sizeof(struct node));
    p->l=NULL;
    p->r=NULL;
    return 0;
}
