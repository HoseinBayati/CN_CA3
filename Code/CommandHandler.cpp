#include "CommandHandler.hpp"

CommandHandler::CommandHandler() {
    number_of_nodes = 0;
}

vector<string> CommandHandler::split(string str, char divider) {
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

void CommandHandler::run()
{
    while(true)
    {
        string cmd;
        getline(cin, cmd);

        string cmd_type = split(cmd,' ')[0];
        
        if (cmd_type == TOPOLOGY) {
            init_topology(split(cmd,' '));
            cout << "ok" << endl;
        }

        else if (cmd_type == SHOW) {
            topology.show();
        }

        else if (cmd_type == LSRP) {
            if (split(cmd,' ').size() == 2)
                topology.lsrp(stoi(split(cmd,' ')[1]));
            else if (split(cmd,' ').size() == 1)
                topology.lsrp();
        }

        else if (cmd_type == DVRP) {
            if (split(cmd,' ').size() == 2)
                topology.dvrp(stoi(split(cmd,' ')[1]));
            else if (split(cmd,' ').size() == 1)
                topology.dvrp();
        }

        else if (cmd_type == MODIFY) {
            topology.modify(split(cmd,' ')[1]);
        }

        else if (cmd_type == REMOVE) {
            topology.remove(split(cmd,' ')[1]);
        }
    }
}

int CommandHandler::calcualte_number_of_node(vector<string> p) {
    int largest_node = MIN_NUM;
    for (int i = 1; i < p.size(); i++) {
        vector<string> path = split(p[i],'-');
        int source = stoi(path[0]);
        int dest   = stoi(path[1]);

        if (dest == source) {
            cout << "Destination and source can not be similar!" << endl;
            return 0;
        }

        if (dest > largest_node)
            largest_node = dest;
        if (source > largest_node)
            largest_node = source;    
    }
    return largest_node;
}

void CommandHandler::init_topology(vector<string> p) {

    number_of_nodes = calcualte_number_of_node(p);

    topology = NetworkTopology(number_of_nodes);

    for (int i = 1; i < p.size(); i++) {
        vector<string> path = split(p[i],'-');
        int source = stoi(path[0]);
        int dest   = stoi(path[1]);
        int cost   = stoi(path[2]);

        topology.add_path(source, dest, cost);
    }
}