#ifndef MINHEAP_H
#define MINHEAP_H
#include<vector>
#include "listnode.h"
using namespace std;


class minHeap
{   vector<ListNode*> A;
    int n;
    public:
        minHeap(vector<ListNode*>);
        ListNode* pop();
        void insert(ListNode*);
        bool isEmpty();

    protected:

    private:
        void heapify(int);
};

#endif // MINHEAP_H
