#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void ChangeAllValues(vector<int>& l, int v, int u) { 
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] == v) {
            l[i] = u;
        }
    }
    
}


int main() { 
    const int vertexCNT = 5;
    const int edgesCNT = 7;

    // first is weight, second is pair of vertex (edge)
    vector<pair<int, pair<int, int>>> graph(edgesCNT);

    vector <pair<int, pair<int, int>>> tree;    // Spanning tree

    vector<int> l(vertexCNT);

    int cost = 0;

    // Input Graph
    graph[0].first = 1;
    graph[0].second = make_pair(0, 1);
    graph[1].first = 3;
    graph[1].second = make_pair(0, 2);
    graph[2].first = -2;
    graph[2].second = make_pair(0, 4);
    graph[3].first = -1;
    graph[3].second = make_pair(1, 3);
    graph[4].first = -1;
    graph[4].second = make_pair(1, 4);
    graph[5].first = 1;
    graph[5].second = make_pair(3, 4);
    graph[6].first = 2;
    graph[6].second = make_pair(2, 4);

    for (int i = 0; i < vertexCNT; ++i) {
        l[i] = i;
    }


    sort(graph.begin(), graph.end());    // Sorting edges


    // main logic
    for (int i = 0; i < edgesCNT; ++i) {
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        if(l[u] != l[v]) { 
            // add (u,v) edge to tree
            tree.push_back(graph[i]);
            ChangeAllValues(l, l[v], l[u]);        // Change all l[v] -> l[u]
            cost += graph[i].first;
        }
    }


    cout << "Spanning Tree" << endl;
    int edgesCountOfTree = tree.size();
    for (int i = 0; i < edgesCountOfTree; i++) {
        cout << "Edge: (" << tree[i].second.first << ", " << tree[i].second.second << ") " << "Weight: " << tree[i].first << "\n";
    }

    cout << "Cost: " << cost << endl;
    return 0;
}