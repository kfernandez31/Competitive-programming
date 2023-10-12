#include<bits/stdc++.h>
#define turbo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

using namespace std;

const int MAX = 1<<20;
ll tr[2*MAX];
ll updated[2*MAX];

void lazy(int v, int lo, int hi, int mid) {
    if(updated[v] != -1) {
        updated[2*v] = updated[v];
        updated[2*v+1] = updated[v];
        tr[2*v] = (mid-lo) * updated[v];
        tr[2*v+1] = (hi-mid) * updated[v];
        updated[v] = -1;
    }
}

void update(int l, int r, int v, int lo, int hi, int val) {
    if(l == lo && r==hi) {
        updated[v] = val;
        tr[v] = (hi-lo) * updated[v];
        return;
    }
    if(r<=l) return;
    int mid = (lo+hi)/2;
    lazy(v, lo, hi, mid);
    update(l, min(r, mid), 2*v, lo, mid, val);
    update(max(l, mid), r, 2*v+1, mid, hi, val);
    tr[v] = tr[2*v] + tr[2*v+1];

}

ll query(int l, int r, int v, int lo, int hi) {
    if(l == lo && r == hi) return tr[v];
    if(r<=l) return 0;
    int mid = (lo+hi)/2;
    lazy(v, lo, hi, mid);
    ll L = query(l, min(r, mid), 2*v, lo, mid);
    ll R = query(max(l, mid), r, 2*v+1, mid, hi);
    return L+R;
}

void build() {
    for(int i=MAX-1; i>0; i--) {
        updated[i] = -1;
        tr[i] = tr[2*i] + tr[2*i+1];
    }
    for(int i=MAX; i<2*MAX; i++) {
        updated[i] = -1;
    }
}

int main() {
    turbo;
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++) {
        int a; cin>>a;
        tr[a+MAX]++;
    }
    build();
    while(q-->0) {
        int l, p, d;
        cin>>l>>p>>d;
        ll ile = query(l, p+1, 1, 0, MAX);
        ll ileWPkt = query(d, d+1, 1, 0, MAX);
        update(l, p+1, 1, 0, MAX, 0);
        cout<<ile-ileWPkt<<'\n';
        
        update(d, d+1, 1, 0, MAX, ile);
    }
}

