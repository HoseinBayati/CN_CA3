#include "DVRPProtocol.hpp"
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

DVRPProtocol::DVRPProtocol()
{
}

void DVRPProtocol::print_info(int src, vector<int> parent, int V, int dis[])
{
    cout << "Dest | Next Hop | Dist | Shortest-Path" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < V; i++)
    {
        int current = i;
        vector<int> hops;
        hops.push_back(current + 1);
        string path = "";
        while (current != src)
        {
            if (current == i)
            {
                path += to_string(current + 1);
                current = parent[current];
            }
            else
            {
                path += ">-" + to_string(current + 1);
                current = parent[current];
            }
            hops.push_back(current + 1);
        }
        path += ">-" + to_string(src + 1);
        if (path[0] == '>')
        {
            path.erase(0, 2);
            hops.push_back(current + 1);
        }
        reverse(path.begin(), path.end());

        cout << i + 1 << " | " << hops[hops.size() - 2] << " | " << dis[i] << " |  [" << path << "]" << endl;
    }
}

void DVRPProtocol::apply_BellmanFord(vector<vector<int>> graph, int V, int E, int src)
{

    // Initialize distance of all vertices as infinite.
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = MAX_NUM;

    // initialize distance of source as 0
    dis[src] = 0;

    // Parent for each vertex
    vector<int> parent(V, -1);

    // Relax all edges |V| - 1 times.
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {

            if (dis[graph[j][0]] != MAX_NUM && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
                parent[graph[j][1]] = graph[j][0];
            }
        }
    }

    // check negative-weight cycles.
    for (int i = 0; i < E; i++)
    {
        if (dis[graph[i][0]] != MAX_NUM && dis[graph[i][0]] + graph[i][2] < dis[graph[i][1]])
        {
            cout << "Graph contains negative weight cycle" << endl;
        }
    }

    print_info(src, parent, V, dis);
}