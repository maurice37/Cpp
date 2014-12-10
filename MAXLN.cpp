#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	long long r;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%lld",&r);
		printf("Case %d: %lld.25\n",i+1,4*r*r);
	}
	return 0;
}