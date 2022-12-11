#include "graph.h"
#include <queue>

std::vector<int> Graph::BFSpath(int start, int end) {
    //basic checks for size out of bounds errors
    if ((start < 0 || start >= (int)map.size()) || (end < 0 || end >= (int)map.size())) {
        return std::vector<int>();
    }
   
    std::queue<int> q;
    std::set<int> visited;
    q.push(start);
    visited.insert(start);
    // path keeps track of which nodes point to which
    // key is node being pointed to and value is node that the edge is coming from
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
    // if end is not found, return empty vector
    if (!found) {
        return vect;
    }
    // go backwards through path to get return vector
    // this will be backwards, so we must reverse
    while (end != start) {
        vect.push_back(end);
        end = path[end];
    }

    vect.push_back(start);
    
    std::reverse(vect.begin(), vect.end());
    
    return vect;
}


int Graph::IDDFS(int start, int end, int max_depth) {
    //basic checks for size out of bounds errors
    if ((start < 0 || start >= (int)map.size()) || (end < 0 || end >= (int)map.size())) {
        return -1;
    }
    // run depth level search for each depth until max_depth
    for (int i = 0; i <= max_depth; ++i) {
        if (DLS(start, end, i)) {
            return i;
        }
    }
    // if end is not found, we return -1
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
    //the key in SignificanceMap is the key for accessign Node and its int is the times it has been visited
    std::map<int, int> signficanceMap;
    int curr = 0;
    int count = iterations;

    while (iterations > 0) {
        bool skip = (rand() % 100) < damping;
        //if the random generated number between 0 to 99 is less than damping you skip to random node in graph
        if (skip || map[curr]->edges.empty()) {
            curr = rand() % map.size();
            signficanceMap[curr] += 1; 
        } else {
            //here you skip to a random node that is connected to the current node within the smae cluster
            int temp = rand() % map[curr]->edges.size();
            curr = map[curr]->edges[temp];
            signficanceMap[curr] += 1;
        }

        iterations--;
    }

    for (auto node : signficanceMap) {
        Node*& currNode = map[node.first];

        // this takes the total ties it was visited/ total iterations to get like the percent of times it was visited
        currNode->signficance = ((double)node.second / (double)count);
    }
}

std::vector<int> Graph::userNodeInput() {
    std::string startingNode;
    std::string endingNode;
    std::vector<int> result;
    // user inputs start and end node for the traversals
    std::cout << "Starting Node: ";
    std::cin >> startingNode;

    std::cout << "Ending Node: ";
    std::cin >> endingNode;

    result.push_back(stoi(startingNode));
    result.push_back(stoi(endingNode));

    // sends start and end nodes back to use in our traversal

    return result;
}

std::vector<int> Graph::userPageRankInput() {
    // low damping means it is likely the next node will be an edge of the current node hgih damping is more likely to jump to random node
    std::string damping;
    // iterations is how many nodes you running function
    std::string iterations;
    std::vector<int> result;
    // take user inputs and put them into out damping and iteration variables
    std::cout << "Damping Factor (0-100): ";
    std::cin >> damping;

    std::cout << "Number of Iterations: ";
    std::cin >> iterations;

    result.push_back(stoi(damping));
    result.push_back(stoi(iterations));

    return result;
}

int Graph::FindMostSignificantNode() {
    //The current best key 
    int current_best_key = 0;
    // settign significance value to something low
    int greatest_significance = -1;
    for(auto iterate = map.begin();iterate != map.end(); iterate++) {
        //iterates through every node in the graph
        if(iterate->second->signficance > greatest_significance) {
            //basically if there is a more significant node you change the current key to set it as the new node and change significance
            current_best_key = iterate->first;
            greatest_significance = iterate->second->signficance;
        }
    }

    return current_best_key;
}





 



 