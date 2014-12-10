#include <iostream>
using namespace std;
void n(int n){
	while(n>1){
		if(n%2==0){
			n/=2;
			cout<<"Maurice\n";
		}
		else{
			n=3*n+3;
			cout<<"Nishu\n";
		}
	}
}
int main(int argc, char const *argv[])
{	
	unsigned long long x=1,count=0,arr[60];
	for(int i=0;i<60;i++){
		arr[i]=x*2;
		x*=2;
	}
	unsigned long long z,t=1;
	cin>>z;
	for(int i=0;i<60;i++){
		if(arr[i]==z){count++;}
		
	}
	if(count==1||z==1)cout<<"TAK";
	else cout<<"NIE";
	/*if((z != 0) && !(z & (z - 1))) cout<<"TAK\n";
	else cout<<"NIE\n";*/
	/*for(int i=1;i<z;i++){
		t*=2;
		cout<<t<<endl;
	}*/
	return 0;
}
