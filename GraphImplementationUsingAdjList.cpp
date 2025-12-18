#include<iostream>
#include<vector>
#include<unordered_map>
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

int main(){
    Graph G;
    G.addEdge(0,1,0);
    G.addEdge(0,3,0);
    G.addEdge(3,1,0);
    G.addEdge(3,4,0);
    G.addEdge(4,1,0);
    G.addEdge(1,2,0);
    G.addEdge(4,2,0);

    G.adjcencyList();
    return 0;
}

