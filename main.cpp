#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to, capacity, cost, flow;
    Edge(int t, int c, int cst, int f) : to(t), capacity(c), cost(cst), flow(f) {}
};

class MinCostFlow {
private:
    int vertices;
    vector<vector<Edge>> graph;
    vector<int> parent;

public:
    MinCostFlow(int v) : vertices(v), graph(v), parent(v) {}

    void addEdge(int u, int v, int capacity, int cost) {
        graph[u].emplace_back(v, capacity, cost, 0);
        graph[v].emplace_back(u, 0, -cost, 0);
    }

    pair<int, int> bellmanFord(int source, int target) {
        vector<int> dist(vertices, numeric_limits<int>::max());
        fill(parent.begin(), parent.end(), -1);
        dist[source] = 0;

        for (int i = 0; i < vertices - 1; ++i) {
            for (int u = 0; u < vertices; ++u) {
                for (const Edge& edge : graph[u]) {
                    int v = edge.to;
                    int capacity = edge.capacity;
                    int cost = edge.cost;
                    if (capacity > 0 && dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        parent[v] = u;
                    }
                }
            }
        }

        int current = target;
        int minCapacity = numeric_limits<int>::max();

        while (parent[current] != -1) {
            int u = parent[current];
            for (const Edge& edge : graph[u]) {
                if (edge.to == current) {
                    minCapacity = min(minCapacity, edge.capacity);
                    current = u;
                    break;
                }
            }
        }

        return {minCapacity, dist[target]};
    }

    int minCostFlow(int source, int target, int desiredFlow) {
        int totalFlow = 0;
        int totalCost = 0;

        while (totalFlow < desiredFlow) {
            pair<int, int> result = bellmanFord(source, target);

            int minCapacity = result.first;
            int pathCost = result.second;

            if (minCapacity == numeric_limits<int>::max())
                break;

            totalFlow += minCapacity;
            totalCost += pathCost * minCapacity;

            // Update residual capacities along the path
            int current = target;
            while (current != source) {
                int u = parent[current];
                if(u==-1) break;
                for (Edge& edge : graph[u]) {
                    if (edge.to == current) {
                        edge.capacity -= minCapacity;
                        edge.flow += minCapacity;
                        break;
                    }
                }
                current = u;
            }
        }

        return totalCost;
    }
};

int main() {
    MinCostFlow graph(4);
graph.addEdge(0,1,3,1);
graph.addEdge(0,2,2,2);
graph.addEdge(1,2,2,5);
graph.addEdge(1,3,3,1);
graph.addEdge(2,3,4,3);

int source=0, target=3, desiredFlow=5;
int totalCost=graph.minCostFlow(source,target,desiredFlow);
cout<< "Totall Cost: "<<totalCost<<endl;
return 0;

}
