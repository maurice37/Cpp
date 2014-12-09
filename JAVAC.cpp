// Code about JAVAC
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
void translate(string n){
	char m,c;
	int cpp=0,java=0,total=1;
	total=cpp+java;
	for(int i=0; i<n.length();i++){
		m=n[i];
		if(int(m)<=90 && int(m)>= 65 && i==0){
			cpp=1;java=1;
			i=n.length()-1;
		}
		else if(int(m)==95 && i==0){
			cpp=1;java=1; //Error
			i=n.length()-1;
		}
		else if(int(m)==95 && i==n.length()-1){
			cpp=1;java=1; //Error
		}
		else if(int(m)==95){
			cpp=1; //implies this given string is c++
			if(i!=n.length()){
				m=n[i+1];
				if(int(m)==95){
					java=1;cpp=1;
					i=n.length()-1;
				}
			}
		}
		else if(int(m)<=90 && int(m)>= 65){
			java=1;		//implies this given string is java
		}
		total=cpp+java;
	}
	if(total==0){
		cout<<n<<'\n'; 	//valid for both of them
	}
	else if(cpp==1 && java==0){
				//string is cpp so convert it to JAVA
		for(int i=0;i<n.length();i++){
			c=n[i];
			if(int(c)==95){
				if(i==n.length()-1)continue;
				else {
					c=n[++i];
					int z=int(c);
					z-=32;
					cout<<char(z);
				}
			}
			else{
				cout<<c;
			}
		}
		cout<<"\n";
	}
	else if(cpp==1 && java==1){
		cout<<"Error!\n";
	}
	else{
		//convert java to cpp
		for(int i=0;i<n.length();i++){
			c=n[i];
			if(int(c)<=90 && int(c)>= 65){
				cout<<'_';
				int as=int(c);
				as+=32;
				cout<<char(as);
			}
			else cout<<c;
		}
		cout<<'\n';
	}
}
int main(int argc, char const *argv[])
{	
	char a[101];
	while(scanf("%s",a)!=EOF){
		translate(a);
	}
	return 0;
}



/*
	Summary
	-> Very easy problem with MATHABHARE test cases
	keep the boundary cases in mind and you will get AC
	very easily
	
	Patel Maurice M
	7:24PM 12/09/2014


*/