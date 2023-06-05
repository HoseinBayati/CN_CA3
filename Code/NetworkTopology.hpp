#ifndef networkTopology
#define networkTopology

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Constants.hpp"
#include "LSRPProtocol.hpp"
#include "DVRPProtocol.hpp"
#include <chrono>

using namespace std;


class NetworkTopology {
public:
    NetworkTopology(int _number_of_nodes);
    NetworkTopology();

    void add_path(int s,int d,int cost);
    void show();
    void lsrp(int source);
    void lsrp();
    void dvrp(int source);
    void dvrp();
    vector<string> split(string str, char divider);
    void modify(string change);
    void remove(string change);

private:
    vector<vector<int>> adjacencyMatrix;
    int number_of_nodes;
    LSRPProtocol lsrp_protocol;
    DVRPProtocol dvrp_protocol;

    vector<vector<int>> get_graph();
};

#endif