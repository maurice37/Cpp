#include <iostream>
#include <stdio.h>
using namespace std;
int fill(int t,int d){
	int a=0;
	if(t==d)return a;
	else{
		if(t%d==0){
			a=(t/d)-1;
		}
		else{
			a=t/d;
		}
		return a;
	}
}
void ans(int sum,int m){
	if(sum>=m)printf("YES\n");
	else printf("NO\n");
}
int main(int argc, char const *argv[]){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,d,temp,sum=0;
		scanf("%d %d %d",&n,&m,&d);
		int *h=new int[n];
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			sum+=fill(temp,d);
		}
		ans(sum,m);
	}

	return 0;
}