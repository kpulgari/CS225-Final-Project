#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/data-parser.h"
#include "../src/graph.h"

TEST_CASE("Testing CSV Parsing and Graph Population", "[data-parsing]") { 
    Graph g;
    std::string file = "lib/enwiki-2013-names.csv";
    DataParser d;

    d.PopulateGraph(g, file);

    // testing map is correct size
    REQUIRE(g.map.size() == 4206784);

    // testing correct id mapping
    REQUIRE(g.map[4]->title == "\"Kharqan\"");
    REQUIRE(g.map[3397412]->title == "\"Helko\"");
}


#endif