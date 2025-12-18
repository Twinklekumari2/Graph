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

class Topological : public Graph{
public: 
    unordered_map<int, int> indegree;
    vector<int> TopologicalOrder;
    void indegreeCalc(){
        for(auto i : adjList){
            indegree[i.first] = 0;
        }
        for(auto i : adjList){
            for(auto j : i.second){
                indegree[j]++;
            }
        }
    }

    void topologicalOrder(){
        queue<int> q;
        for(auto i : indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TopologicalOrder.push_back(front);

            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        } 
    }

    void printTopologicalOrder(){
        for(auto i : TopologicalOrder){
            cout << i << ", ";
        }
        cout << endl;
    }

};

class CycleDetection : public Topological{
public:
    void cycleDetection(){
        int actualNodes = adjList.size();
        int nodesPresentInTopologicalOrder = TopologicalOrder.size();

        if(actualNodes == nodesPresentInTopologicalOrder){
            cout << "Cycle is Not Present in the Graph" << endl;
        }else{
            cout << "Cycle is Present in the Graph" << endl;
        }
    }

};

int main(){
    CycleDetection G;
    G.addEdge(0,1,1);
    G.addEdge(0,3,1);
    G.addEdge(3,1,1);
    G.addEdge(3,4,1);
    G.addEdge(4,1,1);
    G.addEdge(1,2,1);
    G.addEdge(4,2,1);
    G.adjcencyList();
    G.indegreeCalc();

    G.topologicalOrder();
    cout << "Topological Order is: ";
    G.printTopologicalOrder();
    cout << "About cycle present: " << endl;
    G.cycleDetection();
    return 0;
}

