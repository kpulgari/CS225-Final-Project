#pragma once

#include "graph.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class DataParser {
    public:
        void PopulateGraph(Graph& graph, const std::string filename);
        void PopulateEdgeRelationships(Graph& graph, const std::string filename);
};