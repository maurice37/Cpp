#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(int argc, char const *argv[]){
	int t;
	scanf("%d",&t);
	while(t--){
		int s1=0,s2=0,min;
		static char *a,*b;
		a=new char[3000];
		b=new char[3000];
		int a1[26]={0},b1[26]={0},sum1=0,sum2=0,count=0,temp=0;
		scanf("%s %s",a,b);
		string foo1=a,foo2=b;
		s1=foo1.length();
		s2=foo2.length();
		min=s1;
		if(s1>s2)min=s2;
		for(int i=0;i<min;i++){
			if(a[i]!=b[i])count++;
		}
		if(min==s1){
			temp=s2-min;
			count+=temp;
		}
		else{
			temp=s1-min;
			count+=temp;
		}
		/*for(int i=0;i<s1;i++){
			temp=int(a[i])-65;
			a1[temp]++;
		}
		for(int i=0;i<s2;i++){
			temp=int(b[i])-65;
			b1[temp]++;
		}
		for(int i=0;i<26;i++){
			min=a1[i];
			if(a1[i]>b1[i])min=b1[i];
			b1[i]-=min;
			a1[i]-=min;
		}
		for(int i=0;i<26;i++){
			sum1+=a1[i];
			sum2+=b1[i];
		}
		if(sum2<sum1)printf("%d\n",sum1);
		else printf("%d\n",sum2);
		*/
		printf("%d\n",count);
		delete [] a;
		delete [] b;
	}
	return 0;
}
