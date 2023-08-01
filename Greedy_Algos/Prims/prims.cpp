#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int dest, weight;
};

class Graph
{
    int V;
    vector<vector<Edge>> adjList;

public:
    Graph(int V) : V(V), adjList(V) {}

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
    }

    void primMST()
    {
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0;

        pq.push(make_pair(0, src));

        vector<Edge> mst;
        int mstWeight = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (const Edge &edge : adjList[u])
            {
                int v = edge.dest;
                int weight = edge.weight;

                if (!visited[v])
                    pq.push(make_pair(weight, v));
            }

            if (u != src)
            {
                mst.push_back({u, pq.top().first});
                mstWeight += pq.top().first;
            }
        }

        cout << "Prim's MST:" << endl;
        for (const Edge &edge : mst)
        {
            cout << src << " - " << edge.dest << " : " << edge.weight << endl;
        }
        cout << "Total Weight of MST: " << mstWeight << endl;
    }
};

int main()
{
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    graph.primMST();

    return 0;
}
