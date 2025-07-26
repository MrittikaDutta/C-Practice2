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
struct node* search(struct node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->l,key);
    }
    else{
        return search(root->r,key);
    }
}
void insert(struct node* root,int key){
    struct node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("already present");
            return ;
        }
        else if(key<root->data){
            root=root->l;
        }
        else{
            root=root->r;
        }
    }
    struct node* n=createnode(key);
    if(key<prev->data){
        root->l=n;
    }
    else{
        root->r=n;
    }
}
struct node* inOrderpre(struct node* root){
    root=root->l;
    while(root->r != NULL){
        root=root->r;
    }
    return root;
}
struct node *deletenode(struct node *root, int val){
    struct node* iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->l==NULL && root->r==NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->l=deletenode(root->l,val);
    }
    else if(val>root->data){
        root->r=deletenode(root->r,val);
    }
    else{
        iPre=inOrderpre(root);
        root->data=iPre->data;
        root->l=deletenode(root->l,iPre->data);
    }
    return root;
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
    deletenode(p,5);
    printf("\n");
    inOrder(p);
    return 0;
}