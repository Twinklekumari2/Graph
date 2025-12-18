#include<iostream>
#include<vector>
#include<queue>
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

class Cycledetection : public Graph{
public: 
    void cycleDetection(){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        q.push(0);
        visited[0] = true;
        parent[0] = -1;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            for(auto a : adjList[front]){
                if(visited[a] && parent[a] != front){
                    cout << "Cycle Detected" << endl;
                    break;
                }
                if(!visited[a]){
                    q.push(a);
                    visited[a] = true;
                    parent[a] = front;
                }
            }
        }

    }

};
int main(){
    Cycledetection G;
    G.addEdge(0,1,0);
    G.addEdge(0,3,0);
    G.addEdge(3,1,0);
    G.addEdge(3,4,0);
    G.addEdge(4,1,0);
    G.addEdge(1,2,0);
    G.addEdge(4,2,0);

    G.adjcencyList();
    G.cycleDetection();
    return 0;
}

