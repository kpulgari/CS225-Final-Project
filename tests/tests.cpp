#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/data-parser.h"
#include "../src/graph.h"

#include <cstddef>
#include <vector>



TEST_CASE("Testing CSV Parsing and Graph Population", "[data-parsing-csv]") { 
    Graph fullDataset;
    Graph sampleDataset;

    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    std::string file3 = "lib/enwiki-2013-names-test.csv";
    std::string file4 = "lib/enwiki-2013-test.txt";
    DataParser d;
    d.PopulateGraph(fullDataset, file);
    d.PopulateEdgeRelationships(fullDataset, file2);
    d.PopulateGraph(sampleDataset, file3);
    d.PopulateEdgeRelationships(sampleDataset, file4);

    const int nodeCount = 4206785;      

    // testing map is correct size
    REQUIRE(fullDataset.map.size() == nodeCount);

    // testing correct id mapping
    REQUIRE(fullDataset.map[4]->title == "\"Kharqan\"");
    REQUIRE(fullDataset.map[19]->title == "\"The RSHS Catalyst\"");
    REQUIRE(fullDataset.map[4204801]->title == "\"Elisabeth Owens\"");
    REQUIRE(fullDataset.map[4204802]->title == "\"SS Hastier\"");
    REQUIRE(fullDataset.map[4204803]->title == "\"Isabel Crawford\"");
    REQUIRE(fullDataset.map[4204804]->title == "\"USS Vigilant\"");
    REQUIRE(fullDataset.map[1979104]->title == "\"Metropolis of Philadelphia\"");
    REQUIRE(fullDataset.map[608470]->title == "\"Gambsheim\"");
    REQUIRE(fullDataset.map[608471]->title == "\"Herrlisheim\"");

    
}

TEST_CASE("Testing TXT Parsing and Edge Vector Population", "[data-parsing-txt]") { 

    Graph fullDataset;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(fullDataset, file);
    d.PopulateEdgeRelationships(fullDataset, file2);
    const int edgeCount = 101311613;

    // testing node's edge vector being populated
    REQUIRE(fullDataset.map[2]->edges.at(0) == 0);
    REQUIRE(fullDataset.map[1011088]->edges.at(0) == 10);
    REQUIRE(fullDataset.map[4206288]->edges.at(fullDataset.map[4206288]->edges.size() - 1) == 4206287);

    // testing total edge count is correct
    size_t edges = 0;

    for (size_t i = 0; i < fullDataset.map.size(); ++i) {
        edges += fullDataset.map[i]->edges.size();
    }

    REQUIRE(edges == edgeCount);
}

TEST_CASE("BFS finds correct path between nodes using sample data", "[BFS-path-sampleDataset]") {

    Graph sampleDataset;
    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";
    DataParser d;

    d.PopulateGraph(sampleDataset, file);
    d.PopulateEdgeRelationships(sampleDataset, file2);

    // testing function produces valid BFS path from node 0 to node 2
    std::vector<int> vect1;
    vect1.push_back(0);
    vect1.push_back(2);

    REQUIRE(sampleDataset.BFSpath(0, 2) == vect1);
    // testing function produces valid BFS path from node 2 to node 9
    std::vector<int> vect2;
    vect2.push_back(2);
    vect2.push_back(7);
    vect2.push_back(8);
    vect2.push_back(9);

    REQUIRE(sampleDataset.BFSpath(2, 9) == vect2);

    // testing function returns empty vector when there is no BFS path from node 2 to node 12
    std::vector<int> vect3;

    REQUIRE(sampleDataset.BFSpath(2, 12) == vect3);

    // testing function returns a vector with one element if start and end are equal
    std::vector<int> vect4;
    vect4.push_back(20);

    REQUIRE(sampleDataset.BFSpath(20, 20) == vect4);

    // testing path direction works one way
    std::vector<int> vect5;

    REQUIRE(sampleDataset.BFSpath(7, 2) == vect5);
}

TEST_CASE("BFS finds correct path between nodes using full dataset", "[BFS-path-fullDataset]") {

    Graph fullDataset;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(fullDataset, file);
    d.PopulateEdgeRelationships(fullDataset, file2);

    // testing function returns valid BFS path from node 20 to node 884615
    std::vector<int> vect1;
    vect1.push_back(20);
    vect1.push_back(882643);
    vect1.push_back(187334);
    vect1.push_back(207278);
    vect1.push_back(186941);
    vect1.push_back(884615);

    REQUIRE(fullDataset.BFSpath(20, 884615) == vect1);

    // testing function returns empty vector when there is no BFS path from node 5 to node 8
    std::vector<int> vect2;

    REQUIRE(fullDataset.BFSpath(5, 8) == vect2);
}

TEST_CASE("IDDFS has expected values using sample dataset", "[IDDFS-sampleDataset]") {

    Graph sampleDataset;
    std::string file = "lib/enwiki-2013-names.csv";
    std::string file2 = "lib/enwiki-2013.txt";
    DataParser d;

    d.PopulateGraph(sampleDataset, file);
    d.PopulateEdgeRelationships(sampleDataset, file2);

     // testing IDDFS function returns proper depth
    REQUIRE(sampleDataset.IDDFS(14,17,10) == 2); 

    // IDDFS function returns -1 when there is no path

    REQUIRE(sampleDataset.IDDFS(4,5,3) == -1);

    REQUIRE(sampleDataset.IDDFS(0,9,2) == -1);

    REQUIRE(sampleDataset.IDDFS(0,9,1) == -1);

}

TEST_CASE("IDDFS matches up with BFS path using sample dataset", "[IDDFS-BFS-match-sampleDataset]") {

    Graph sampleDataset;
    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";
    DataParser d;

    d.PopulateGraph(sampleDataset, file);
    d.PopulateEdgeRelationships(sampleDataset, file2);

    REQUIRE(sampleDataset.IDDFS(14,17, 10) == int(sampleDataset.BFSpath(14,17).size()) - 1);

    REQUIRE(sampleDataset.IDDFS(0,7, 10) == int(sampleDataset.BFSpath(0,7).size()) - 1);

    REQUIRE(sampleDataset.IDDFS(4,5, 10) == int(sampleDataset.BFSpath(4,5).size()) - 1);

    REQUIRE(sampleDataset.IDDFS(0,9, 10) == int(sampleDataset.BFSpath(0,9).size()) - 1);

}

TEST_CASE("PageRank works properly using sample data", "[PageRank-sampleDataset]") {

    Graph sampleDataset;
    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";
    DataParser d;

    d.PopulateGraph(sampleDataset, file);
    d.PopulateEdgeRelationships(sampleDataset, file2);

    // testing signficance when damping factor is 0
    sampleDataset.PopulatePageRank(0, 100000);
 
    REQUIRE(sampleDataset.map[18]->signficance > sampleDataset.map[3]->signficance);
    REQUIRE(sampleDataset.map[20]->signficance > sampleDataset.map[9]->signficance);

    // testing signficance when damping factor is 80
    sampleDataset.PopulatePageRank(80, 100000);

    REQUIRE(sampleDataset.map[18]->signficance > sampleDataset.map[3]->signficance);
    REQUIRE(sampleDataset.map[20]->signficance > sampleDataset.map[9]->signficance);
}

TEST_CASE("Correctly finds most significant node in sample data", "[FindMostSignificantNode-sampleDataset]") {

    Graph sampleDataset;
    std::string file = "lib/enwiki-2013-names-test.csv";
    std::string file2 = "lib/enwiki-2013-test.txt";
    DataParser d;

    d.PopulateGraph(sampleDataset, file);
    d.PopulateEdgeRelationships(sampleDataset, file2);

    sampleDataset.PopulatePageRank(80, 100000);
    REQUIRE(sampleDataset.FindMostSignificantNode() == 20);
}



#endif