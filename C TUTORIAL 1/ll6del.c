#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* cnode(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
};
typedef struct node node;

int main(){
    int n,i,v,c,p,rem ;
    printf("enter the number of nodes :");
    scanf("%d",&n);
    if(n<=0){
        printf("invalid \n");
        return 1;
    }
    struct node* head=NULL;
    struct node* current=NULL;
    for(i=0;i<n;i++){
        printf("enter value :");
        scanf("%d",&v);
        struct node* newnode= cnode(v);
        if(head==NULL){
            head=newnode;
            current=head;
        }
        else{
            current->next=newnode;
            current=newnode;
        }
        
        
    }
    current=head;
    while(current!=NULL){
        printf("%d  ",current->data);
        current=current->next;
    }
    printf("null \n");
    current=head;
    printf("enter element to delete");
    scanf("%d",&c);
    while(current!=NULL){
        if(c==current->data){

            current=current->next->next;

        }

    }
    current=head;
    while(current!=NULL){
        printf("%d  ",current->data);
        current=current->next;
    }
    return 0;
}