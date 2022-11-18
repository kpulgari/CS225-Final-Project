#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/data-parser.h"
#include "../src/graph.h"

#include <cstddef>
#include <vector>

TEST_CASE("Testing CSV Parsing and Graph Population", "[data-parsing-csv]") { 
    const int nodeCount = 4206784;

    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    DataParser d;

    d.PopulateGraph(g, file);

    // testing map is correct size
    REQUIRE(g.map.size() == nodeCount);

    // testing correct id mapping
    REQUIRE(g.map[4]->title == "\"Kharqan\"");
    REQUIRE(g.map[3397412]->title == "\"Helko\"");
}

TEST_CASE("Testing TXT Parsing and Edge Vector Population", "[data-parsing-txt]") { 
    const int edgeCount = 101311613;

    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);

    // testing node's edge vector being populated
    REQUIRE(g.map[2]->edges.at(0) == 0);
    REQUIRE(g.map[1011088]->edges.at(0) == 10);
    REQUIRE(g.map[4206288]->edges.at(g.map[4206288]->edges.size() - 1) == 4206287);

    
    // testing total edge count is correct
    size_t edges = 0;

    for (size_t i = 0; i < g.map.size(); ++i) {
        edges += g.map[i]->edges.size();
    }

    std::cout << "Total edges: " << edges << std::endl;
    REQUIRE(edges == edgeCount);
}

TEST_CASE("BFS finds correct path between nodes", "[BFS-path]") {
    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);

    std::vector<int> vect1;
    vect1.push_back(0);
    vect1.push_back(2);
    REQUIRE(g.BFSpath(0, 2) == vect1);

 

}


#endif