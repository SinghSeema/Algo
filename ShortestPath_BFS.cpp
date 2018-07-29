#include <iostream>
#include <list>
#include <map>
using namespace std;

class graph {
    int vertices;
    list<int> *adjlist;
    map<int, int> path;
    
    public:
    graph(int V) {
        this->vertices = V;
        adjlist = new list<int>[V];
        for(int i = 0; i<V; i++) {
            path[i] = 0;
        }
    }
    void addEdge(int u, int v) {
        adjlist[u].push_back(v);
    }
    void BFS(int source);
    void shortestpathforvertex(int vertex);
};
void graph::shortestpathforvertex(int vertex) {
    map<int, int>::const_iterator pos;
    int key = vertex;
    pos = path.find(key);
    cout<<endl<<"shortest path to reach "<<vertex<<" is"<<endl;
    while(pos != path.end() && pos->second != -1) {
        cout<<pos->second<<" ";
        key = pos->second;
        pos = path.find(key);
        
    }
}
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
    int i = 0;
    path[source] = -1;
    
    while(!q.empty()) {
        source= q.front();
        cout<< source << " ";
        q.pop_front();
        for(it = adjlist[source].begin(); it!= adjlist[source].end() ; it++) {
            if(!visited[*it]) {
                visited[*it] = i+1;
                path[*it] = source;
                q.push_back(*it);
            }
        }
        i++;
    }
    
    
    
    
}

int main() {
	cout<<"Start of BFS "<<endl;
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    g.shortestpathforvertex(3);
    g.shortestpathforvertex(1);
	return 0;
}
