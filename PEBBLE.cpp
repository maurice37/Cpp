#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int ans(string s){
	int len=s.size();
	char *a;
	a=new bool[len];
	char m;
	for(int i=0;i<len;i++){
		m=s[i];
		if(m=='1')a[i]=1;
		else if(m=='0') a[i]=0;
		else continue;
	}
	int count=0;
	for(int i=0;i<len;i++){
		if(count==0){
			if(a[i])count++;
		}
		else{
			if(count%2==1){
				if(!a[i])count++;
			}
			else if(count%2==0){
				if(a[i])count++;
			}
		}
	}
	//delete []a;
	return count;
}
int main(int argc, char const *argv[]){
	string s;
	int count=1;
	while(cin>>s){
		int answer=ans(s);
		printf("Game #%d: %d\n",count,answer);
		count++;
	}
	return 0;
}