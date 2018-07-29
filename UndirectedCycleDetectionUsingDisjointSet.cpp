#include <iostream>
#include <list>
#include <map>
using namespace std;

class graph {
    int vertices;
    int edges;
    
    public:
    class edge {
        public:
        int src;
        int dest;
    };
    
    class Node {
        public:
        int vertex;
        Node* parent;
        int rank;
    };
    
    map<int, Node*>m_set;
    edge *edge_list;
    public:
    graph(int vertices, int edges);
    void makeSet(int vertex);
    void addEdge(int u, int v, int index);
    bool union_set(int v1, int v2);
    int findSet(int vertex);
    Node * find_set(Node* node);
    bool hasCycleUsingDisjointSet();
};

void graph::makeSet(int vertex) {

    Node *node = new Node();
    node->rank = 0;
    node->vertex = vertex;
    node->parent = node;
    m_set.insert(std::make_pair(vertex, node));
}

bool graph::union_set(int v1, int v2) {
    Node * node1;
    Node * node2;
    if (m_set.find(v1) != m_set.end())
        node1 = m_set.find(v1)->second;
    
    if (m_set.find(v2) != m_set.end())
        node2 = m_set.find(v2)->second;
    Node *parent1 = find_set(node1);
    Node *parent2 = find_set(node2);
    
    if (parent1->vertex == parent2->vertex)
        return false; //they are in the same set do noting
    else {
        if (parent1->rank >= parent2->rank) {
            parent1->rank = parent1->rank == parent2->rank?(parent1->rank)+1:parent1->rank;
            parent2->parent = parent1;
        }
        else 
            parent1->parent = parent2;
        
    }
    return true;
    
}

int graph::findSet(int vertex) {
    if (m_set.find(vertex) != m_set.end())
        return find_set((m_set.find(vertex)->second))->vertex;
}
graph::Node * graph::find_set(Node* node) {
    
    Node* parent = node->parent;
    if (node == parent)
        return parent;
    node->parent = find_set(node->parent);
    return node->parent;
}

graph::graph(int vertices, int edges)
{

    this->vertices = vertices;
    edge_list = new edge[edges];
    this->edges = edges;

    for (int i= 0; i<vertices; i++) {
        makeSet(i);
    }

}
void graph::addEdge(int u, int v, int index) {

    edge_list[index].src = u;
    edge_list[index].dest =v;

}
bool graph::hasCycleUsingDisjointSet() {
    
    // get edges and for each vertex in an edge run

    for (int i =0; i<edges; i++) {
        int parent1 = findSet(edge_list[i].src);
        int parent2 = findSet(edge_list[i].dest);
        if (parent1 == parent2)
            return true;
        union_set(edge_list[i].src, edge_list[i].dest);
    }
    return false;
    
}


int main()
{
    cout<<"started"<<endl;
    int index = 0;
    
    graph g1(5, 5);

    g1.addEdge(1, 0, index);
    g1.addEdge(0, 2, index+1);
    g1.addEdge(2, 0, index+2);
    g1.addEdge(0, 3, index+3);
    g1.addEdge(3, 4, index+4);
    g1.hasCycleUsingDisjointSet()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    graph g2(3,2);
    index = 0;
    g2.addEdge(0, 1, index);
    g2.addEdge(1, 2, index+1);
    g2.hasCycleUsingDisjointSet()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
                   
    
    graph g3(3,3);
    index = 0;
    g3.addEdge(0,1,index);
    // add edge 1-2
    g3.addEdge(1,2, index+1);
    // add edge 0-2
    g3.addEdge(0,2,index+2);
    g3.hasCycleUsingDisjointSet()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
