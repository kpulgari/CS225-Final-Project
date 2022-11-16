#include "../src/graph.h"
#include "../src/data-parser.h"
#include <iostream>
#include <string>

int main() {
    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);
}
