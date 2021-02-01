#include<bits/stdc++.h>

using namespace std;


void kmp(const string &pat, const string &txt)
{
    int m = pat.size();
    vector<int> border(m + 1);
    border[0] = -1;
    for (int i = 0; i < m; ++i)
    {
        border[i+1] = border[i];
        while (border[i+1] > -1 and pat[border[i+1]] != pat[i])
        {
            border[i+1] = border[border[i+1]];
        }
        border[i+1]++;
    }

    int n = txt.size();
    int vis = 0;
    for (int i = 0; i < n; ++i)
    {
        while (vis > -1 and pat[vis] != txt[i])
        {
            vis = border[vis];
        }
        if (++vis == m)
        {
            printf("%d\n", i - m + 1);
            vis = border[m];
        }
    }
}

int main()
{
    int m;
    bool first = true;
    while (scanf("%d",&m)==1)
    {
        if (!first) puts("");
        first = false;

        string pat;
        getline(cin, pat);
        getline(cin, pat);
        string txt;
        getline(cin, txt);
        kmp(pat, txt);
    }
    return 0;
}
