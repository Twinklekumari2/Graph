#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Graph{
public:
     unordered_map<int, vector<int>> adjList;

     void addEdge(int u, int v, int dir){
        adjList[u].push_back(v);
        if(dir == 0){
            adjList[v].push_back(u);
        }
     }

     void adjcencyList(){
        for(auto i : adjList){
            cout << i.first << ": { ";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << "}" << endl;
        }
     }
};

class DepthFirstSearching : public Graph{
public:
    void solve(int src, unordered_map<int, bool>& visited){
        cout << src << " ";
        visited[src] = true;

        for(auto a : adjList[src]){
            if(!visited[a]){
                solve(a, visited);
            }
        }

    }
    void DFS(int n){
        cout << "Depth First Searching for node 0: ";
        stack<int> st;
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        st.push(0);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                solve(i, visited);
            }
        }
    }

};

int main(){
    DepthFirstSearching G;
    G.addEdge(0,1,0);
    G.addEdge(0,3,0);
    G.addEdge(3,1,0);
    G.addEdge(3,4,0);
    G.addEdge(4,1,0);
    G.addEdge(1,2,0);
    G.addEdge(4,2,0);

    G.adjcencyList();

    G.DFS(5);
    return 0;
}

