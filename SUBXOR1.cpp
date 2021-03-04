# C_N_Tries

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int lCount,rCount;
    Node *lChild,*rChild;
    
};
Node *CreateNode()
    {
    
    Node *pNode = NULL;
 
    pNode = (struct Node *)malloc(sizeof(Node));
 
    if (pNode)
    {
        pNode->lCount=pNode->rCount=0;
        pNode->lChild =pNode->rChild =NULL;
 
    }
 
    return pNode;
    }
void addBit(Node *root,int n)
{
    for(int i=20;i>=0;i--)
    {
        int x= (n>>i) & 1;
    
        if(x)
        {
            root->rCount++;
            if(root->rChild == NULL)
                root->rChild = CreateNode();
            root = root->rChild;
        }
        else
        {
            root->lCount++;
            if(root->lChild == NULL)
                root->lChild = CreateNode();
            root = root->lChild;
        }
    }
}
int query(Node *root,int n,int k)
{
    if(root == NULL)
        return 0;
    int res = 0;
    for(int i=20;i>=0;i--)
    {
        bool ch1=(k>>i) & 1;
        bool ch2=(n>>i) & 1;
        if(ch1)
        {
            if(ch2){
                res+=root->rCount;
                if(root->lChild == NULL)
                    return res;
                root = root->lChild;
            }
 
            else{
                res+=root->lCount;
                if(root->rChild == NULL)
                    return res;
                root = root->rChild;
            }
        }
        else
        {
            if(ch2){
                if(root->rChild == NULL)
                    return res;
                root= root->rChild;
            }
            else{
                if(root->lChild == NULL)
                    return res;
                root= root->lChild;
            }
        }
    }
    return res;
}
#define gc getchar_unlocked
 
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int t;
    //scanf("%d",&t);
    scanint(t);
    while(t--)
    {
        int n,k;
        //scanf("%d%d",&n,&k);
        scanint(n);
        scanint(k);
        int temp,temp1,temp2=0;
        Node *root = CreateNode();
        addBit(root,0);
        long long total =0;
        for(int i=0;i<n;i++)
        {
            //scanf("%d",&temp);
            scanint(temp);
            temp1= temp2^temp;
            total+=(long long)query(root,temp1,k);
            addBit(root , temp1);
            temp2 = temp1;
        }
        printf("%lld\n",total);
    }
    return 0;
}
