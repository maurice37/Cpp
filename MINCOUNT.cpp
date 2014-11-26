#include<stdio.h>
inline long long getInt(){
	char c;
	long long n=0;
	while((c=getchar_unlocked()) >= '0' && c <='9'){
		//n=10*n +(c - '0')
		n=(n<<3)+(n<<1)+c-'0';
	}
	return n;
}
int main(int argc, char const *argv[]){
	long long t;
	t=getInt();
	while(t--){
		long long n,d,ans;
		n=getInt();
		d=n/2;
		if(n==0||n==1)printf("0\n");
		else{
			d=(n-1)/3;
			ans=(d+1)*d/2*3;
			ans+=((n-1)%3)*(d+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
