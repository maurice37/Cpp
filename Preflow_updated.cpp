// C++ program to implement push-relabel algorithm for
// getting maximum flow of graph
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Edge
{
	// To store current flow and capacity of edge
	int flow, capacity;

	// An edge u--->v has start vertex as u and end
	// vertex as v.
	int u, v;

	Edge(int flow, int capacity, int u, int v)
	{
		this->flow = flow;
		this->capacity = capacity;
		this->u = u;
		this->v = v;
	}
};

// Represent a Vertex
struct Vertex
{
	int h, e_flow;

	Vertex(int h, int e_flow)
	{
		this->h = h;
		this->e_flow = e_flow;
	}
};

// To represent a flow network
class Graph
{
	int V; // No. of vertices
	vector<Vertex> ver;
	vector<Edge> edge;

	// Function to push excess flow from u
	bool push(int u);

	// Function to relabel a vertex u
	void relabel(int u);

	// This function is called to initialize
	// preflow
	void preflow(int s);

	// Function to reverse edge
	void updateReverseEdgeFlow(int i, int flow);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// returns maximum flow from s to t
	int getMaxFlow(int s, int t);
	void printflow(int **graph, int **graph_old, string nodes[]);
};

Graph::Graph(int V)
{
	this->V = V;

	// all vertices are initialized with 0 height
	// and 0 excess flow
	for (int i = 0; i < V; i++)
		ver.push_back(Vertex(0, 0));
}

void Graph::addEdge(int u, int v, int capacity)
{
	// flow is initialized with 0 for all edge
	edge.push_back(Edge(0, capacity, u, v));
}

void Graph::preflow(int s)
{
	// Making h of source Vertex equal to no. of vertices
	// Height of other vertices is 0.
	ver[s].h = ver.size();

	//
	for (int i = 0; i < edge.size(); i++)
	{
		// If current edge goes from source
		if (edge[i].u == s)
		{
			// Flow is equal to capacity
			edge[i].flow = edge[i].capacity;

			// Initialize excess flow for adjacent v
			ver[edge[i].v].e_flow += edge[i].flow;

			// Add an edge from v to s in residual graph with
			// capacity equal to 0
			edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
		}
	}
}

void Graph::printflow(int **graph, int **graph_old, string nodes[])
{
	for(int i = 0; i < edge.size(); i++)
        {
            graph[edge[i].u][edge[i].v] = edge[i].flow;
        }

    cout<<"Flows:"<<endl;
    cout<<"     ";
    for(int i=0;i<V;i++)
    {
        cout<<nodes[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<V;i++)
        {
            cout<<nodes[i]<<":   ";
            for(int j=0;j<V;j++)
            {
                int flow = graph[i][j]*(graph[i][j]>0);
                cout << flow << " ";
            }
            cout<<endl;
        }
}

// returns index of overflowing Vertex
int overFlowVertex(vector<Vertex>& ver, int s, int t)
{
	for (int i = 0; i < ver.size(); i++)
	if (ver[i].e_flow > 0 && i!=s && i!=t)
			return i;

	// -1 if no overflowing Vertex
	return -1;
}

// Update reverse flow for flow added on ith Edge
void Graph::updateReverseEdgeFlow(int i, int flow)
{
	int u = edge[i].v, v = edge[i].u;

	for (int j = 0; j < edge.size(); j++)
	{
		if (edge[j].v == v && edge[j].u == u)
		{
			edge[j].flow -= flow;
			return;
		}
	}

	// adding reverse Edge in residual graph
	Edge e = Edge(0, flow, u, v);
	edge.push_back(e);
}

// To push flow from overflowing vertex u
bool Graph::push(int u)
{
	// Traverse through all edges to find an adjacent (of u)
	// to which flow can be pushed
	for (int i = 0; i < edge.size(); i++)
	{
		// Checks u of current edge is same as given
		// overflowing vertex
		if (edge[i].u == u)
		{
			// if flow is equal to capacity then no push
			// is possible
			if (edge[i].flow == edge[i].capacity)
				continue;

			// Push is only possible if height of adjacent
			// is smaller than height of overflowing vertex
			if (ver[u].h > ver[edge[i].v].h)
			{
				// Flow to be pushed is equal to minimum of
				// remaining flow on edge and excess flow.
				int flow = min(edge[i].capacity - edge[i].flow,
							ver[u].e_flow);

				// Reduce excess flow for overflowing vertex
				ver[u].e_flow -= flow;

				// Increase excess flow for adjacent
				ver[edge[i].v].e_flow += flow;

				// Add residual flow (With capacity 0 and negative
				// flow)
				edge[i].flow += flow;

				updateReverseEdgeFlow(i, flow);

				return true;
			}
		}
	}
	return false;
}

// function to relabel vertex u
void Graph::relabel(int u)
{
	// Initialize minimum height of an adjacent
	int mh = INT_MAX;

	// Find the adjacent with minimum height
	for (int i = 0; i < edge.size(); i++)
	{
		if (edge[i].u == u)
		{
			// if flow is equal to capacity then no
			// relabeling
			if (edge[i].flow == edge[i].capacity)
				continue;

			// Update minimum height
			if (ver[edge[i].v].h < mh)
			{
				mh = ver[edge[i].v].h;

				// updating height of u
				ver[u].h = mh + 1;
			}
		}
	}
}

// main function for printing maximum flow of graph
int Graph::getMaxFlow(int s, int t)
{
	preflow(s);

	// loop untill none of the Vertex is in overflow
	while (overFlowVertex(ver,s,t) != -1)
	{
		int u = overFlowVertex(ver,s,t);
		if(!push(u))
		{
		    relabel(u);
        }
	}

	// ver.back() returns last Vertex, whose
	// e_flow will be final maximum flow
	return ver[t].e_flow;
}

// Driver program to test above functions
int main()
{

	ifstream input_file;
	string filename;
	int V;
	int a;
	int i,j,k,c;


	//Driver program begin//
	//Add the helper code to this one and run to check the flow


	cout<<"Enter input file name:"<<endl;
	cin>>filename;

	input_file.open(filename);

	input_file>>V>>a;

    string nodes[V];
    int dummy;

    for(int i=0;i<V;i++)
    {
        input_file >> dummy >> nodes[i];  //list of node names in order
    }

	Graph g(V);
	// Creating above shown flow network

	int **graph = new int*[V];
	int **graph_old = new int*[V];
    for(int i=0;i<V;i++)
    {
       graph[i] = new int[V];
       graph_old[i] = new int[V];
    }
    for(int i=0;i<V;i++)
    {
       for(int j=0;j<V;j++)
        {
            graph[i][j] = 0;
            graph_old[i][j] = 0;
        }
    }

	while(a--){
		input_file>>i>>j>>c>>k;

//		cout<<i<<" "<<j<<" "<<c<<" "<<k<<endl;
		g.addEdge(i,j,k);
		graph_old[i][j] = k;
	}

	string start_node_char, end_node_char;
	int s,t;

	while(1)
        {
            cout << "Input start node: ";
            cin >> start_node_char;
            cout << "Input end node: ";
            cin >> end_node_char;

            bool found_start=0, found_end=0;
            for(int i=0;i<V;i++)
            {
                if(start_node_char==nodes[i])
                {
                    s = i;  //find the position of the start_node in the modified node list
                    found_start = 1;
                }
                if(end_node_char==nodes[i])
                {
                    t = i;  //find the position of the end_node in the modified node list
                    found_end = 1;
                }
            }
            if(found_end==0 || found_start==0)
            {
                cout << "Atleast one of the nodes is not found" << endl;
            }
            else
            {
                break;
            }
        }


	cout << "Maximum flow is " << g.getMaxFlow(s,t) << endl;


    g.printflow(graph,graph_old,nodes);


	return 0;
}
