#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,e,v1,v2,answer,assign=0,no=1;
	scanf("%d",&t);
	while(t--){
		answer=1;
		assign=0;
		scanf("%d %d",&n,&e);
		int *value=new int[n];
		int **a=new int*[n];
		for(int i=0;i<n;++i){
			a[i]=new int[n];
			value[i]=0;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				a[i][j]=0;
			}
		}
		for(int i=0;i<e;++i){
			scanf("%d %d",&v1,&v2);
			v1--;v2--;
			if(v1<v2){
				a[v1][v2]++;
			}
			else{
				a[v2][v1]++;
			}
		}
		/*for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<a[x][y]<<"\t";
			}
			cout<<endl;
		}
		*/
		for(int i=0;i<n;++i){
			if(value[i]==0){
				value[i]=1;
				assign=2;
			}
			else if(value[i]==1){
				assign=2;
			}
			else if(value[i]==2){
				assign=1;
			}
			for(int j=i;j<n;j++){
				if(a[i][j]==1){
					if(value[j]==0||value[j]==assign){
						value[j]=assign;
					}
					else{
						answer=0;
						break;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			delete[] a[i];
		}
		delete[] a;
		printf("Scenario #%d:\n",no);
		if(answer==0)printf("Suspicious bugs found!\n");
		else if(answer==1) printf("No suspicious bugs found!\n");
		else printf("Error!\n");
		no++;
	}
	return 0;
}
