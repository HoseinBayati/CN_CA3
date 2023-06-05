#ifndef lSRPProtocol
#define lSRPProtocol

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Constants.hpp"

using namespace std;

class LSRPProtocol
{
public:
    LSRPProtocol();
    void perform_lsrp(vector<vector<int>> graph, int src);

private:
    int minDistance(vector<int> dist, vector<bool> sptSet);
    void printSolution(vector<int> dist, vector<int> parent, int src);
    void print_iter(vector<int> dis);
};

#endif