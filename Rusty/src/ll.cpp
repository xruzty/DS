#include "ll.h"
#include <vector>
#include <stack>
#include <iostream>
#include <math.h>
using namespace std;

ListNode* rev(ListNode* head, int iter){
    if(!head || !head->next)
        return head;
    if(iter){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    else{
        ListNode* p = rev(head->next,0);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
}
ListNode* rev2(ListNode* head, int& a, int& b, int iter){
    if(iter){
        ListNode* node=head, *pre=nullptr, *last=nullptr;
        for(int i=0;i<a-1;i++){
            pre=node;
            node=node->next;
        }
        last=node;
        if(!pre){
            pre=node;
            head=nullptr;
        }

        for(int i=0;i<b-a+1;i++)
            last=last->next;
        ListNode *prev=nullptr;

        while(node!=last){
            ListNode *next = node->next;
            node->next=prev;
            prev=node;
            node=next;
        }
        if(head){
            pre->next->next=last;
            pre->next=prev;
        }
        else{
            head=prev;
            pre->next=last;
        }
        return head;
    }
    else{
            return nullptr;
    }
}
int isPalindrome(ListNode* head){
    if(!head || !head->next)
        return 1;
    ListNode *lag = head, *lead = head, *before=head;
    while(lead->next && lead->next->next){
        before = lag;
        lag=lag->next;
        lead=lead->next->next;
    }
    ListNode *prev = NULL;
    lead = lag;
    while(lag){
        ListNode* next = lag->next;
        lag->next=prev;
        prev=lag;
        lag=next;
    }
    int p=1;
    while(head && prev){
        if(head->val!=prev->val){
            p=0;
            break;
        }
        head=head->next;
        prev=prev->next;
    }
    prev=NULL;
    while(lead){
        ListNode* next = lead->next;
        lead->next=prev;
        prev=lead;
        lead=next;
    }
    before->next= prev;

    return p;
}
ListNode* countSort(ListNode* head){
    // Assume the 3 val are 1 2 and 3
    if(!head)
        return head;
    ListNode *onel = nullptr,*oner = nullptr, *twol= nullptr,*twor=nullptr, *thl = nullptr,*thr=nullptr, *node = head;
    while(node){
        if(node->val==1){
            if(!onel){
            onel=node;
            oner=node;
            }
            else{
                oner->next=node;
                oner=node;
            }
        }
        else if(node->val==2){
            if(!twol){
                twol=node;
                twor=node;
            }
            else{
                twor->next=node;
                twor=node;
            }
        }
        else{
            if(!thl){
                thl=node;
                thr=node;
            }
            else{
                thr->next=node;
                thr=node;
            }
        }
        node=node->next;
    }
    oner->next=twol;
    twor->next=thl;
    thr->next=nullptr;
    return head;

}
ListNode* revK(ListNode* head, int k, int iter){
    if(iter){
        if(!head)
            return head;
        ListNode *start = new ListNode(0);
        start->next=head;
        ListNode *i=head, *j=start, *old=start;
        while(1){
            for(int i=0;i<k;i++){
                if(!j->next){
                    delete start;
                    return head;
                }
                j=j->next;
            }
            if(i==head)
                head=j;
            old->next=j;
            old=i;
            ListNode *prev=nullptr;
            ListNode *end= j->next;
            while(i!=end){
                ListNode* next = i->next;
                i->next=prev;
                prev=i;
                i=next;
            }
            old->next=i;
            j=old;
        }
    }
    else{
        if(!head || !head->next || k==1)
            return head;
        ListNode* prev = head;
        for(int i=0;i<k;i++){
            if(!prev)
                return head;
            prev=prev->next;
        }
        prev = revK(prev,k,0);
        for(int i=0;i<k;i++){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

}
ListNode* insertSort(ListNode* head){
    if(!head || !head->next)
        return head;
    ListNode *end = head, *node=head->next;
    while(node){
        if(node->val<=head->val){
            ListNode* next = node->next;
            node->next=head;
            head=node;
            node=next;
        }
        else if(node->val>=end->val){
            end->next=node;
            end = node;
            node=node->next;
        }
        else{
            ListNode* next = node->next, *p = head;
            while(p->next->val<node->val)
                p=p->next;
            ListNode *temp = p->next;
            p->next = node;
            node->next = temp;
            node=next;
        }
    }
    end->next=nullptr;
    return head;
}
ListNode* mergeSort(ListNode* head){
    if(!head || !head->next)
        return head;
    ListNode *lag = head, *lead = head;
    while(lead->next && lead->next->next){
        lag = lag->next;
        lead = lead->next->next;
    }
    ListNode* head2 = lag->next;
    lag->next = nullptr;
    return merge2(mergeSort(head),mergeSort(head2));
}
ListNode* rotateLeft(ListNode* head, int k){
    if(!head || !head->next || !k)
        return head;
    ListNode *a = nullptr, *b = head, *last=nullptr;
    int i=0;
    while(i<k && b){
        a=b;
        b=b->next;
        i++;
    }
    if(!b){
        last = a;
        int r=k%i;
        if(!r)
            return head;
        a=nullptr;
        b=head;
        for(int j=0;j<r;j++){
            a=b;
            b=b->next;
        }
    }
    else{
        last = b;
        while(last->next)
            last=last->next;
    }
    a->next = nullptr;
    last->next = head;
    return b;
}
ListNode* rotateRight(ListNode* head, int k){
    if(!head || !head->next || !k)
        return head;
    ListNode *a=head, *b=head;
    int i=0;
    while(i<k && b){
        b=b->next;
        i++;
    }
    if(!b){
        int r = k%i;
        if(!r)
            return head;
        b = head;
        for(int j=0;j<r;j++)
            b=b->next;
    }
    while(b->next){
        a=a->next;
        b=b->next;
    }
    ListNode* newHead = a->next;
    a->next = nullptr;
    b->next = head;
    return newHead;
}
ListNode* merge2(ListNode* A, ListNode* B, int iter){
    if(!iter){
        if(!A)
            return B;
        if(!B)
            return A;
        if(A->val<B->val){
            ListNode* head = A;
            A->next = merge2(A->next,B,iter);
            return head;
        }
        else{
            ListNode* head = B;
            B->next = merge2(A,B->next,iter);
            return head;
        }
    }
    else{
        if(!A)
            return B;
        if(!B)
            return A;
        ListNode *head =nullptr,*tail = nullptr;
        if(A->val<B->val){
            head = A;
            tail = A;
            A=A->next;
            tail->next = nullptr;
        }
        else{
            head = B;
            tail = B;
            B=B->next;
            tail->next = nullptr;
        }
        while(A&&B){
            if(A->val<B->val){
                tail->next = A;
                tail = A;
                A=A->next;
                tail->next = nullptr;
            }
            else{
                tail->next = B;
                tail = B;
                B=B->next;
                tail->next = nullptr;
            }
        }
        while(A){
            tail->next = A;
            tail = A;
            A=A->next;
            tail->next=nullptr;
        }
        while(B){
            tail->next = B;
            tail = B;
            B=B->next;
            tail->next=nullptr;
        }
        return head;
    }
}
ListNode* partition(ListNode* head, int x){
    if(!head || !head->next)
        return head;
    ListNode *lHead=nullptr, *lTail=nullptr, *rHead=nullptr, *rTail=nullptr;
    while(head){
        if(head->val<x){
            if(!lHead){
                lHead=head;
                lTail=head;
                head=head->next;
                lTail->next=nullptr;
            }
            else{
                lTail->next = head;
                lTail=head;
                head=head->next;
                lTail->next=nullptr;
            }
        }
        else{
            if(!rHead){
                rHead=head;
                rTail=head;
                head=head->next;
                rTail->next=nullptr;
            }
            else{
                rTail->next = head;
                rTail=head;
                head=head->next;
                rTail->next=nullptr;
            }
        }
    }
    if(!lHead)
        return rHead;
    lTail->next=rHead;
    return lHead;
}
ListNode* swap2(ListNode* head, int iter){
    if(iter){
        if(!head||!head->next)
            return head;
        ListNode *prev=nullptr, *node=head, *n1=nullptr, *n2=nullptr;
        while(node){
            n1=node->next;
            if(!n1)
                return head;
            n2=n1->next;
            if(prev)
                prev->next=n1;
            else
                head=n1;
            node->next=n2;
            n1->next=node;
            prev=node;
            node=n2;
        }
        return head;
    }
    else{
        if(!head||!head->next)
            return head;
        ListNode* p=swap2(head->next->next,0);
        ListNode *q=head->next;
        q->next=head;
        head->next=p;
        return q;
    }
}
ListNode* addR(ListNode* l1, ListNode* l2, int *c){
    if(!l1)
        return nullptr;
    ListNode *out = new ListNode(0);
    out->next = addR(l1->next,l2->next,c);
    int sum = l1->val+l2->val+*c;
    out->val = sum%10;
    *c=sum/10;
    return out;
}
ListNode* add(ListNode* l1, ListNode* l2, int modify){

    if(modify){
        l1=rev(l1);l2=rev(l2);
        ListNode *h1=l1, *h2=l2;
        ListNode *start = new ListNode(0), *tail = start;
        int sum=0,c=0;
        while(c||h1||h2){
            sum = 1;
            if(h1&&h2)
                sum = h1->val+h2->val+c;
            else if(h1)
                sum = h1->val+c;
            else if(h2)
                sum = h2->val+c;
            if(sum<10){
                tail->next = new ListNode(sum);
                c=0;
            }
            else{
                tail->next = new ListNode(sum%10);
                c=1;
            }
            if(h1) h1=h1->next;
            if(h2) h2=h2->next;
            tail=tail->next;
        }
        tail->next = NULL;
        tail=start->next;
        delete start;
        l1=rev(l1);l2=rev(l2);
        return rev(tail);
    }
    else{
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p1=l1, *p2=l2;
        while(p1->next&&p2->next){
            p1=p1->next;p2=p2->next;
        }
        if(!p2->next)
            p2=l1;
        if(!p1->next)
            p1=l2;
        while(p1->next&&p2->next){
            p1=p1->next;p2=p2->next;
        }
        int c=0; ListNode *big=nullptr;
        ListNode *n1=nullptr, *n2=nullptr;
        if(!p1->next){
            n1 = p2;
            n2 = l2;
            big=l1;
        }
        else{
            n1 = p1;
            n2 = l1;
            big=l2;
        }

        ListNode * out = addR(n1,n2,&c);
        if((n1==l1||n1==l2)){
            if(!c)
                return out;
            else{
                ListNode *out2 = new ListNode(1);
                out2->next=out;
                return out2;
            }
        }
        else{
            ListNode *head=new ListNode(big->val),*tail=head;
            big=big->next;
            while(big!=n1){
                tail->next= new ListNode(big->val);
                tail=tail->next;
            }

            if(!c){
                tail->next=out;
                return head;
            }
            else{
                head=rev(head);
                ListNode *node=head,*prev=nullptr;
                while(c&&node){
                    int sum = node->val+1;
                    node->val = sum%10;
                    c = sum/10;
                    prev=node;
                    node=node->next;
                }
                if(c)
                    prev->next=new ListNode(1);
                head=rev(head);

                tail->next=out;
                return head;
            }
        }
    }
}
ListNode* subR(ListNode* l1, ListNode* l2, int *b){
    if(!l1)
        return nullptr;

    ListNode *out = new ListNode(0);
    out->next = subR(l1->next,l2->next,b);
    int v1=l1->val,v2=l2->val;
    if(*b)
        v1--;
    if(v1>=v2){
        out->val = v1-v2;
        *b=0;
    }
    else{
        out->val = 10+v1-v2;
        *b=1;
    }
    return out;
}
ListNode* sub(ListNode* l1, ListNode* l2){
    if(!l1)return l2;
    if(!l2)return l1;
    ListNode *n1=l1, *n2=l2, *big=nullptr, *small=nullptr, *p=nullptr, *out=nullptr;
    while(n1->next&&n2->next){
        n1=n1->next;n2=n2->next;
    }
    int b=0;
    if(!n1->next && !n2->next){
        if(l1->val>l2->val){
            big=l1;
            small=l2;
        }
        else{
            big=l2;
            small=l1;
        }
        out = subR(big,small,&b);
        return out;
    }
    else if(!n2->next){
        big = l1;
        small =l2;
        n2=l1;
        while(n2->next&&n1->next){
            n1=n1->next; n2=n2->next;
        }
        p = n2;
        out = subR(n2,l2,&b);
    }
    else{
        big = l2;
        small=l1;
        n1=l2;
        while(n1->next&&n2->next){
            n1=n1->next;n2=n2->next;
        }
        p = n1;
        out = subR(n1,l1,&b);
    }
    ListNode *head= new ListNode(big->val), *tail=head;
    big=big->next;
    while(big!=p){
        tail->next = new ListNode(big->val);
        tail=tail->next;
        big=big->next;
    }
    if(!b){
        tail->next = out;
        return head;
    }
    else{
        head=rev(head);
        ListNode *node=head;
        while(node->val==0){
            node->val=9;
            node=node->next;
        }
        node->val = node->val-1;
        head=rev(head);
        tail->next= out;
        return head;
    }
}
int binToDec(ListNode *head,int* i, int iter){
    if(!iter && !i)
        return -1;
    if(!iter){
        if(!head) return 0;
        int val =binToDec(head->next,i);
        val += head->val * pow(2,*i);
        *i=(*i)+1;
        return val;
    }
    else{
        stack<int> s;
        while(head){
            s.push(head->val); head=head->next;
        }
        int i=0,dec=0;
        while(!s.empty()){
            dec+=s.top()*pow(2,i++);
            s.pop();
        }
        return dec;
    }

}
ListNode* mR2a(ListNode *l1, ListNode *l2, ListNode **head){
    if(!l1 && !l2->next){
        *head = l2;
        return l2;}
    if(!l2 && !l1->next){
        *head = l1;
        return l1;}
    ListNode *p=nullptr;
    if((!l2&&l1)||(l1&&(l1->val<=l2->val))){
        ListNode *p = mR2a(l1->next,l2,head);
        p->next = l1;
        return l1;
    }
    else{
        ListNode *p = mR2a(l1,l2->next,head);
        p->next = l2;
        return l2;
    }
    return p;

}
ListNode* merge2a(ListNode *l1, ListNode *l2){
    if(!l1 && !l2)
        return nullptr;
    ListNode *head = nullptr;
    ListNode **a=&head;
    mR2a(l1,l2,a)->next=nullptr;
    return head;
}

