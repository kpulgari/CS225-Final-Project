#pragma once

#include <string>
#include <vector>
#include <map>

class Graph {
    public:
        struct Node {
            std::string title;
            std::vector<int> edges;
        };

        std::map<int, Node*> map;
        std::vector<int> BFSpath(int start, int end);
        int Graph::IDDFS(int start, int end, int max_depth);
        bool Graph::DLS(int start, int end, int limit);
};