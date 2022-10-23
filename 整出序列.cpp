#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n;

int main()
{
	cin>>n;
	while(n>0)
	{
		cout<<n<<" ";
		n=n>>1;
	}
	return 0;
}