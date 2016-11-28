#include "avltree.h"
#include<iostream>
using namespace std;

AVLTree::AVLTree()
{
    this->root = nullptr;
}
AVLTreeNode* insertH(AVLTreeNode* node, int k){
    if(!node)
        return (new AVLTreeNode(k));
    else if(k<node->val)
        node->left = insertH(node->left,k);
    else if(k>node->val)
        node->right = insertH(node->right,k);
    node->updateHeight();
    int b = node->balance();
    if(b>1 && k<node->left->val){
        return node->rightRotate();
    }
    else if(b>1 && k>node->left->val){
        node->left = node->left->leftRotate();
        return node->rightRotate();
    }
    else if(b<-1 && k>node->right->val){
        return node->leftRotate();
    }
    else if(b<-1 && k<node->right->val){
        node->right = node->right->rightRotate();
        return node->leftRotate();
    }
    return node;
}
void AVLTree::insert(int key){
    this->root = insertH(this->root,key);
}
void inorder(AVLTreeNode* root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
void AVLTree::printInorder(){
    cout<<"Inorder Traversal : ";
    inorder(this->root);
    cout<<endl;
}
