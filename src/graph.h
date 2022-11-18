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
        
};