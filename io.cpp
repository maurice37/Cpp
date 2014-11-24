#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k,t,count=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t%k==0)count++;
	}
	printf("%d",count);
	return 0;
}
Time-0.65





#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k,t,count=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%k==0)count++;
	}
	cout<<count;
	return 0;
}
Time-2.65



#include <iostream>
#include <stdio.h>
using namespace std;
inline int getInt(){
	int c;
	int n=0;
	while((c=getchar_unlocked()) >='0' && c <= '9'){
		//n=10*n + (v- '0');
		n=(n<<3) + (n<<1) + c-'0';
	}
	return n;
}
int main(int argc, char const *argv[])
{
	int n,k,t,count=0;
	n=getInt();
	k=getInt();
	for(int i=0;i<n;i++){
		t=getInt();
		if(t%k==0)count++;
	}
	printf("%d",count);
	return 0;
}
Time-0.08!!!!