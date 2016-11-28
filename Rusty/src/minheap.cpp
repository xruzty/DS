#include "minheap.h"

minHeap::minHeap(vector<ListNode*> D)
{   n = D.size();
    for(int i=0;i<n;i++)
        A.push_back(D[i]);
    for(int i=n/2-1;i>=0;i--)
        heapify(i);

}
void minHeap::heapify(int i){
    int l=2*i+1;
    int r=2*i+2;
    int low = i;
    if(l<n && A[l]->val<A[i]->val){
        low = l;
    }
    if(r<n && A[r]->val<A[low]->val){
        low = r;
    }
    if(low!=i){
        ListNode* temp = A[i];
        A[i]=A[low];
        A[low] = temp;
        heapify(low);
    }
}
ListNode* minHeap::pop(){
    if(!n)
        return nullptr;
    ListNode* temp = A[n-1];
    A[n-1] = A[0];
    A[0] = temp;
    n--;
    heapify(0);
    ListNode *out = A[n];
    A.pop_back();
    return out;
}
bool minHeap::isEmpty(){
    if(!n)
        return true;
    return false;
}
void minHeap::insert(ListNode* D){
    A.push_back(D);
    n++;
    int i = n-1;
    int p = (i-1)/2;
    while(p>=0 && A[i]->val<A[p]->val){
        ListNode *temp = A[i];
        A[i]=A[p];
        A[p]=temp;
        heapify(i);
        i=p;
        p=(i-1)/2;
    }
}
