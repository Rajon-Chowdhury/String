#include<bits/stdc++.h>
using namespace std;


const int MaxN=100009;

int nxt[MaxN][10];
int ed[MaxN];

int sz=1;
int flag=1;
void inser(string s)
{
    int v=0;

    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        if(!nxt[v][c])
        {
            nxt[v][c]=sz++;
        }
        else if(nxt[v][c] and i==s.size()-1)
         flag=0;
        v=nxt[v][c];
        if(ed[v])
            flag=0;
    }

   ed[v]=1;

}

int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n+5];
        sz=1;
        flag=1;
        memset(nxt,0,sizeof nxt);
        memset(ed,0,sizeof ed);
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            inser(s[i]);
        }
        if(flag==0)
        {
            printf("Case %d: NO\n",++cs);
        }
        else
        {
            printf("Case %d: YES\n",++cs);
        }
    }
}
