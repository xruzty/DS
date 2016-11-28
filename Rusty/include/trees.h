#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED
#include "treenode.h"
#include <string>
#include<vector>
using namespace std;
void inorder(TreeNode*,int=1);
void preorder(TreeNode*,int=1);
void postorder(TreeNode*,int=1);
void commonNodesBST(TreeNode*,TreeNode*);
void kthLevel(TreeNode*,int);
void getLevel(TreeNode*,int);
void printCousins(TreeNode*,int);
void printCousins2(TreeNode*,int);
bool isSymmetric(TreeNode*,TreeNode*);
bool isSymmetricIter(TreeNode*);
int maxDepth(TreeNode*,int=1);
int minDepth(TreeNode*,int=1);
void DFS(TreeNode*);
int kthSmallest(TreeNode*,int);
TreeNode* createFrom(vector<int>&, vector<int>&);        // from Inorder & preorder
TreeNode* createFrom2(vector<int>&, vector<int>&);  // from Inorder & postorder
string serialize(TreeNode*);
TreeNode* deserialize(string);
#endif // TREES_H_INCLUDED
