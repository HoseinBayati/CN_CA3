#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "CommandHandler.hpp"

using namespace std;

int main() {

    CommandHandler cmd_handler = CommandHandler();
    cmd_handler.run();
    
    return 0;
}