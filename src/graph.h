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
            double signficance = 0;
        };

        std::map<int, Node*> map;
        std::vector<int> userNodeInput();
        std::vector<int> userPageRankInput();
        std::vector<int> BFSpath(int start, int end);
        int IDDFS(int start, int end, int max_depth);
        bool DLS(int start, int end, int limit);
        void PopulatePageRank(int damping, int iterations);
        int FindGreatestPathBFS(int start, int end);
        std::string FindMostSignificantNode();
        //std::vector<int> Dijkstra(int start, int end);
        
};