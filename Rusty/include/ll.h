#ifndef LL_H
#define LL_H
#include "listnode.h"
using namespace std;


ListNode* rev(ListNode* head,int=1);
ListNode* rev2(ListNode* head,int&,int&,int=1);
int isPalindrome(ListNode*);
ListNode* countSort(ListNode*);
ListNode* revK(ListNode*, int,int=1);
ListNode* insertSort(ListNode*);
ListNode* mergeSort(ListNode*);
ListNode* rotateLeft(ListNode*, int);
ListNode* rotateRight(ListNode*, int);
ListNode* merge2(ListNode* , ListNode* , int=1);
ListNode* partition(ListNode*, int);
ListNode* swap2(ListNode*, int=1);                //swap every nodes in pairs
ListNode* add(ListNode*,ListNode*,int=1);
ListNode* sub(ListNode*,ListNode*);               //absolute diff
int binToDec(ListNode*,int* = nullptr,int=1);
ListNode* merge2a(ListNode*,ListNode*);           //Merge two sorted lists in descending order
#endif // LL_H
