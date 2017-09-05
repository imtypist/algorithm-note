#include <stdio.h>
#include <math.h>
struct node{
    int high,data;
    node *lchild,*rchild;
    node(){
        lchild = rchild = NULL;
    }
};

int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

int getHeight(node* root){
    if(root == NULL) return 0;
    return root->high;
}

void updateHeight(node* root){
    return max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->high = 1;
        return;
    }
    if(root->data > data){
        insert(root->lchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            int L = getBalanceFactor(root->lchild);
            if(L == 1){ // LL
                R(root);
            }else if(L == -1){ // LR
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            int R = getBalanceFactor(root->rchild);
            if(R == 1){ // RL
                R(root-rchild);
                L(root);
            }else if(R == -1){
                L(root);
            }
        }
    }
}
