#include "graph.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    Graph graph;

    std::ifstream inputFile;
    inputFile.open("enwiki-2013-names.csv");

    std::string line;

    // parsing input file
    while (getline(inputFile, line)) {
        int id;
        std::string title;
        std::string tempString;
        std::stringstream inputString(line);

        getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        getline(inputString, title, ',');

        // making node + populating graph
        if (!title.empty() && id > 0) {
        Graph::Node* node = new Graph::Node;
        node->title = title;
        graph.map[id] = node;
        }

        line = "";
    }

    std::cout << graph.map.size() << std::endl;
}