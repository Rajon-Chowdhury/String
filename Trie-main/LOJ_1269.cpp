#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
bool check(ll N,int pos){return (bool)(N & (1<<pos));}
const int mx=50005*34;
ll sz=1;
ll nxt[mx][3];
ll pw[40];
void insert_trie(ll msk){
      int v=0;
      for(int i=31;i>=0;i--){
         int id=check(msk,i);
         if(nxt[v][id]==-1){
            nxt[v][id]=sz;
            sz++;
         }
         v=nxt[v][id];
      }
}
ll query_mx(ll msk){
    ll res=0;
    int v=0;
    for(int i=31;i>=0;i--){
        int id=check(msk,i);
        if(nxt[v][id^1]!=-1){
            res+=pw[i];
            v=nxt[v][id^1];
        }
        else
            v=nxt[v][id];
    }
    return res;
}
ll query_mn(ll msk){
      ll res=0;
      int v=0;
      for(int i=31;i>=0;i--){
        int id=check(msk,i);
        if(nxt[v][id]!=-1){
           v=nxt[v][id];
        }
        else{
            res+=pw[i];
            v=nxt[v][id^1];
        }
      }
      return res;
}
int main(){
     pw[0]=1;
     for(int i=1;i<=35;i++){
        pw[i]=pw[i-1]*2;
     }
     int t,cs=1;
     scanf("%d",&t);
     while(t--){
        sz=1;
        memset(nxt,-1,sizeof nxt);
        insert_trie(0);
        int n;
        scanf("%d",&n);
        ll xr=0;
        ll maxi=-inf;
        ll mini=inf;
        for(int i=1;i<=n;i++){
            ll x;
            scanf("%lld",&x);
            xr^=x;
            maxi=max(maxi,query_mx(xr));
            mini=min(mini,query_mn(xr));
            insert_trie(xr);
        }
        printf("Case %d: %lld %lld\n",cs++,maxi,mini);
     }
}
