// SOlution of Factorial Problem and to handle large numbers in C++
#include <iostream>
#include <stdio.h>
using namespace std;
void arr(int *a,int n,int& d){
	int k=0;
	while(n){
		a[k]=n%10;
		n/=10;
		k++;
	}
	d=k;
}
void print(int *a,int m){
	for(int i=m-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<'\n';
}
void fact(int* a,int& d,int n){
	int temp=0,x;
	for(int i=0;i<d;i++){
		x=a[i]*n+temp;
		a[i]=x%10;
		temp=x/10;
	}
	while(temp){
		a[d++]=temp%10;
		temp/=10;
	}
}
int main(int argc, char const *argv[])
{
	/* To test the random data;
	int a[200],d=0,x=0,temp=0;
	int n;
	cin>>n;
	arr(a,1,d);
	for(int i=2;i<=n;i++){
		fact(a,d,i);
	}
	print(a,d);
	
	*/

	//For solution part
	int t;
	scanf("%d",&t);

	while(t--){
		int n,d=0,temp=0;
		scanf("%d",&n);
		int *a=new int[200];
		arr(a,1,d);
		for(int i=2;i<=n;i++){
			fact(a,d,i);
		}
		print(a,d);
	}


	return 0;
}