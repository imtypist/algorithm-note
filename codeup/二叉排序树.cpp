#include <cstdio>

struct node{
    int el;
    node* lchild;
    node* rchild;
    node(){
        lchild = rchild = NULL;
    }
};

void preOrder(node* root){
    if(root == NULL) return;
    printf("%d ",root->el);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(node* root){
    if(root == NULL) return;
    inOrder(root->lchild);
    printf("%d ",root->el);
    inOrder(root->rchild);
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ",root->el);
}

void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->el = data;
        return;
    }
    if(root->el == data){
        return;
    }else if(root->el > data){
        insert(root->lchild, data);
    }else{
        insert(root->rchild, data);
    }
}

int main(){
    int n,data;
    while(scanf("%d",&n) != EOF){
        node* root = NULL;
        for(int i = 0;i < n;i++){
            scanf("%d",&data);
            insert(root, data);
        }
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        delete(root);
    }
    return 0;
}
