#include "../src/graph.h"
#include "../src/data-parser.h"
#include <iostream>
#include <string>

int main() {
    Graph g;
    DataParser d;
    std::string file;
    std::string file2;

    while (file.empty()) {
        std::string dataset;
        std::cout << "Use sample dataset ('s') or full dataset ('f'): ";
        std::cin >> dataset;

        if (dataset == "s") {
            file = "lib/enwiki-2013-names-test.csv";
            file2 = "lib/enwiki-2013-test.txt";
            std::cout << "Using sample dataset" << std::endl;
        } else if (dataset == "f") {
            file = "lib/enwiki-2013-names.csv";
            file2 = "lib/enwiki-2013.txt";
            std::cout << "Using full dataset" << std::endl;
        } else {
            std::cout << "Invalid selection!" << std::endl;
        }
    }

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
                std::cout << "No path found!" << std::endl;
            } else {
                std::cout << "BFS Path: " << std::endl;
                for (auto node : res) {
                    std::cout << "Node: " << node << "  " << "Title: " << g.map[node]->title << std::endl;
                }
            }

        } else if (choice == "IDDFS") {
            std::vector<int> input = g.userNodeInput();
            std::string depth;

            std::cout << "Max Depth: ";
            std::cin >> depth;

            int res = g.IDDFS(input[0], input[1], stoi(depth));
            
            res == -1 ? std::cout << "No path found!" << std::endl : std::cout << "IDDFS Depth: " << res << std::endl;

        } else if (choice == "PageRank") {
            std::vector<int> input = g.userPageRankInput();
            g.PopulatePageRank(input[0], input[1]);
            std::cout << g.FindMostSignificantNode() << std::endl;
        } else if (choice == "end") {
            return 0;
        } else {
            std::cout << "Invalid Selection!" << std::endl;
        }
    }
}
