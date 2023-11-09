#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    private:
         int n; // Number of vertices
         list<int> * adj; // Adj list

    public:
        Graph(int n);
        void loadGraph(int V, int W);
        void DSF(int s); // Search key
        void BFS(int s);  
};

Graph::Graph(int n){
    this->n = n;
    adj = new list<int>[n];
}

void Graph::loadGraph(int n, int m){
    adj[n].push_back(m);
}

void Graph::DSF(int s){
    bool *visited = new bool[n];

    for(int i = 0 ; i < n; i++){
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

void Graph::BFS(int s){
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    queue<int> queue;
    queue.push(s);

    while (!queue.empty()){
        s = queue.front();
        queue.pop();

        if(!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }

        for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                queue.push(*i);
            }
        }
    }

}

int main() {
    Graph g(5);
    g.loadGraph(0, 1);
    g.loadGraph(0, 2);
    g.loadGraph(1, 0);
    g.loadGraph(2, 0);
    g.loadGraph(1, 2);
    g.loadGraph(2, 1);
    g.DSF(0);
    cout << endl;
    g.BFS(0);
}