#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=2000020;
int nxt[mx][28];
int cnt[mx];
int sz=1;
void inser(string s){
    int v=0,n;
    n=s.size();
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

}
int func(string s){
   int v=0,n;
    n=s.size();
    for(int i=0;i<n;i++){
        int id=s[i]-'a';
        if(cnt[nxt[v][id]]==1){
            return i+1;
        }
        v=nxt[v][id];
    }
    return n;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        sz=1;
        memset(cnt,0,sizeof cnt);
        memset(nxt,-1,sizeof nxt);
        string s[n+5];
        for(int i=1;i<=n;i++){
            cin>>s[i-1];
            inser(s[i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
             ans+=func(s[i]);
        }
        cout<<ans<<endl;

    }
}
