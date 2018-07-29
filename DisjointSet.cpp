#include <iostream>
#include <map>
using namespace std;

class DisjointSet {
    
        class Node {
        public:
        long data;
        Node* parent;
        int rank;
    };


    map<long, DisjointSet::Node*> Map;


    /**
     * Create a set with only one element.
     */
    public:
    void makeSet(long data) {
        DisjointSet::Node *node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        Map.insert(std::make_pair(data, node));
    }

    /**
     * Combines two sets together to one.
     * Does union by rank
     *
     * @return true if data1 and data2 are in different set before union else false.
     */
    bool union_set(long data1, long data2) {
        map<long, DisjointSet::Node*>::const_iterator pos;
        Node *node1;
        Node *node2;
        if ((pos = Map.find(data1)) != Map.end())
            node1 = pos->second;
        if ((pos = Map.find(data2)) != Map.end())
            node2 = pos->second;

        Node *parent1 = findSet(node1);
        Node *parent2 = findSet(node2);

        //if they are part of same set do nothing
        if (parent1->data == parent2->data) {
            return false;
        }

        //else whoever's rank is higher becomes parent of other
        if (parent1->rank >= parent2->rank) {
            //increment rank only if both sets have same rank
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        } else {
            parent1->parent = parent2;
        }
        return true;
    }

    /**
     * Finds the representative of this set
     */
    long findSet(long data) {
        if (Map.find(data) != Map.end())
            return findSet(Map.find(data)->second)->data;
    }

    /**
     * Find the representative recursively and does path
     * compression as well.
     */
    private:
    static Node* findSet(Node* node) {
        Node* parent = node->parent;
        if (parent == node) {
            return parent;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }
};

int main(void) {
        DisjointSet ds;
        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.union_set(1, 2);
        ds.union_set(2, 3);
        ds.union_set(4, 5);
        ds.union_set(6, 7);
        ds.union_set(5, 6);
        ds.union_set(3, 7);

        cout<<"representative of 1"<<" ->"<<ds.findSet(1)<<endl;
        cout<<"representative of 2"<<" ->"<<ds.findSet(2)<<endl;
        cout<<"representative of 3"<<" ->"<<ds.findSet(3)<<endl;
        cout<<"representative of 4"<<" ->"<<ds.findSet(4)<<endl;
        cout<<"representative of 5"<<" ->"<<ds.findSet(5)<<endl;
        cout<<"representative of 6"<<" ->"<<ds.findSet(6)<<endl;
        cout<<"representative of 7"<<" ->"<<ds.findSet(7)<<endl;
    }
