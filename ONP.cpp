//ONP on SPOJ
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
void onp(string n){
	char m;
	int z=0;
	char* st=new char[500];
	int count=0;
	for(int i=0;i<n.length();i++){
		m=n[i];
		if(m=='(')continue;
		else if(int(m)>=95 && int(m)<=122){
			cout<<m;
		}
		else if(m==')'){
			cout<<st[--count];
		}
		else /*if(int(m)>=42 && int(m)<=47)*/{
			st[count]=m;
			count++;
			z++;
		}
		
	}
	//cout<<endl<<z<<endl;
	/*for(int i=0;i<10;i++){
		cout<<st[i]<<'\n';
	}
	cout<<'\n';*/
}
int main(int argc, char const *argv[]){
	int t;
	char a[500];
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		onp(a);
		cout<<'\n';
	}

	return 0;
}