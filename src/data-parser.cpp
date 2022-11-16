#include "data-parser.h"

void DataParser::PopulateGraph(Graph& graph, const std::string filename) {
    std::ifstream inputFile;
    inputFile.open(filename);
    std::string line;

    // parsing input file line by line
    while (getline(inputFile, line)) {
        int id;
        std::string title;
        std::string tempString;
        std::stringstream inputString(line);

        getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        getline(inputString, title, ',');

        // checking data corrrectedness + making node & populating graph
        if (!title.empty() && id >= 0) {
            Graph::Node* node = new Graph::Node;
            node->title = title;
            graph.map[id] = node;
        }

        line = "";
    }
}

void DataParser::PopulateEdgeRelationships(Graph& graph, const std::string filename) {
    std::ifstream inputFile;
    inputFile.open(filename);
    std::string line;

    // parsing input file line by line
    while (getline(inputFile, line)) {
        int start;
        std::string tempStringStart;
        int end;
        std::string tempStringEnd;
        std::stringstream inputString(line);

        getline(inputString, tempStringStart, ' ');
        start = atoi(tempStringStart.c_str());
        getline(inputString, tempStringEnd, ' ');
        end = atoi(tempStringEnd.c_str());

        // checking data corrrectedness + populating edge vector
        if ((start >= 0 && start <= 4206784) && (end >= 0 && end <= 4206784)) {
            graph.map[start]->edges.push_back(end);
        }

        line = "";
    }
};