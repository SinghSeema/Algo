#include <iostream>
#include <list>
#include <map>

using namespace std;
class graph {
    int vertices;
    list<int>*adjlist;
    public:
    void addEdge(int v, int u);
    void DFS();
    void DFS_Visit(int source, int *visited);
    graph(int vertices);
};

graph::graph(int vertices) {
    this->vertices = vertices;
    adjlist = new list<int>[vertices];
}
void graph::addEdge(int v, int u) {
    adjlist[v].push_back(u);
}
void graph::DFS_Visit(int source, int *visited) {
    list<int>::iterator it;
    cout<<source<<" ";
    for(it = adjlist[source].begin(); it != adjlist[source].end(); it++) {
        if(!visited[*it]) {
            visited[*it] = 1;
            DFS_Visit(*it, visited);
            
        }
    }

}
void graph::DFS() {
    int visited[vertices];
    for(int i =0; i<vertices; i++) {
        visited[i] = 0;
    }
    
    for(int i =0; i<vertices; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            DFS_Visit(i, visited);
            
        }
    }
    
}
int main() {
    // Create a graph 
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"<<endl;
    g.DFS();
 
    return 0;

}
