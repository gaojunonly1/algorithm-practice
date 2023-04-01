#include<bits/stdc++.h>
using namespace std;
char s[10][10];
int main()
{
	for(int i=1;i<=8;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
			if(s[i][j]=='*')
			{
				printf("%c%d",j+'a'-1,8-i+1);
				return 0;
			}
	}
}
