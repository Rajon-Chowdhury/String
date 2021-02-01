#include<bits/stdc++.h>
using namespace std;
#define ll long long
int in[1010000][2];
ll ha[1010000];
ll pw[1010000];


int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    ll ans=0;
     pw[0]=1;
    const int p=29;

    for(i=1;i<=n;i++){
        pw[i]=pw[i-1]*p;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        in[i][0]=a;in[i][1]=b;
        ha[a]+=pw[b];
        ha[b]+=pw[a];
    }
    for(i=0;i<m;i++){
        int a=in[i][0],b=in[i][1];
        if(ha[a]+pw[a]==ha[b]+pw[b])ans++;
    }

    sort(ha,ha+n);
    for(i=0;i<n;i=j){
        for(j=i;j<n&&ha[i]==ha[j];j++);
        ans+=((long long)j-i)*((long long)j-i-1)/2;
    }
    printf("%I64d\n",ans);
}
