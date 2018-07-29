#include <iostream>
#include <list>
#include <map>
#include <stack>
using namespace std;
class graph {
    int vertices;
    list<int>*adjlist;
    public:
    void addEdge(int v, int u);
    void topSort();
    void topSortUtil(int source, int *visited, stack<int>&st);
    graph(int vertices);
};

graph::graph(int vertices) {
    this->vertices = vertices;
    adjlist = new list<int>[vertices];
}
void graph::addEdge(int v, int u) {
    adjlist[v].push_back(u);
}
void graph::topSortUtil(int source, int *visited, stack<int>&st) {
    list<int>::iterator it;
    
    for(it = adjlist[source].begin(); it != adjlist[source].end(); it++) {
        if(!visited[*it]) {
            visited[*it] = 1;
            topSortUtil(*it, visited, st);
        }
        
    }
    st.push(source);

}
void graph::topSort() {
    int visited[vertices];
    stack<int>Stack;
    for(int i =0; i<vertices; i++) {
        visited[i] = 0;
    }
    
    for(int i =0; i<vertices; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            topSortUtil(i, visited,Stack);
            
        }
    }
        // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    
}
int main() {
    graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
 
    cout << "Topological sorting"<<endl;
    g.topSort();
 
    return 0;

}
