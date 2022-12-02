#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/data-parser.h"
#include "../src/graph.h"

#include <cstddef>
#include <vector>

TEST_CASE("Testing CSV Parsing and Graph Population", "[data-parsing-csv]") { 
    const int nodeCount = 4206785;

    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    DataParser d;

    d.PopulateGraph(g, file);

    // testing map is correct size
    REQUIRE(g.map.size() == nodeCount);

    // testing correct id mapping
    REQUIRE(g.map[4]->title == "\"Kharqan\"");
    REQUIRE(g.map[19]->title == "\"The RSHS Catalyst\"");
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

    REQUIRE(edges == edgeCount);
}

TEST_CASE("BFS finds correct path between nodes with sample data", "[BFS-path-sample-data]") {
    Graph g;
    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";
    DataParser d;

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);

    // testing function produces valid BFS path from node 0 to node 2
    std::vector<int> vect1;
    vect1.push_back(0);
    vect1.push_back(2);

    REQUIRE(g.BFSpath(0, 2) == vect1);

    // testing function produces valid BFS path from node 2 to node 9
    std::vector<int> vect2;
    vect2.push_back(2);
    vect2.push_back(7);
    vect2.push_back(8);
    vect2.push_back(9);

    REQUIRE(g.BFSpath(2, 9) == vect2);

    // testing function returns empty vector when there is no BFS path
    std::vector<int> vect3;

    REQUIRE(g.BFSpath(2, 20) == vect3);
    REQUIRE(g.BFSpath(10, 7) == vect3);

    // testing function returns empty vector when there are invalid nodes
    std::vector<int> vect4;

    REQUIRE(g.BFSpath(-1, 2) == vect4);
    REQUIRE(g.BFSpath(1, 2523) == vect4);
}

TEST_CASE("BFS finds correct path between nodes", "[BFS-path]") {
    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(g, file);
    d.PopulateEdgeRelationships(g, file2);

    // testing function returns valid BFS path from node 20 to node 884615
    std::vector<int> vect1;
    vect1.push_back(20);
    vect1.push_back(882643);
    vect1.push_back(187334);
    vect1.push_back(207278);
    vect1.push_back(186941);
    vect1.push_back(884615);

    REQUIRE(g.BFSpath(20, 884615) == vect1);

    // testing function returns empty vector when there is no BFS path
    std::vector<int> vect2;

    REQUIRE(g.BFSpath(5, 8) == vect2);
    REQUIRE(g.BFSpath(20, 0) == vect2);

    // testing function returns empty vector when there are invalid nodes
    std::vector<int> vect4;

    REQUIRE(g.BFSpath(-1214, 21) == vect4);
    REQUIRE(g.BFSpath(1, 1316134911) == vect4);
}


#endif