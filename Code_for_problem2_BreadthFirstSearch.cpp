#include <iostream> 
#include <fstream>
#include <queue>
#include <stack>
using namespace std; 

int main()
{   
    ifstream inFile;

    inFile.open("C:\\Users\\Anish\\Desktop\\Networks\\Sample Network from Search Algorithm Slides.txt");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int nodecount;
    cout<<"Please enter the number of nodes:"<<endl;
    inFile>>nodecount;
    cout<<nodecount<<endl;

    int arccount;
    cout<<"Please enter the number of arcs:"<<endl;
    inFile>>arccount;
    cout<<arccount<<endl;
    
    int start_node[arccount];
    int end_node[arccount];
    int arc_cost[arccount];
    int arc_capacity[arccount];

    for(int i = 0; i<arccount; i++)
    {
        inFile>>start_node[i]>>end_node[i]>>arc_cost[i]>>arc_capacity[i];
    }
    
    int source;
    cout<<"Please enter the source node:"<<endl;
    cin>>source;

    int target;
    cout<<"Please enter the target node:"<<endl;
    cin>>target;

    queue<int> current;
    int node_parent[nodecount];
    int node_status[nodecount]; //Can be 0 for processed, 1 for current, 2 for unseen.

    //All nodes start as unseen.
    for(int i=0; i<nodecount; i++)
    node_status[i] = 2;

    int current_node;
    current.push(source);
    node_status[source] = 1; //Pushing source node to the current queue.

    while((!current.empty()) and (node_status[target]==2))
    {   
        current_node = current.front();
        current.pop();

        for(int i=0; i<arccount; i++)    
        if(start_node[i]==current_node and node_status[end_node[i]]==2)
        {
            current.push(end_node[i]);
            node_status[end_node[i]] = 1;
            node_parent[end_node[i]] = current_node;
        }

        node_status[current_node] = 0; //Processed.
    }

    stack<int> path;

    if(node_status[target]==2) cout<<"No Path Found from Node "<< source<<" To Node "<<target<<endl;
    else
    {   
        int temp = target;
        while(temp!=source)
        {
            path.push(temp);
            temp = node_parent[temp];
        }

        path.push(source);
        cout<<"A Path From Node "<<source<<" To Node "<<target<<" With Minimum Hops is:"<<endl;
        while(!path.empty())
        {
            cout<<path.top()<<" ";
            path.pop();
        }

    }
    return 0;
}