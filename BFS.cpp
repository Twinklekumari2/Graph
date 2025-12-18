#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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

class BreadthFirstSearch : public Graph{
public:

    void BFS(){
        cout << "Breadth First Searching For Node 0: " ;
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(0); //starting node
        visited[0] = true;
   
        while(!q.empty()){
           auto front = q.front();
           q.pop();

           cout << front << " ";
           for(auto a : adjList[front]){
              if(!visited[a]){
                  q.push(a);
                  visited[a] = true;
            }
           }
        }
    }
};

int main(){
    BreadthFirstSearch G;
    G.addEdge(0,1,0);
    G.addEdge(0,3,0);
    G.addEdge(3,1,0);
    G.addEdge(3,4,0);
    G.addEdge(4,1,0);
    G.addEdge(1,2,0);
    G.addEdge(4,2,0);

    G.adjcencyList();
    G.BFS();


    return 0;
}

