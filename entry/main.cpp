#include "../src/graph.h"
#include "../src/data-parser.h"
#include <iostream>
#include <string>

int main() {
    Graph g;
    DataParser d;

    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);

    while (true) {
        std::string choice;

        std::cout << "Choose an algorithm (BFS, IDDFS, PageRank) or type 'end' to terminate: ";
        std::cin >> choice;

        if (choice == "BFS") {
            std::vector<int> input = g.userNodeInput();
            std::vector<int> res = g.BFSpath(input[0], input[1]);

            if (res.size() == 0) {
                std::cout << "-1" << std::endl;
            } else {
                std::cout << "BFS Path Size: " << res.size() << std::endl;
                std::cout << "BFS Path: ";
                for (auto node : res) {
                    std::cout << node << " ";
                }
                std::cout << "" << std::endl;
            }

        } else if (choice == "end") {
            return 0;
        } else {
            std::cout << "Invalid Selection!" << std::endl;
        }
    }
}
