#include<iostream>
#include <list>
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Graph {
   int V;
   list<int> *adj;
   void findNewPath(int , int , bool [], int [], int &);
   public:
   Graph(int V);
   void addEdge(int u, int v);
   void printPaths(int s, int d);
};
Graph::Graph(int V) {
   this->V = V;
   adj = new list<int>[V];
}
void Graph::addEdge(int u, int v) {
   adj[u].push_back(v);
}
void Graph::printPaths(int s, int d) {
   bool *visited = new bool[V];
   int *path = new int[V];
   int path_index = 0;
   for (int i = 0; i < V; i++)
   visited[i] = false;
   findNewPath(s, d, visited, path, path_index);
}
void Graph::findNewPath(int u, int d, bool visited[],
int path[], int &path_index) {
   visited[u] = true;
   path[path_index] = u;
   path_index++;
   if (u == d) {
      for (int i = 0; i<path_index; i++)
      cout<<path[i]<<" ";
      cout << endl;
   } else {
      list<int>::iterator i;
      for (i = adj[u].begin(); i != adj[u].end(); ++i)
         if (!visited[*i])
            findNewPath(*i, d, visited, path, path_index);
   }
   path_index--;
   visited[u] = false;
}
int main() {
	ifstream input_file;
	string filename;
	int v;
	int a;
	int i,j,k,c;


	//Driver program begin//
	//Add the helper code to this one and run to check the flow


	cout<<"Enter input file name:"<<endl;
	cin>>filename;

	input_file.open(filename);

	
	Graph g(15);
	int t=30;
	while(t--){
		input_file>>i>>j>>c>>k;
		g.addEdge(i, j);
	}


   
   //g.addEdge(0, 1);
   //g.addEdge(0, 2);
   // g.addEdge(0, 3);
   // g.addEdge(2, 0);
   // g.addEdge(2, 1);
   // g.addEdge(1, 3);
   int s = 2, d = 3;
   cout<<"Enter source\n";
   cin>>s;
   cout<<"\nEnter destination\n";
   cin>>d;
   cout<<"Following are all different paths from source to destination : \n";
   g.printPaths(s, d);
   return 0;
}