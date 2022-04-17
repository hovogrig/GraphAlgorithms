#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;


bool not_visited(int ind, vector<int>& visited) { 
    for (int i = 0; i < visited.size(); i++)  {
        if(visited[i]==ind) { 
            return false;
        }
    }
    return true;
}

int main() { 
    const int n = 7;
    const int INF = numeric_limits<int>::max();
    
    vector<vector<int>> AdjMatrix = {   {0, 1, 15, 10, INF, INF, INF},
                                        {1, 0, 5, 4, 4, 6, INF},
                                        {15, 5, 0, INF, INF, -1, INF},
                                        {10, 4, INF, 0, -4, INF, 11},
                                        {INF, 4, INF, -4, 0, 1, 2},
                                        {INF, 6, -1, INF, 1, 0, -7},
                                        {INF, INF, INF, 11, 2, -7, 0} };
    int source_vertex = 0;
    int cost = 0;               // Spanning tree cost
    pair<int,int> y;
    
    vector<int> visited;
    vector<int> alpha(n);
    vector<int> betta(n);
    vector<pair<int,int>> edges;        // Edges of spanning tree

    visited.push_back(source_vertex);

    int p = source_vertex;

    for (int i = 0; i < n; i++) {
        if (i != source_vertex) {
            int val = AdjMatrix[p][i]; 
            if(val != INF) { 
                alpha[i] = p;
                betta[i] = val;
            } else { 
                alpha[i] = -1;
                betta[i] = INF;
            }
        }
        
    }

    while(visited.size() != n) { 
        int min = INF;
        int w = -1; 
        for(int i = 0; i < n; ++i) { 
            if((betta[i] < min) && (not_visited(i, visited))) { 
                min = betta[i];
                w = i;
            }
        }
        
        y.first = w;            
        y.second = alpha[w];
        
        edges.push_back(y);             
        
        visited.push_back(w);
        cost += min;
        p = w;
        
        for (int i = 0; i < n; i++) {
            if((betta[i] > AdjMatrix[p][i]) && (not_visited(i, visited))) { 
                alpha[i] = p;
                betta[i] = AdjMatrix[p][i];
            }
        }
        
    }

    cout << "Edges Of Spanning Tree: ";
    for (int i = 0; i < edges.size(); i++) {
        cout << "(" << edges[i].first << ","<< edges[i].second << ")" << " "; 
    }
       
    cout << '\n';

    cout << "Cost: " << cost << '\n';
    return 0;
}