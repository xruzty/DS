#include "avltreenode.h"
#include<iostream>
using namespace std;

AVLTreeNode::AVLTreeNode(int v)
{
    this->val = v;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}
void AVLTreeNode::updateHeight(){
    int h1=0,h2=0;
    if(this->left)
        h1=this->left->height;
    if(this->right)
        h2=this->right->height;
    this->height = max(h1,h2)+1;
}
int AVLTreeNode::balance(){
    int h1=0,h2=0;
    if(this->left)
        h1 = this->left->height;
    if(this->right)
        h2 = this->right->height;
    return h1-h2;
}
AVLTreeNode* AVLTreeNode::rightRotate(){
    AVLTreeNode *l = this->left;
    if(!l)
        return this;
    AVLTreeNode *child = l->right;
    l->right = this;
    this->left = child;
    this->updateHeight();
    l->updateHeight();
    return l;
}
AVLTreeNode* AVLTreeNode::leftRotate(){
    AVLTreeNode *r = this->right;
    if(!r)
        return this;
    AVLTreeNode *child = r->left;
    r->left = this;
    this->right = child;
    this->updateHeight();
    r->updateHeight();
    return r;
}
