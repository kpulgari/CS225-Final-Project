#include "../src/graph.h"
#include "../src/data-parser.h"
#include <iostream>
#include <string>

int main() {
    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    DataParser d;

    d.PopulateGraph(g, file);
    std::cout << g.map.size() << std::endl;
}
