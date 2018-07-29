#include <iostream>
#include <list>
#include <map>

using namespace std;
enum color_e {
    
    WHITE,
    GRAY,
    BLACK,
};
class graph {
    int vertices;
    list<int>*adjlist;
    public:
    void addEdge(int v, int u);
    bool isCyclic();
    bool DFS_Visit(int source, int *color);
    graph(int vertices);
};

graph::graph(int vertices) {
    this->vertices = vertices;
    adjlist = new list<int>[vertices];
}
void graph::addEdge(int v, int u) {
    adjlist[v].push_back(u);
}
bool graph::DFS_Visit(int source, int *color) {
    list<int>::iterator it;
    color[source] = GRAY;
    
    for(it = adjlist[source].begin(); it != adjlist[source].end(); it++) {
        if(color[*it] == GRAY)
            return true;
        if (color[*it] == WHITE )
            if(DFS_Visit(*it, color) == true)
                return true;
    }
    color[source] = BLACK;
    return false;

}
bool graph::isCyclic() {
    int color[vertices];
    for(int i =0; i<vertices; i++) {
        color[i] = WHITE;
    }
    
    for(int v =0; v<vertices; v++) {
        if(color[v] == WHITE) {
            if (DFS_Visit(v, color) == true)
                return true;
        }
    }
    return false;
    
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
 
    if (g.isCyclic())
        cout << "Graph contains cycle";
    return 0;

}
