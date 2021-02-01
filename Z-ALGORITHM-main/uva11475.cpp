#include<bits/stdc++.h>
using namespace std;

int Z[2000010];
void Zfunc(string str){
int n = str.length();
int L, R, k;

L = R = 0;
for (int i = 1; i < n; ++i)
{
    if (i > R)
    {
        L = R = i;
        while (R<n && str[R-L] == str[R])
            R++;
        Z[i] = R-L;
        R--;
    }
    else
    {

        k = i-L;

        if (Z[k] < R-i+1)
            Z[i] = Z[k];


        else
        {
            L = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
    }
   // cout<<Z[i]<<" ";
}
}
int main()
{
    string s;
    while(cin >> s){
        int j;
        string rev,str,ans,t;
        t=s;
        reverse(t.begin(),t.end());
        str=t+'#'+s;
        Zfunc(str);
        int k=s.size()+1,mx=0;
        int n=str.size();
        for(int i=k;i<n;i++)
        {
            if(Z[i]>mx){
              mx=Z[i];
               j=i-k;

            }
        }
        ans=s.substr(0,j);
        reverse(ans.begin(),ans.end());
        ans=s+ans;
        cout<<ans<<endl;
        memset(Z,0,sizeof(Z));
    }
}
