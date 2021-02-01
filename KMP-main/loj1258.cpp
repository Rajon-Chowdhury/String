

#include<bits/stdc++.h>
using namespace std;


#define SIZE 1000005

using namespace std;

int m, n;

char s[SIZE];
char str[SIZE];
int b[SIZE];


void kmpPreprocess(char *substr, int *n)
{
	int i = 0, j = -1;
	b[i] = j;

	while(i < m)
	{
		while(j >= 0 && substr[i] != substr[j])
			j = b[j];
		i++, j++;
		b[i] = j;
	}
}

int kmpSearch(char *str, char *substr, int *b)
{
	int i = 0, j = 0;

	while(i < n)
	{
		while(j >= 0 && str[i] != substr[j])
			j = b[j];
		i++, j++;
	}
	return j;
}

int main()
{


	int i, j, k, sum = 0;
	int tc, t, d, x, y;
	unsigned char ch;
	int mx;

	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{
		cin>>s;
		n = m = strlen(s);
		reverse_copy(s, s + n, str);
		kmpPreprocess(str, b);

		int match = kmpSearch(s, str, b);
		printf("Case %d: %d\n", t, 2*n - match);
	}

	return 0;
}
