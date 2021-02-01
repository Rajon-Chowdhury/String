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
}

}

int main()
{
    string s,str;
    cin>>s;
    Zfunc(s);
    int n=s.size(),ans=0,mx=0;
    map<int,int>cnt;
    for(int i=1; i<n; i++)
    {

       if(Z[i]+i>=n && mx>=(n-i))
       {
           ans=n-i;break;
       }
       mx=max(mx,Z[i]);
    }
    str=s.substr(0,ans);
    if(str.size()==0)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        cout<<str<<endl;
    }


}
