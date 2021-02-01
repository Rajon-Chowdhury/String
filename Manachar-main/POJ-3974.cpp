#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;
const int maxn = 2000010;

string convert(string s) {
    string res;
    res += '@';
    for(int i = 0; i < s.size(); ++i) {
        res += '#';
        res += s[i];
    }
    res += '#';
    res += '$';
    return res;
}

int len[maxn];

int Manacher(string s) {
    memset(len, 0, sizeof(len));
    int mx = 0, id = 0;
    int ans = 0;
    for(int i = 1; i < s.size() - 1; ++i) {
        if(mx > i) {
            len[i] = min(mx - i, len[2 * id - i]);
        } else {
            len[i] = 1;
        }
        while(s[i - len[i]] == s[i + len[i]]) {
            ++len[i];
        }
        if(i + len[i] > mx) {
            mx = i + len[i];
            id = i;
        }
        ans = max(ans, len[i]);
    }
    return ans - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int cs = 0;
    while (cin >> s) {
        if(s == "END") break;
        string tmp = convert(s);
        cout << "Case " << (++cs) << ": ";
        cout << Manacher(tmp) << endl;
    }
    return 0;
}
