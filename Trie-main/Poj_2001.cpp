#include <iostream>
#include<cstring>
#include<string>
using namespace std;

const int mx=20500;
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
void func(string s){
   int v=0,n;
    n=s.size();
    for(int i=0;i<n;i++){
        int id=s[i]-'a';
        cout<<s[i];
        if(cnt[nxt[v][id]]==1){
            break;
        }
        v=nxt[v][id];
    }
}
int main()
{
        sz=1;
        memset(cnt,0,sizeof cnt);
        memset(nxt,-1,sizeof nxt);
        int n=0;
         string str[10005],s;
         while(getline(cin, s)){
            if(s.size()==0) break;
            inser(s);
            str[n]=s;
            n++;
         }

        int ans=0;
        for(int i=0;i<n;i++){
              cout<<str[i]<<" ";
              func(str[i]);
              cout<<endl;
        }


}

