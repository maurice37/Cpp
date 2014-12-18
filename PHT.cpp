#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
inline long long getInt(){
	int c;
	long long n=0;
	while((c=getchar_unlocked()) >= '0' && c<='9'){
		n=(n<<3) + (n<<1) + c - '0';
	}
	return n;
}

void levelification(long long* a){
	for(int i=1;i<100;i++){
		a[i]=i*(i+2);
	}
}

int main(int argc, char const *argv[]){
	long long t;
	scanf("%lld",&t);
	for(long long i=0;i<t;i++){
		long long m;
		scanf("%lld",&m);
		int l=(sqrt(m+1))-1;
		printf("Case %lld: %d\n",i+1,l);
		
	}
	return 0;
}


/*
Still have to solve this problem using the getchar_unlocked method


*/