#include "graph.h"
#include <queue>
#include <set>
#include <algorithm>

std::vector<int> Graph::BFSpath(int start, int end) {
    if ((start < 0 || start >= (int)map.size()) || (end < 0 || end >= (int)map.size())) {
        return std::vector<int>();
    }
   
    std::queue<int> q;
    std::set<int> visited;
    q.push(start);
    visited.insert(start);
    std::map<int, int> path;
    bool found = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == end) {
            found = true;
            break;
        } 
        for (size_t i = 0; i < map[v]->edges.size(); ++i) {
            int num = map[v]->edges.at(i);
            if (visited.find(num) == visited.end()) {
                visited.insert(num);
                q.push(num);
                path[num] = v;
            }
        }
    }

    std::vector<int> vect;
    if (!found) {
        return vect;
    }

    while (end != start) {
        vect.push_back(end);
        end = path[end];
    }

    vect.push_back(start);
    std::reverse(vect.begin(), vect.end());
    
    return vect;
}


int Graph::IDDFS(int start, int end, int max_depth) {
    if ((start < 0 || start >= (int)map.size()) || (end < 0 || end >= (int)map.size())) {
        return -1;
    }

    for (int i = 0; i <= max_depth; ++i) {
        if (DLS(start, end, i)) {
            return i;
        }
    }
    return -1;
}

bool Graph::DLS(int start, int end, int limit) {
    if (start == end) {
        return true;
    }
    if (limit <= 0) {
        return false;
    }

    for (size_t i = 0; i < map[start]->edges.size(); ++i) {
        if (DLS(map[start]->edges[i], end, limit - 1)) {
            return true;
        }
    }
    return false;
}



 