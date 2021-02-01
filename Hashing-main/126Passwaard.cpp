#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int p=31;
const int m=1e9+9;
long long h[1000005];
long long pw[1000005];

long long findd(int i,int l)
{
    long long cur_h = (h[i + l] + m - h[i]) % m;
    cur_h = (cur_h * pw[n-i-1]) % m;
    return cur_h;
}

long long func(int len)
{
    if(len*3<n) return false;
    int first=findd(0,len);
    int  lst= findd(n-len,len);
    if(first!=lst) return false;

    for(int i=len+1; i<n-len; i++)
    {
        long long tmp=findd(i,len);
        if(tmp==lst)
        {
            return true;
        }
    }
    return false;
}
void solve(string const& s)
{
    n=s.size();

    pw[0]=1;
    for(int i=1; i<n; i++)
    {
        pw[i]=(pw[i-1]*p)%m;
    }

    for(int i=0; i<n; i++)
    {
        h[i+1]=(h[i]+(s[i]-'a'+1)*pw[i])%m;
    }
    int lo=0,hi=n,ans=-1;

    while(lo<=hi)
    {
        int m=(lo+hi)/2;
        if(func(m)&&m>0)
        {
            lo=m+1;
            ans=m;
        }
        else
        {
            hi=m-1;
        }
    }
    if(ans==-1) cout<<"Just a legend"<<endl;
    else{
        string sb;
        sb=s.substr(0,ans);
    }

}
int main()
{

    int t=1;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
}
