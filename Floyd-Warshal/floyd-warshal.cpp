#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() { 
    const int vertexCount = 4;

    const int INF = numeric_limits<int>::max();

    vector<vector<int>> Graph ={{0, INF, -2, INF},
                                {4, 0, 3, INF},
                                {INF, INF, 0, 2},
                                {INF, -1, INF, 0}};


    vector<vector<int>> Distances;
    
    Distances = Graph;

    for (int k = 0; k < vertexCount; k++) {
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                if (Distances[i][k] != INF && Distances[k][j] != INF && i != k) {
                    int u = Distances[i][j];
                    int v = Distances[i][k] + Distances[k][j];  
                    if (u > v) {
                        Distances[i][j] = v;
                    }
                }
            }
        }   
    }
    
    for (int i = 0; i < vertexCount; i++){
        for (int j = 0; j < vertexCount; j++){
            if (i != j) {
                cout<<"From Vertex "<<i<<" To Vertex " <<j<<" Distance: "<<Distances[i][j]<<'\n';
            }
        }
    }

    return 0;
}