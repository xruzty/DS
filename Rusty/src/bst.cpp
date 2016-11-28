#include "bst.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


BSTnode* insert_node(BSTnode* root, BSTnode* node){
    if(!root)
        return node;
    BSTnode *p=root, *before;
    while(p){
        before=p;
        if(node->val<p->val){
            p->lcount++;
            p=p->left;
        }
        else
            p=p->right;
    }
    if(node->val<before->val){
        before->left=node;
    }
    else
        before->right=node;
    return root;
}
BSTnode* createUtil(vector<int> A, BSTnode* root, int l , int r){
        if(l>r)
            return nullptr;
        if(l==r)
            return insert_node(root,new BSTnode(A[l]));
        int m = l+(r-l)/2;
        root = insert_node(root,new BSTnode(A[m]));
        createUtil(A,root,l,m-1);
        createUtil(A,root,m+1,r);
        return root;
}
BSTnode* create_BST(vector<int> A){
    int m = (A.size()-1)/2;
    BSTnode* root = new BSTnode(A[m]);
    root = createUtil(A,root,0,m-1);
    root = createUtil(A,root,m+1, A.size()-1);
    return root;
}
bool isLeaf(BSTnode* node){
    if(!node)
        return true;
    return !node->left&&!node->right;
}
void inorder(BSTnode* root){
    stack<BSTnode*> s;
    while(!s.empty()||root){
        if(root){
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            cout<<root->val<<" ";
            root=root->right;
        }
    }
}
void preorder(BSTnode* root){
    stack<BSTnode*> s;
    while(!s.empty()||root){
        if(root){
            s.push(root);
            cout<<root->val<<" ";
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
}
vector<int> getPreorder(BSTnode* root){
    vector<int> out;
    if(!root)
        return out;
    stack<BSTnode*> s;
    while(root || !s.empty()){
        if(root){
            s.push(root);
            out.push_back(root->val);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
    return out;
}
void postorder(BSTnode* root){
    stack<BSTnode*> s;
    while(!s.empty()||root){
        while(!isLeaf(root)){
            s.push(root);
            root=root->left;
        }
        if(root)
            cout<<root->val<<" ";
        while(!s.empty()&&root==s.top()->right){
            root=s.top();
            s.pop();
            cout<<root->val<<" ";
        }
        if(s.empty())
            root=nullptr;
        else{
            root=s.top()->right;
        }
    }
}
int kthSmallest(BSTnode* root, int k){
    while(root->lcount+1!=k){
        if(root->lcount+1>k)
            root=root->left;
        else{
            k=k-root->lcount-1;
            root=root->right;
        }
    }
    return root->val;
}
BSTnode* c_preUtil(vector<int>& A, int i, int l){
    int n=A.size();
    if(i>=l)
        return nullptr;
    BSTnode* root = new BSTnode(A[i]);
    int j=i+1;
    while(j<n && A[j]<A[i])
        j++;
    if(i<n && A[i+1]<A[i])
        root->left = c_preUtil(A,i+1,j);
    root->right = c_preUtil(A,j,l);
    return root;
}
BSTnode* create_pre(vector<int>& A){
    int n=A.size();
    if(!n)
        return nullptr;
    return c_preUtil(A,0,n);
}
BSTnode* c_preUtil2(vector<int>& A, int* i, int max, int min){
    int n=A.size();
    if(*i>=n)
        return nullptr;
    int key=A[*i];
    if(key<=min || key>=max)
        return nullptr;
    *i = *i + 1;
    BSTnode* root = new BSTnode(key);
    root->left = c_preUtil2(A,i,key,min);
    root->right = c_preUtil2(A,i,max,key);

    return root;

}
BSTnode* create_pre2(vector<int>& A){
    int n=A.size();
    int index=0;
    int *i = &index;
    if(!n)
        return nullptr;
    return c_preUtil2(A,i,INT_MAX,INT_MIN);
}
BSTnode* c_postUtil(vector<int>& A, int i, int l){
    if(i<l)
        return nullptr;
    BSTnode* root = new BSTnode(A[i]);
    int j=i-1;
    while(j>=l && A[j]>A[i])
        j--;
    if(i-1>=l && A[i-1]>A[i])
        root->right = c_postUtil(A,i-1,j+1);
    root->left = c_postUtil(A,j,l);
    return root;

}
BSTnode* create_post(vector<int>& A){
    int n=A.size();
    if(!n)
        return nullptr;
    return c_postUtil(A,n-1,0);
}
BSTnode* c_postUtil2(vector<int>& A, int *i, int max, int min){
    if(*i<0)
        return nullptr;
    int key=A[*i];
    if(key<=min || key>=max)
        return nullptr;
    *i = *i - 1;
    BSTnode* root = new BSTnode(key);
    root->right = c_postUtil2(A,i,max,key);
    root->left = c_postUtil2(A,i,key,min);

    return root;
}
BSTnode* create_post2(vector<int>& A){
    int n=A.size();
    if(!n)
        return nullptr;
    int index = n-1;
    int *i = &index;
    return c_postUtil2(A,i,INT_MAX,INT_MIN);
}
