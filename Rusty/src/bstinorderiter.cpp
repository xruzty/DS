#include "bstinorderiter.h"
#include "bst.h"
#include <stack>

BSTinorderIter::BSTinorderIter(BSTnode* r)
{   root = r; node = r;
    goDeep(node);

}
void BSTinorderIter::goDeep(BSTnode* p){
    while(p){
        S.push(p);
        p=p->left;
    }
}
bool BSTinorderIter::hasNext(){
    if(S.empty())
        return false;
    return true;
}
int BSTinorderIter::next(){
    node = S.top();
    int out = node->val;
    S.pop();
    node=node->right;
    goDeep(node);
    return out;
}
