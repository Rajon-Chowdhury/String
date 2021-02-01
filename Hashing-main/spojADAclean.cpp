#include<bits/stdc++.h>
using namespace std;
#define ll long long


int countsubstrings(string const& s,int n,int k) {


    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> pw(n);
    pw[0] = 1;
    for (int i = 1; i < n; i++)
        pw[i] = (pw[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * pw[i]) % m;


    int cnt = 0;

        set<long long> hs;
        for (int i = 0; i <=n-k; i++) {
            long long cur = (h[i+k] + m - h[i]) % m;
            cur = (cur * pw[n-i-1]) % m;
            hs.insert(cur);
        }
        cnt += hs.size();
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        string s;
        cin>>s;
        int ans= countsubstrings(s,n,k);
        printf("%d\n",ans);

    }
}
