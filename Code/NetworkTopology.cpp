#include "NetworkTopology.hpp"


NetworkTopology::NetworkTopology() {
}

NetworkTopology::NetworkTopology(int _number_of_nodes) {
    lsrp_protocol = LSRPProtocol();
    dvrp_protocol = DVRPProtocol();

    number_of_nodes = _number_of_nodes;

    for (int i = 0; i < number_of_nodes; i++)
    {
        vector<int> row;
        for(int j = 0; j < number_of_nodes; j++)
        {
            row.push_back(DEFAULT_COST);
        }

        adjacencyMatrix.push_back(row);
    }

    for(int i = 0; i < number_of_nodes; i++)
    {
        adjacencyMatrix[i][i] = 0;
    }
    
}

void NetworkTopology::add_path(int s,int d,int cost) {
    adjacencyMatrix[s-1][d-1] = cost;
    adjacencyMatrix[d-1][s-1] = cost;
}

void NetworkTopology::show() {
    cout << "     ";
    
    for (int i = 0; i < number_of_nodes; i++) {
        cout << i + 1;
        int len = to_string(i + 1).length();
        if (len == 1) {
            cout << "  ";
        }
        else if (len == 2) {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < number_of_nodes; i++) {
        cout << i + 1;
        int len = to_string(i + 1).length();
        if (len == 1) {
            cout << "  : ";
        }
        else if (len == 2) {
            cout << " : ";
        }

        for (int j = 0; j < number_of_nodes; j++) {
            if (!(adjacencyMatrix[i][j] == 0 && i != j)) cout << adjacencyMatrix[i][j];
            else cout << "-1";
            int len = to_string(adjacencyMatrix[i][j]).length();
            if (len == 1) {
                cout << "  ";
            }
            else if (len == 2) {
                cout << " ";
            }            
        }
        cout << "\n";
    }
}

void NetworkTopology::lsrp(int source) {
    auto begin = chrono::high_resolution_clock::now();

    lsrp_protocol.perform_lsrp(adjacencyMatrix, source - 1);

    auto end = chrono::high_resolution_clock::now();
    cout << "lsrp takes " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns" << endl; 
}

void NetworkTopology::lsrp() {
    std::chrono::duration<int64_t, std::nano> time_sum;
    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < number_of_nodes; i++)
    {
        lsrp_protocol.perform_lsrp(adjacencyMatrix, i);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "lsrp takes " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns" << endl;
}

void NetworkTopology::dvrp(int source) {
    vector<vector<int>> graph = get_graph();

    auto begin = chrono::high_resolution_clock::now();
    
    dvrp_protocol.apply_BellmanFord(graph,adjacencyMatrix.size(),graph.size(),source - 1);

    auto end = chrono::high_resolution_clock::now();
    cout << "dvrp takes " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns" << endl;
}

void NetworkTopology::dvrp() {


    vector<vector<int>> graph = get_graph();
    
    auto begin = chrono::high_resolution_clock::now();

    for (int i = 0; i < number_of_nodes; i++) {
        dvrp_protocol.apply_BellmanFord(graph,adjacencyMatrix.size(),graph.size(),i);
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "dvrp takes " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns" << endl; 
    
}

void NetworkTopology::modify(string change) {

    vector<string> path = split(change, '-');
    int source = stoi(path[0]);
    int dest   = stoi(path[1]);
    int cost   = stoi(path[2]);

    if(source == dest) {
        cout << "Destination and source can not be similar!" << endl;
        return;
    }
    add_path(source,dest,cost);
    cout << "ok" << endl;
}

void NetworkTopology::remove(string change) {
    
    vector<string> path = split(change, '-');
    int source = stoi(path[0]);
    int dest   = stoi(path[1]);

    if (source == dest)
    {
        cout << "Source and dest can not same!" << endl;
        return;
    }
    if (adjacencyMatrix[source - 1][dest - 1] == DEFAULT_COST)
    {
        cout << "There is no connection to remove!" << endl;
        return;
    }

    adjacencyMatrix[source-1][dest-1] = DEFAULT_COST;
    adjacencyMatrix[dest-1][source-1] = DEFAULT_COST;
    cout << "ok" << endl;
}

vector<string> NetworkTopology::split(string str, char divider) {
    stringstream ss(str);
    string word;
    vector< string> result;

    while(getline(ss, word, divider))
    {
        if(word != "")
            result.push_back(word);
    }
    return result;
}

vector<vector<int>> NetworkTopology::get_graph() {
    vector<vector<int>> graph;
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        for (int j = 0; j < adjacencyMatrix[i].size(); j++){
            if (adjacencyMatrix[i][j] > 0) {
                vector<int> edge;
                edge.push_back(i);
                edge.push_back(j);
                edge.push_back(adjacencyMatrix[i][j]);
                graph.push_back(edge);
            }
        }
    }

    return graph;
}