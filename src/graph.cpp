#include "graph.h"
#include <queue>

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

void Graph::PopulatePageRank(int damping, int iterations) {
    std::map<int, int> signficanceMap;
    int curr = 0;
    int count = iterations;

    while (iterations > 0) {
        bool skip = (rand() % 100) < damping;
        
        if (skip || map[curr]->edges.empty()) {
            curr = rand() % map.size();
            signficanceMap[curr] += 1; 
        } else {
            int temp = rand() % map[curr]->edges.size();
            curr = map[curr]->edges[temp];
            signficanceMap[curr] += 1;
        }

        iterations--;
    }

    for (auto node : signficanceMap) {
        Node*& currNode = map[node.first];
        currNode->signficance = ((double)node.second / (double)count);
    }
}

std::vector<int> Graph::userNodeInput() {
    std::string startingNode;
    std::string endingNode;
    std::vector<int> result;

    std::cout << "Starting Node: ";
    std::cin >> startingNode;

    std::cout << "Ending Node: ";
    std::cin >> endingNode;

    result.push_back(stoi(startingNode));
    result.push_back(stoi(endingNode));

    return result;
}

std::vector<int> Graph::userPageRankInput() {
    std::string damping;
    std::string iterations;
    std::vector<int> result;

    std::cout << "Damping Factor (0-100): ";
    std::cin >> damping;

    std::cout << "Number of Iterations: ";
    std::cin >> iterations;

    result.push_back(stoi(damping));
    result.push_back(stoi(iterations));

    return result;
}


int Graph::FindGreatestPathBFS(int start, int end) {
    std::vector<int> damping_iteration = userPageRankInput();
    int damping = damping_iteration.at(0);
    int iterations = damping_iteration.at(1);
    PopulatePageRank(damping, iterations);
    std::vector<int> store_path = BFSpath(start, end);
    double Total_significance = 0;
    for(int i : store_path) {
        Total_significance +=  map.at(i)->signficance;
    }

    return Total_significance;

}

std::string Graph::FindMostSignificantNode() {
    int current_best_key = 0;
    int greatest_significance = -1;
    for(auto iterate = map.begin();iterate != map.end(); iterate++) {
        if(iterate->second->signficance > greatest_significance) {
            current_best_key = iterate->first;
            greatest_significance = iterate->second->signficance;
        }
    }

    return map.at(current_best_key)->title;


}




// std::vector<int> Graph::Dijkstra(int start, int end) {
//     std::map<Node*, int> distance_map;// populate map with everythin being large except start which is 0
//     for(auto iterate = map.begin(); iterate != map.end(); iterate++) {
//         if(iterate->first == start) {
//             distance_map.insert({iterate->second,2});
//         } else {
//             distance_map.insert({iterate->second, 0});

//         }

//     }

//     std::set<Node*> visited; // defining the set to check visited

//     std::queue<std::pair<Node*, int>> priority_queue;
//     priority_queue.push({map.at(start), 2});// priority Queues significance is same as distance map second

//     while(!priority_queue.empty()) {
//         int significance = priority_queue.front().second;
//         int curr_int = start;
//         Node* current_node = priority_queue.front().first;// basically you need to set the distance and the node current then you pop queue and add to visited just like bfs
//         priority_queue.pop();
//         visited.insert(current_node);
//         // edges returns an int which is a key 
//         for(unsigned int i = 0; i < map.at(curr_int)->edges.size(); i++) {
//             //i is an iterator through the vector of edges and is in int so we can take this and find the node then find distance from it
//             if(distance_map.at(map.at(map.at(curr_int)->edges.at(i))) < distance_map.at(map.at(curr_int)) + map.at(map.at(curr_int)->edges.at(i))->signficance) {
//                 // now update stuff sorry this was so long
//                 distance_map.at(map.at(map.at(curr_int)->edges.at(i))) = distance_map.at(map.at(curr_int)) + map.at(map.at(curr_int)->edges.at(i))->signficance;

//             }
//             if(visited.find(map.at(map.at(curr_int)->edges.at(i))) == visited.end()) {
//                 //if visited does not contain this node add it to queues
//                 priority_queue.push({map.at(map.at(curr_int)->edges.at(i)), distance_map.at(map.at(map.at(curr_int)->edges.at(i)))});
//             }
            

//         }

//     }




// }

 



 