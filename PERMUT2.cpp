/*
#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,t;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		else{
			int *a=new int[n],*b=new int[n];
			bool flag=false;
			for(int i=1;i<=n;i++){
				scanf("%d",&t);
				b[i-1]=t;
				a[t-1]=i;
			}
			for(int i=0;i<n;i++){
				if(b[i]!=a[i]){
					i=n;
					flag=true;
				}
			}
			if(!flag){
				printf("ambiguous\n");
			}
			else printf("not ambiguous\n");
			delete [] a;
			delete [] b;
		}
	}
	return 0;
}
*/
//Faster one
#include <iostream>
#include <stdio.h>
using namespace std;
inline int getInt(){
	int c;
	int n=0;
	while((c=getchar_unlocked()) >= '0' && c<= '9' ){
		//n=10*n+(v-'0');
		n=(n<<3) + (n<<1) +c -'0';
	} 
	return n;
}
int main(int argc, char const *argv[])
{
	int n,t;
	while(1){
		n=getInt();
		if(n==0)break;
		else{
			int *a=new int[n],*b=new int[n];
			bool flag=false;
			for(int i=1;i<=n;i++){
				t=getInt();
				b[i-1]=t;
				a[t-1]=i;
			}
			for(int i=0;i<n;i++){
				if(b[i]!=a[i]){
					i=n;
					flag=true;
				}
			}
			if(!flag){
				printf("ambiguous\n");
			}
			else printf("not ambiguous\n");
			delete [] a;
			delete [] b;
		}
	}
	return 0;
}
