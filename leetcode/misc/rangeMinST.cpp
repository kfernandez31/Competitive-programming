#include <bits/stdc++.h>
#define ll long long
#define llu long long unsigned
#define ld long double
#define fr(i,n) for(int i=0;i<n;i++)
#define watch(x) cout<<(#x)<<"=="<<(x)<<endl
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define P 1000000007llu
#define N 200005
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int arr[N], tree[4*N], n, q;

void buildST(int l, int r, int treeIndex) {
    if(l==r) {
        tree[treeIndex]=arr[l];
    } else {
        int m=(l+r)/2, lChild=(treeIndex<<1)+1, rChild=lChild+1;
        buildST(l,m,lChild);
        buildST(m+1,r,rChild);
        tree[treeIndex]=min(tree[lChild],tree[rChild]);
    }
}

int rangeQueryST(int a, int b, int treeIndex, int l ,int r) {
    if(b<l||r<a) return INT32_MAX;
    if(a<=l&&r<=b) return tree[treeIndex];
    int m=(l+r)/2, lChild=(treeIndex<<1)+1, rChild=lChild+1;
    return min(rangeQueryST(a,b,lChild,l,m),rangeQueryST(a,b,rChild,m+1,r));
}

void pointUpdateST(int i, int v, int treeIndex, int l, int r) {
    if(l==r) {
        if(l==i) tree[treeIndex]=v;
    } else {
        int m=(l+r)/2, lChild=(treeIndex<<1)+1, rChild=lChild+1;
        if(i>m) pointUpdateST(i,v,rChild,m+1,r);
        else pointUpdateST(i,v,lChild,l,m);
        tree[treeIndex]=min(tree[lChild],tree[rChild]);
    }
}

int main() {
    n=getchar_pos_int(), q=getchar_pos_int();
    fr(i,n) arr[i]=getchar_pos_int();
    buildST(0,n-1,0);
    fr(i,q) {
        bool isRangeQuery=getchar_pos_int()-1;
        int a=getchar_pos_int()-1, b=getchar_pos_int()-1;
        if(isRangeQuery) printf("%d\n",rangeQueryST(a,b,0,0,n-1));
        else pointUpdateST(a,b+1,0,0,n-1);
    }
    return 0;
}
