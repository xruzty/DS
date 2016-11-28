#include "trees.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

void inorder(TreeNode* root,int iter){
    stack<TreeNode*> s;
    TreeNode* p=root;
    while(!s.empty()||p){
        if(p){
            s.push(p);
            p=p->left;
        }
        else{
            p = s.top();
            s.pop();
            cout<<p->val<<" ";
            p=p->right;
        }
    }
}
void preorder(TreeNode* root,int iter){
    stack<TreeNode*> s;
    while(!s.empty()||root){
        if(root){
            cout<<root->val<< " ";
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
}
void postorder(TreeNode* root, int iter){
    if(iter){
        if(!root)
            return;
        stack<TreeNode*> s;
        TreeNode* pre=nullptr;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                if(!root->right||pre==root->right){
                    s.pop();
                    cout<<root->val<<" ";
                    pre = root;
                    root = nullptr;
                }
                else{
                    root = root->right;
                }
            }
        }
    }
}
bool isLeaf(TreeNode* r){
    if(!r)
        return true;
    return r->left==nullptr && r->right==nullptr;
}
void postorder(TreeNode* root){
    stack<TreeNode*> s;
    while(!s.empty()||root){
        while(!isLeaf(root)){                                   //  Push all non leaf left nodes into stack.
            s.push(root);
            root=root->left;
        }
        if(root)                                                //  Print the non null non leaf node
            cout<<root->val<<" ";
        while(!s.empty() && root==s.top()->right){              //  if root = s.top()->right, right subtree is over as well
            root=s.top();                                       //  pop and print from stack and recheck.
            s.pop();
            cout<<root->val<<" ";
        }
        if(s.empty())
            return;                                             //  Left subtree is done.
        else                                                    //  Move onto the right subtree
            root=s.top()->right;
    }
}
void DFS(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            root=q.front();
            q.pop();
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            cout<<root->val<<" ";
        }
    }
}
void commonNodesBST(TreeNode* r1, TreeNode* r2){
        stack<TreeNode*> s1, s2;
        while((r1||!s1.empty())&&(r2||!s2.empty())){
            if(r1){
                s1.push(r1);
                r1=r1->left;
            }
            if(r2){
                s2.push(r2);
                r2=r2->left;
            }
            if(!r1 && !r2){
                r1 = s1.top();
                r2 = s2.top();
                if(r1->val==r2->val){
                    cout<<r1->val<<" ";
                    s1.pop();
                    s2.pop();
                    r1=r1->right;
                    r2=r2->right;
                }
                else if(r1->val<r2->val){
                    s1.pop();
                    r1=r1->right;
                    r2=nullptr;
                }
                else{
                    s2.pop();
                    r2=r2->right;
                    r1=nullptr;
                }
            }
        }
}
void kthLevel(TreeNode* root, int k){
    if(!root)
        return;
    if(!k)
        cout<<root->val<<" ";
    else{
        kthLevel(root->left,k-1);
        kthLevel(root->right,k-1);
    }

}
int getLevelUtil(TreeNode* root, int data, int level ){
    if(!root)
        return 0;
    if(root->val==data)
        return level;
    int l=getLevelUtil(root->left,data,level+1);
    if(l)
        return l;
    return getLevelUtil(root->right,data,level+1);
}
void getLevel(TreeNode* root, int data){
    cout<<"Level is - "<<getLevelUtil(root,data,0)<<endl;
}
void printCousinsUtil(TreeNode* root, int data, int level){
    if(!root)
        return;
    if(level>1){
        printCousinsUtil(root->left,data,level-1);
        printCousinsUtil(root->right,data,level-1);
    }
    if(level==1){
        if((root->left)&&(root->right)&&(root->left->val==data || root->right->val==data))
            return;
        if(root->left)
            cout<<root->left->val<<" ";
        if(root->right)
            cout<<root->right->val<<" ";
    }
}
void printCousins(TreeNode* root, int data){
    int level = getLevelUtil(root,data,0);
    printCousinsUtil(root,data,level);

}
void printCousins2(TreeNode* root, int data){
    queue<TreeNode*>q;
    q.push(root);
    int level=-1;
    bool flag1=false,flag2=false;
    while(!q.empty()){
        level++;
        vector<int> out;
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                if(node->left->val==data){
                    flag1=true;
                    continue;
                }
            }
            if(node->right){
                if(node->right->val==data){
                    flag1=true;
                    continue;
                }
            }
            if(flag1){
                cout<<node->val<<" ";
                flag2=true;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(flag2)
            return;

    }

}
bool isSymmetric(TreeNode* r1, TreeNode* r2){
    if(!r1&&!r2)
        return true;
    if((!r1&&r2)||(r1&&!r2)||(r1->val!=r2->val))
        return false;
    return isSymmetric(r1->left,r2->right)&&isSymmetric(r2->left,r1->right);

}
bool isSymmetricIter(TreeNode* root){
    stack<TreeNode*> s1,s2;
    TreeNode *p1=root,*p2=root;
    int a=1,b=2;
    while((!s1.empty()&&!s2.empty())||(p1&&p2)){                        //preorder and reverse postorder should be same for symmetry
        if(p1){
            a=p1->val;
            s1.push(p1);
            p1=p1->left;
        }
        else{
            p1=s1.top();
            s1.pop();
            p1=p1->right;
        }
        if(p2){
            b=p2->val;
            s2.push(p2);
            p2=p2->right;
        }
        else{
            p2=s2.top();
            s2.pop();
            p2=p2->left;
        }
        if(a!=b)
            return false;

    }
    return true;
}
int maxDepth(TreeNode* root, int iter){
    if(iter){
        if(!root)
            return 0;
        stack<TreeNode*> s,path;
        unsigned int depth = 0;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            if(!path.empty()&&path.top()==root){
                if(path.size()>depth)
                    depth = path.size();
                s.pop();
                path.pop();
            }
            else{
                path.push(root);
                if(root->left)
                    s.push(root->left);
                if(root->right)
                    s.push(root->right);
            }
        }
        return depth;
    }
    else{
        if(!root)
            return 0;
        return max(maxDepth(root->left,0),maxDepth(root->right,0))+1;
    }
}
int minDepth(TreeNode* root, int iter){
    if(iter){
        if(!root)
            return 0;
        unsigned int depth = INT_MAX;
        stack<TreeNode*> s,path;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            if(!path.empty()&&path.top()==root){
                if(!root->left&&!root->right){
                    if(path.size()<depth)
                        depth = path.size();
                }
                s.pop();
                path.pop();
            }
            else{
                path.push(root);
                if(root->left)
                    s.push(root->left);
                if(root->right)
                    s.push(root->right);
            }
        }
        return depth;
    }
    else{
        if(!root)
            return 0;
        if(!root->left)
            return minDepth(root->right)+1;
        if(!root->right)
            return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
}
int kthSmallest(TreeNode* root, int k){
    stack<TreeNode*> s;
    while(!s.empty()||root){
        if(root){
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            k--;
            if(!k)
                return root->val;
            root=root->right;
        }
    }
    return -1;
}
int searchUtil(vector<int>& A,int key, int l, int r){
    int i=l;
    while(A[i]!=key && i<=r)
        i++;
    return i;
}
TreeNode* createFrom2(vector<int>& post, vector<int>& pre){
    return nullptr;
}
TreeNode* createFromUtil(vector<int>& pre, vector<int>& in, int* i, int l, int r){
    if(l>r)
        return nullptr;
    TreeNode* root = new TreeNode(pre[*i]);
    *i = *i + 1;
    int j = searchUtil(in, root->val, l, r);
    root->left = createFromUtil(pre,in,i,l,j-1);
    root->right = createFromUtil(pre,in,i,j+1,r);
    return root;
}
TreeNode* createFrom(vector<int>& pre, vector<int>& in){
    int n=in.size();
    int index=0;
    int *i = &index;
    return createFromUtil(pre,in,i,0,n-1);

}
string serialize(TreeNode* root) {
    string s;
    s += "[";
    if(root){
        int h = maxDepth(root,0),l=0;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            l++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();q.pop();
                if(node){
                    if(l!=h)
                        q.push(node->left);
                    if(l!=h)
                        q.push(node->right);
                    stringstream ss;
                    ss << node->val;
                    s += ss.str() + ",";
                }
                else{
                    s += "n,";
                }
            }
        }
        s = s.substr(0,s.size()-1);
    }

    while(s[s.size()-1]=='n'){
        s = s.substr(0,s.size()-2);
    }
    s += "]";
    return s;
}
TreeNode* getVal(string& s){
    int n=s.size(),i=0;
    if(!n)
        return nullptr;
    while(i<n && s[i]!=',')
        i++;
    if(s[0]=='n'){
        s = s.substr(2,n-2);
        return nullptr;
    }
    else{
        int low=0;
        if(s[0]=='-')
            low=1;
        int val=0, d=0;
        for(int j=i-1;j>=low;j--){
            val+= (int(s[j])-48)*pow(10,d++);
        }
        if(i==n)
            s = "";
        else{

            s = s.substr(i+1);
        }
        if(low)
            val*=-1;
        return new TreeNode(val);
    }
}
TreeNode* deserialize(string s){
    int n=s.size();
    if(!(n-2))
        return nullptr;
    s = s.substr(1,n-2);
    queue<TreeNode*> q;
    TreeNode* root = getVal(s), *node=nullptr;
    q.push(root);
    while(s.size()){
        node = q.front(); q.pop();
        if(node){
            node->left = getVal(s);
            if(node->left)
                q.push(node->left);
            node->right = getVal(s);
            if(node->right)
                q.push(node->right);
        }
    }
    return root;
}
