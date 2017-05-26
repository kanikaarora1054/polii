#include<iostream>
#include<math.h>
using namespace std;
int tree[10000];
void  buildTree(int start,int end_,int pos,int input[])
{
    if(start>end_)
        return;
    if(start==end_)
    {
    tree[pos]=input[start];
    return;
    }
       int  mid=(start+end_)/2;
        buildTree(start,mid,2*pos,input);
        buildTree(mid+1,end_,2*pos+1,input);
        tree[pos]=tree[2*pos]+tree[2*pos+1];
}
int query(int start,int end_,int l,int r,int pos)
{
    if(l>=start&&r<=end_)
        return tree[pos];
    else if(l<=start&&r>=end_)
         return 0;
    else
    {
       int mid=(start+end_)/2;
        int v1=query(start,mid, l,r, 2*pos+1);
        int v2=query(mid+1,end_,l,r,2*pos+2);
        return v1+v2;
    }


}
int main()
{
int n,l,r;
cout<<"enter size";
cin>>n;
int input[n+1];
for(int i=1;i<=n;i++)
{
    cin>>input[i];
    cout<<input[i];
}
buildTree(1,n,1,input);
for(int i=1;i<=pow(2,n);i++)
    cout<<tree[i]<<endl;
    cout<<"enter ranjge for query";
    cin>>l>>r;
    cout<<query(1,n, l,r, 1);

}
