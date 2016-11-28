#ifndef BSTINORDERITER_H
#define BSTINORDERITER_H
#include "bstnode.h"
#include <stack>


class BSTinorderIter
{
    public:
        BSTinorderIter(BSTnode* root);
        bool hasNext();
        int next();

    protected:

    private:
        std::stack<BSTnode*> S;
        BSTnode *node, *root;
        void goDeep(BSTnode* p);
};

#endif // BSTINORDERITER_H
