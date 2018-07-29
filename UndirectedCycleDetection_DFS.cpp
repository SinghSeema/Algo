#include <iostream>
#include <list>
using namespace std;

class graph {
    int vertices;
    list<int>*adjlist;
    
    public:
    graph(int vertices);
    void addEdge(int v, int u);
    bool hasCycle();
    bool hasCycleUtil(int vertex, int *visited, int parent);
};
graph::graph(int V)
{
    vertices = V;
    adjlist = new list<int>[V];
}
// push for both direction as graph is undirected
void graph::addEdge(int v, int u)
{
    adjlist[v].push_back(u);
    adjlist[u].push_back(v);
}
bool graph::hasCycleUtil(int vertex, int* visited, int parent)
{
    visited[vertex] = 1;
    list<int>::iterator it;
    for(it = adjlist[vertex].begin(); it != adjlist[vertex].end(); it++) {
        if (*it == parent)
            continue;
        else if (visited[*it])
                return true;
        else if (hasCycleUtil(*it, visited, vertex))
                return true;
    }
    return false;

}
bool graph:: hasCycle()
{
    int visited[vertices];
    for(int i =0; i<vertices; i++)
        visited[i] = 0;
    for(int i =0; i<vertices; i++)
        if (!visited[i])
            if(hasCycleUtil(i, visited, -1))
                return true;
    return false;
            
}
// Driver program to test above functions
int main()
{
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.hasCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.hasCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
