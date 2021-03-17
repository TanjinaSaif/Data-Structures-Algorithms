#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    vector<int> *weight;
    vector<int> not_visited;
    int *distance;
    int *parent;

    Graph(int V);
    void addEdge(int v1, int v2, int w);
    int dijkstra(int src);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    //update weight size
    weight = new vector<int>[V];
    //add all vertex in not_visited
    for( int i = 0; i<V ; i++)
    {
        not_visited.push_back(i);
    }

    //define size of distance and parent
    distance = new int[V];
    parent = new int[V];
    //initialize these arrays
    for( int i = 0; i<V ; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
}
void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    //update weight[v1]
    weight[v1].push_back(w);
}

//implement dijkstra(int src)
int Graph:: dijkstra(int src)
{
    while(!not_visited.empty())
    {
        int min1 = INT_MAX, index = -1;
        for(int i = 0; i<not_visited.size(); i++)
        {
            if(min1>distance[not_visited.at(i)])
            {
                min1 = distance[not_visited.at(i)]; //Find min distance
                index = i; //index of node of min distance
            }

        }
        int Unvisited_node = not_visited.at(index);

        for(int i =index; i< not_visited.size()-1; i++)
        {
            not_visited[i] = not_visited[i+1]; //Swapping items to pop back min

        }
        not_visited.pop_back();

        for(int i = 0; i<adj[Unvisited_node].size(); i++) //Checking Child Nodes
        {
            int v = adj[Unvisited_node].at(i); //Child node
            distance[v] = distance[Unvisited_node]+ weight[Unvisited_node].at(i); //updating distance of child
            parent[v] = Unvisited_node; //Where it came from
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1,5);
    g.addEdge(0, 2,3);
    g.addEdge(2, 1,1);
    g.addEdge(1, 3, 2);

    int v = 3;
    int src = 0;
    g.distance[src] = 0;
    //call dijkstra to test shortest path
    g.dijkstra(src);
    cout<<"Shortest distance:"<<g.distance[v]<<endl;
    while (v!=-1)
    {
        cout<<v<<"<--"<<" ";
        v = g.parent[v];
    }
    return 0;
}
