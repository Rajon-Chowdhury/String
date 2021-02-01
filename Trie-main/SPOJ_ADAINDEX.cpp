#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=2000005;
ll nxt[mx][27];
int sz=1;
ll ed[mx];
ll cnt[mx];

void trie_insert(string s){
     int n=s.size(),v=0;
     for(int i=0;i<n;i++){
        int id=s[i]-'a';
        if(nxt[v][id]==-1){
            nxt[v][id]=sz;
            sz++;
        }
        cnt[v]++;
        v=nxt[v][id];

     }
     cnt[v]++;
     ed[v]++;
}
ll search_trie(string s){
    int n=s.size(),v=0;
    ll res=0;
     for(int i=0;i<n;i++){
        int id=s[i]-'a';
        if(nxt[v][id]==-1){
            return 0;
        }
        v=nxt[v][id];
     }
     return cnt[v];
}
int main(){
    memset(nxt,-1,sizeof nxt);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        trie_insert(s);
    }
    while(q--){
        string s;
        cin>>s;
        ll ans=search_trie(s);
        cout<<ans<<endl;
    }
}
