#include <iostream>
#include <list>
#include <map>
using namespace std;

class graph {
    int vertices;
    list<int> *adjlist;

    public:
    graph(int V) {
        this->vertices = V;
        adjlist = new list<int>[V];
    }
    void addEdge(int u, int v) {
        adjlist[u].push_back(v);
    }
    void BFS(int source);
};

void graph::BFS(int source)
{
    int visited[this->vertices];
   
    for(int i =0; i<this->vertices; i++) {
        visited[i] = 0;
    }
    list<int>q ;
    visited[source] = 1;
    q.push_back(source);
    list<int>::iterator it;

    while(!q.empty()) {
        source= q.front();
        cout<< source << " ";
        q.pop_front();
        for(it = adjlist[source].begin(); it!= adjlist[source].end() ; it++) {
            if(!visited[*it]) {
                visited[*it] = 1;
                q.push_back(*it);
            }
        }
    }
    
}

int main() {
	cout<<"[BFS Traversal started with source 2]"<<endl;
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);

	return 0;
}
