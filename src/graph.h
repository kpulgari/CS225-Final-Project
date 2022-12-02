#pragma once

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

class Graph {
    public:
        struct Node {
            std::string title;
            std::vector<int> edges;
        };

        std::map<int, Node*> map;
        std::vector<int> userNodeInput();
        std::vector<int> BFSpath(int start, int end);
        int IDDFS(int start, int end, int max_depth);
        bool DLS(int start, int end, int limit);
};