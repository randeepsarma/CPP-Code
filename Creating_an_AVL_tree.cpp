#include <iostream>

using namespace std;

struct Node{
    int data,height;
    Node*left,*right;
    
};
Node*nodecreate(int num){
Node*ret=new Node();
ret->data=num;
ret->left=NULL;
ret->right=NULL;
ret->height=1;
return ret;
}
int max(int a ,int b){
    return (a>b)?a:b;
}
int getHeight(Node*root){
    if(!root)return 0;
    return root->height;
}
Node*turnright(Node*root){
Node*h=root->left;
Node*T=h->right;
h->right=root;
root->left=T;

root->height=max(getHeight(root->left),getHeight(root->right))+1;
h->height=max(getHeight(h->left),getHeight(h->right))+1;
return h;
}
Node*turnleft(Node*root){
Node*h=root->right;
Node*T=h->left;
h->left=root;
root->right=T;

root->height=max(getHeight(root->left),getHeight(root->right))+1;
h->height=max(getHeight(h->left),getHeight(h->right))+1;
return h;
}
Node*create(Node*&head,int num){
if(head==NULL)return nodecreate(num);
else if(num<head->data){
    head->left= create(head->left,num);
}else if(num>head->data){
    head->right=create(head->right,num);
}
head->height=max(getHeight(head->left),getHeight(head->right))+1;
int diff=getHeight(head->left)-getHeight(head->right);
if(diff>1 && head->left->data>num){
    return turnright(head);
}else if(diff<-1 && head->right->data<num){
    return turnleft(head);
}else if (diff>1 && head->left->data<num)
{head->left=turnleft(head->left);
return turnright(head);
}else {
head->right=turnright(head->right);
return turnleft(head);
}


return head;
}
void pfunct(Node*head){

if(!head)return;
pfunct(head->right);
cout<<head->data<<endl;
pfunct(head->left);

}
int main(){

Node*head=NULL;
head=create(head,12);
head=create(head,24);
head=create(head,25);
pfunct(head);
    return 0;
}



