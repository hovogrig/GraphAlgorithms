#include <iostream> 
#include <vector> 
#include <queue>

using namespace std;


/*
    0 - White
    1 - Gray
    2 - Black
*/


int main(){ 
    const int n = 8;  // Number of vertexes

    vector<vector<int>> graph = {   {1,3},
                                    {2,0},
                                    {1,3,5},  
                                    {0,2,4},                        // Adjacency List Representation of Graph
                                    {3,5},
                                    {2,4,6},
                                    {5,7},
                                    {6} };


    vector<int> Distances(n);
    vector<int> Pred(n);
    vector<int> Colors(n);
    queue<int> queue;
    int StartingVertex  = 0;

    Colors[StartingVertex] = 1;
    Distances[StartingVertex] = 0;
    Pred[StartingVertex] = -1;

    for (int i = 0; i < n; i++) {
        if(i != StartingVertex) { 
            Colors[i] = 0;
        }
    }
    
    queue.push(StartingVertex);

    while(!queue.empty()) { 
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            if (Colors[graph[u][i]] == 0) {
                Colors[graph[u][i]] = 1;
                queue.push(graph[u][i]);
                Distances[graph[u][i]] = Distances[u] + 1;
                Pred[graph[u][i]] = u;
            }   
        }
        Colors[u] = 2;       
    }

    for (int i = 0; i < n; ++i){
        if (i != StartingVertex) { 
            cout << StartingVertex << " -> " << i << " Distance: "<< Distances[i] << "    "; 
            cout << "Pred: " << Pred[i] << '\n';
        } 
    }

    return 0;
}