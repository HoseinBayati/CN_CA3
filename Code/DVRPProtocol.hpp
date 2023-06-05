#ifndef dVRPProtocol
#define dVRPProtocol

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Constants.hpp"
#include <bits/stdc++.h>

using namespace std;

class DVRPProtocol
{
public:
    DVRPProtocol();
    void apply_BellmanFord(vector<vector<int>> graph, int V, int E, int src);

private:
    void print_info(int src, vector<int> parent, int V, int dis[]);  
};

#endif