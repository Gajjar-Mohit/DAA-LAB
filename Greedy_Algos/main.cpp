#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge
{
    int src, dest, weight;
};

class Graph
{
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    // Helper function to find parent of a node in the MST
    int find(vector<int> &parent, int i)
    {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    // Helper function to perform union of two sets of nodes
    void unionSets(vector<int> &parent, int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        parent[xroot] = yroot;
    }

    void kruskalMST()
    {
        // Sort edges in non-decreasing order of their weights
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
             { return a.weight < b.weight; });

        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        vector<Edge> mst;
        int mstWeight = 0;

        for (const Edge &edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int srcRoot = find(parent, src);
            int destRoot = find(parent, dest);

            // If adding this edge doesn't form a cycle, add it to the MST
            if (srcRoot != destRoot)
            {
                mst.push_back(edge);
                mstWeight += edge.weight;
                unionSets(parent, srcRoot, destRoot);
            }
        }

        cout << "Kruskal's MST:" << endl;
        for (const Edge &edge : mst)
        {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
        cout << "Total Weight of MST: " << mstWeight << endl;
    }
};

struct Edge1
{
    int dest, weight;
};

class Graph1
{
    int V;
    vector<vector<Edge1>> adjList;

public:
    Graph1(int V) : V(V), adjList(V) {}

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

    graph.kruskalMST();

    int V1 = 5;
    Graph1 graph1(V1);

    graph1.addEdge(0, 1, 2);
    graph1.addEdge(0, 3, 6);
    graph1.addEdge(1, 2, 3);
    graph1.addEdge(1, 3, 8);
    graph1.addEdge(1, 4, 5);
    graph1.addEdge(2, 4, 7);
    graph1.addEdge(3, 4, 9);

    graph1.primMST();

    return 0;
}
