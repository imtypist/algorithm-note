#include <cstdio>
#include <string.h>
const int maxn = 30;
char pre[maxn],in[maxn];
int len;
struct node{
    char el;
    node* left;
    node* right;
};

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;
    }
    node* s = new node;
    s->el = pre[preL];
    int k;
    for(k = inL;k <= inR;k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numLeft = k - inL;

    s->left = create(preL + 1, preL + numLeft, inL, k - 1);
    s->right = create(preL + numLeft + 1, preR, k + 1, inR);
    return s;
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->el);
}

int main(){
    while(scanf("%s %s",pre,in) != EOF){
        len = strlen(pre);
        node* root = create(0,len-1,0,len-1);
        postOrder(root);
        printf("\n");
    }
    return 0;
}
