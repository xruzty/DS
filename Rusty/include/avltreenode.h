#ifndef AVLTREENODE_H
#define AVLTREENODE_H


class AVLTreeNode
{   public:
    int val;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;

        AVLTreeNode(int);
        void updateHeight();
        int balance();
        AVLTreeNode* rightRotate();
        AVLTreeNode* leftRotate();

    protected:

    private:
};

#endif // AVLTREENODE_H
