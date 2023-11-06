#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    private:
         int V; // Number of vertices
         list<int> * adj; // Adj list

    public:
        Graph(int V);
        void addEdge(int V, int W);
        void DSF(int s); // Search key
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int V, int W){
    adj[V].push_back(W);
}

void Graph::DSF(int s){
    bool *visited = new bool[V];

    for(int i = 0 ; i < V; i++){
        visited[i] = false;
    }

    stack<int> stack;
    stack.push(s);

    while (!stack.empty()){
        s = stack.top();
        stack.pop();

        if(!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }

        for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                stack.push(*i);
            }
        }

    }

}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.DSF(0);
}