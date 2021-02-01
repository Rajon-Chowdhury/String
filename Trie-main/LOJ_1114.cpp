#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int mx = (int)1e5+10;
int nxt[mx][54];
int ed[mx];
int sz=1;
int indexx(char ch)
{
       if(isupper(ch)) return ch-'A';
       return ch-'a'+26;
}
void inser(string s)
{
    int v=0,n=s.size();
    for(int i=0; i<n; i++)
    {
        int id=indexx(s[i]);
        if(nxt[v][id]==0)
        {
            nxt[v][id]=sz++;
        }
        v=nxt[v][id];
    }
    ed[v]++;
}
ll func(string s)
{
    int v=0,n;
    n=s.size();
    for(int i=0; i<n; i++)
    {
        int id=indexx(s[i]);
        if(nxt[v][id]==0)
        {
            return 0LL;
        }
        v=nxt[v][id];
    }
    return ed[v];
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        sz=1;
        memset(nxt,0,sizeof nxt);
        memset(ed,0,sizeof ed);
        int n;
        scanf("%d",&n);
        getchar();
        for(int i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            if(s.size()>3)
                sort(s.begin()+1,s.end()-1);
            inser(s);
        }
        printf("Case %d:\n",cs++);
        int m;
        scanf("%d",&m);
        getchar();
        while(m--)
        {
            ll ans=1;
            string str;
            getline(cin, str);
            stringstream ss;
            ss<<str;
            while(ss>>str)
            {
                if(str.size()>3)
                sort(str.begin()+1,str.end()-1);
                ans*=func(str);

            }
            printf("%lld\n",ans);

        }
    }
}



