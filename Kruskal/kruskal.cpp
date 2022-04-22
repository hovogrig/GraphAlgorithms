#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() { 
    const int vertexCNT = 10;
    const int edgesCNT = 6;


    // first is weight, second is pair of vertex (edge)
    pair<int, pair<int, int>> graph[edgesCNT];

    /* vector<vector<PAIR> > graph = {
                                {PAIR(1, 1), PAIR(3, -4)},
                                {PAIR(0, 1), PAIR(3, 3), PAIR(2, -1), PAIR(4, 2)},
                                {PAIR(1, -1)},
                                {PAIR(0, -4), PAIR(1, 3), PAIR(6, 5)},
                                {PAIR(1, 2), PAIR(5, 1), PAIR(6, 5), PAIR(7,7)},
                                {PAIR(4, 1), PAIR(9, 3)},
                                {PAIR(3, 5), PAIR(4, 5), PAIR(7, -7)},
                                {PAIR(4, 7), PAIR(6, -7), PAIR(8, 1)},
                                {PAIR(7, 1), PAIR(9, 2)},
                                {PAIR(5, 3), PAIR(8, 2)} };
    */ 

    graph[0].first = 1;
    graph[0].second = make_pair(0, 1);
    graph[1].first = 3;
    graph[1].second = make_pair(0, 2);
    graph[2].first = -1;
    graph[2].second = make_pair(1, 3);
    graph[3].first = -1;
    graph[3].second = make_pair(1, 4);
    graph[4].first = 1;
    graph[4].second = make_pair(3, 4);
    graph[5].first = 2;
    graph[5].second = make_pair(2, 4);
    
    
    sort(graph, graph + edgesCNT);

    return 0;
}