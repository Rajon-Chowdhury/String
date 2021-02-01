#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=1e6+9;
string s;
ll n,hs[2][mxn],pw[2][mxn],mod[2]={1000000005,1000000007};
void func(){
    for(ll id=0;id<2;id++){
        pw[id][0]=1;
        for(ll i=1;i<=n;i++){
            pw[id][i]=(pw[id][i-1]*10)%mod[id];
        }
    }
    for(ll id=0;id<2;id++){
        for(ll i=1;i<=n;i++){
            hs[id][i]=((hs[id][i-1]*10)%mod[id]+s[i-1]-'0')%mod[id];
        }
    }
}
void check(ll a,ll b,ll c){

    if(a<=0 || b<=0 || c<=0) return;
    if(max(a,b)>c) return;
    if(s[a]=='0'&&b>1 || s[a+b]=='0'&&c>1) return;
    ll id,A,B,C;
    for(id=0;id<2;id++){
        A=hs[id][a]%mod[id];
        B=(mod[id]+hs[id][a+b]-(hs[id][a]*pw[id][b])%mod[id])%mod[id];
        C=(mod[id]+hs[id][a+b+c]-(hs[id][a+b]*pw[id][c])%mod[id])%mod[id];
        if((A+B)%mod[id]!=C%mod[id]) return;
    }
  //  cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i];
        if(i==a-1) cout<<'+';
        if(i==a+b-1) cout<<'=';
    }
    cout<<endl;
    exit(0);
}
int main(){
     cin>>s;
     ll a,b,c;
     n=s.size();
     func();
     for(ll c=1;c<=n;c++){

        ///case1
        a=c,b=n-a-c;
        check(a,b,c);

       ///case2
        a=c-1,b=n-a-c;
        check(a,b,c);

       ///case3
        b=c,a=n-b-c;
        check(a,b,c);

       ///case4
        b=c-1,a=n-b-c;
        check(a,b,c);


     }
}
