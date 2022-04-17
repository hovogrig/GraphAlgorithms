#include <iostream>
#include <vector>

using namespace std;


/*
    0 - White
    1 - Gray
    2 - Black
*/

const int vertexCnt = 12; 

vector<vector<int>>graph = {{1, 8, 5},
                            {0, 2},
                            {1, 3, 5},
                            {2, 4},
                            {3},    
                            {0, 2, 6},
                            {5, 7, 8},
                            {6},
                            {0, 6}, 
                            {10, 11},
                            {9}, 
                            {9} };    


vector<int> Colors(vertexCnt);
vector<int> FindingTime(vertexCnt);
vector<int> FinishedTime(vertexCnt);
vector<int> Pred(vertexCnt, -1);
int Timer = 0;

void Visit(int u) {
    Colors[u] = 1; 
    FindingTime[u] = ++Timer;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(Colors[v] == 0) { 
            Pred[v] = u;
            Visit(v);    
        } 
    }
    Colors[u] = 2;
    FinishedTime[u] = ++Timer;
}


int main(){ 
    int ComponentsCount = 0;
    for (int i = 0; i < vertexCnt; ++i) {
        if(Colors[i] == 0){ 
            ++ComponentsCount;
            Visit(i);    
        }
    }
    
    cout << "Components Count: " << ComponentsCount << '\n';

    for (int i = 0; i < vertexCnt; i++) {
        cout << "Vertex " << i << "    Finding Time: " << FindingTime[i] << "  Finishing time: " <<  FinishedTime[i] << '\n';
    }

    for (int i = 0; i < vertexCnt; i++) {
        cout << "Pred " << i << ": " << Pred[i] << '\n';
    }
       
    return 0;
}