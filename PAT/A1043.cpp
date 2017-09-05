#include <cstdio>
#include <vector>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
    node(){
        lchild = rchild = NULL;
    }
};
vector<int> origin,pre,preM,post,postM;
void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        return;
    }
    if(root->data > data) insert(root->lchild, data);
    else insert(root->rchild, data);
}

void preOrder(node* root){
    if(root == NULL) return;
    pre.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void preOrderM(node* root){
    if(root == NULL) return;
    preM.push_back(root->data);
    preOrderM(root->rchild);
    preOrderM(root->lchild);
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post.push_back(root->data);
}

void postOrderM(node* root){
    if(root == NULL) return;
    postOrderM(root->rchild);
    postOrderM(root->lchild);
    postM.push_back(root->data);
}

int main(){
    int n,data;
    scanf("%d",&n);
    node* root = NULL;
    for(int i = 0;i < n;i++){
        scanf("%d",&data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root);
    preOrderM(root);
    postOrder(root);
    postOrderM(root);
    if(pre == origin){
        printf("YES\n");
        for(int i = 0;i < post.size();i++){
            printf("%d",post[i]);
            if(i < post.size()-1) printf(" ");
        }
        printf("\n");
    }else if(preM == origin){
        printf("YES\n");
        for(int i = 0;i < postM.size();i++){
            printf("%d",postM[i]);
            if(i < postM.size()-1) printf(" ");
        }
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
