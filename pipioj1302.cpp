#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* lchild;
    node* rchild;
    node(int v){
        value = v;
        lchild = NULL;
        rchild = NULL;
    }
};

struct answer{
    int depth;
    int parent;
    answer(int d,int p){
        depth = d;
        parent = p;
    }
};

node* preBuild(){
    int value;
    scanf("%d",&value);
    if(value==-1)return NULL;
    node* root = new node(value);
    root->lchild = preBuild();
    root->rchild = preBuild();
    return root;
}

answer* find_depth_and_parent(node* root,int x,int depth,int parent){
    if(root==NULL)return NULL;
    if(root->value==x){
        answer* ans = new answer(depth,parent);
        return ans;
    }
    if(find_depth_and_parent(root->lchild,x,depth+1,root->value)!=NULL)return find_depth_and_parent(root->lchild,x,depth+1,root->value);
    else return find_depth_and_parent(root->rchild,x,depth+1,root->value);
}

int main(){
    node* root = preBuild();
    int x,y;
    scanf("%d %d",&x,&y);
    answer* firstOne = find_depth_and_parent(root,x,1,-2);
    answer* secondOne = find_depth_and_parent(root,y,1,-2);
    if(x!=y&&firstOne->depth==secondOne->depth){
        if(firstOne->parent==secondOne->parent)printf("brother\n");
        else printf("cousin\n");
    }else{
        printf("other relathionship\n");
    }
    // printf("%d %d\n",ans->depth,ans->parent);
    return 0;
}