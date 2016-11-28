#ifndef BST_H
#define BST_H
#include<vector>
#include "bstnode.h"
using namespace std;

BSTnode* create_BST(vector<int> A);
BSTnode* insert_node(BSTnode*, BSTnode*);
BSTnode* create_pre(vector<int>& A);
BSTnode* create_pre2(vector<int>& A);
BSTnode* create_post(vector<int>& A);
BSTnode* create_post2(vector<int>& A);
void inorder(BSTnode*);
void preorder(BSTnode*);
vector<int> getPreorder(BSTnode*);
void postorder(BSTnode*);
int kthSmallest(BSTnode*,int);

#endif // BST_H
