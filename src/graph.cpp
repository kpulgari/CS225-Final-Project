#include "graph.h"
#include <queue>
#include <set>

std::vector<int> Graph::BFSpath(int start, int end) {
   
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
            int num = map[start]->edges.at(i);
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
    std::reverse(vect.begin(), vect.end());
    return vect;
}



 