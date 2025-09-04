//bellman
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b;
    long long c; 
    Edge(int a, int b, long long c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long dis[1005]; 
vector<Edge> edge_list;
int n, e;
bool bellman_ford(int src) {
    for (int i = 1; i <= n; i++) 
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto ed : edge_list) {
            int a = ed.a, b = ed.b;
            long long c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }
    for (auto ed : edge_list) {
        int a = ed.a, b = ed.b;
        long long c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> e;
    while (e--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src; 
    cin >> src;
    int t; 
    cin >> t;
    vector<int> queries(t);
    for (int i = 0; i < t; i++) 
        cin >> queries[i];

    if (!bellman_ford(src)) {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    for (int d : queries) {
        if (dis[d] == LLONG_MAX) 
            cout << "Not Possible\n";
        else 
            cout << dis[d] << endl;
    }

    return 0;
}