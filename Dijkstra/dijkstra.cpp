#include <iostream>
#include <limits>
#include <vector>


using namespace std;


bool not_visited(int ind, vector<int>& visited) { 
    for (int i = 0; i < visited.size(); i++)  {
        if(visited[i]==ind) { 
            return false;
        }
    }
    return true;
}


int main(){
    const int n = 6;        // Number of vertexes

    const int INF = numeric_limits<int>::max();

    int AdjMatrix[n][n] = { {0, 2, 1, INF, INF, INF},
                            {INF, 0, 1, 3, INF, 8},
                            {INF, INF, 0, 5, 4, INF},
                            {INF, 5, INF, 0, 1, 7},
                            {INF, INF, 1, INF, 0, 1},
                            {INF, INF, INF, INF, INF, 0} };


    vector<int> l_v(n);
    vector<int> Prev(n);
    vector<int> visited;       // Visited vertexes

    int source_vertex = 0;

    visited.push_back(source_vertex);
    l_v[source_vertex] = 0;
    Prev[source_vertex] = -1;


    for(int i = 0; i < n; ++i){ 
        if(i != source_vertex) { 
            l_v[i] = INF;
        }
    }
    
    int p = source_vertex;
    while ((n-visited.size()) != 0 ) { 
        bool changed = false;
        for(int j = 0; j < n; ++j) { 
            if((AdjMatrix[p][j] != INF) && (p != j)){
                changed = true;
                int temp = l_v[p] + AdjMatrix[p][j];
                if(temp < l_v[j]) { 
                    l_v[j] = temp;
                    Prev[j] = p;
                }
            }                 
        }

        if(!changed){ break; }
        int min = INF;
        int index{};
        for (int i = 0; i < n; i++) {
            if((l_v[i] < min) && not_visited(i,visited)) { 
                min = l_v[i];
                index = i;
            }
        }
        p = index;
        visited.push_back(p);
    }


    // Beautiful Printing
    for (int i = 0; i < n; ++i) {
        if ( i != source_vertex) {            
            if (l_v[i] == INF) { 
                cout << source_vertex <<" -> " << i  << " Length: INF    Path: Not exist" << '\n'; 
            } else { 
                    cout << source_vertex <<" -> " << i  << " Length: "<< l_v[i] << "      Path: ";
                    int j = i;
                    vector<int> path;
                    path.push_back(j);
                    while (Prev[j] != -1) {
                        j = Prev[j];
                        path.push_back(j);
                    }
                    for (int k = 0; k < path.size(); ++k) {
                        cout << path[path.size()-1-k] << " ";
                    }
                    cout<<'\n';
            }
        }
    }
    return 0;
}