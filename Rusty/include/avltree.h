#ifndef AVLTREE_H
#define AVLTREE_H
#include"avltreenode.h"


class AVLTree
{   public:
        AVLTreeNode* root;
        AVLTree();
        void insert(int key);
        void printInorder();

    protected:

    private:
};

#endif // AVLTREE_H
