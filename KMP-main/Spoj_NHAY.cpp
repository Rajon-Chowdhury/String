#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false)


vector<int>create_lps(string pattern){
    vector<int>lps(pattern.size());
    int index=0;

    for(int i=1;i<pattern.size();){
        if(pattern[i]==pattern[index]){
            lps[i]=index+1;
            i++,index++;
        }
        else{
            if(index!=0) index=lps[index-1];
            else lps[i]=index,i++;
        }
    }
    return lps;
}
void kmp(string pat,string text){
     int i=0,j=0,f=0;
     vector<int>lps=create_lps(pat);
     while(i<text.size()){
        if(text[i]==pat[j]){
            i++,j++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
        if(j==pat.size()){
            cout<<(i-pat.size())<<endl;
            j=lps[j-1];
        }
     }
}
int main(){

     int n;
     while(cin>>n){
        string pattern,text;
        cin>>pattern>>text;
        kmp(pattern,text);

     }
}
