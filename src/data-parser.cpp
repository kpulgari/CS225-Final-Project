#include "data-parser.h"

void DataParser::PopulateGraph(Graph& graph, const std::string filename) {
    std::ifstream inputFile;
    inputFile.open(filename);
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
}

// void DataParser::PopulateGraphRelationships(Graph& graph, const std::string filename) {

// };