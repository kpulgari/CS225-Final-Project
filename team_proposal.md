## Leading Question 
We are going to create a Wikipedia search-based tool to find the distance between two given links. We are going to make a graph with the links as directed edges and the nodes will be represented as pages. We will use a BFS traversal and iterative deepening depth-first search to output the shortest path between the given inputs. We will compare the performance of both algorithms in finding the shortest path between two nodes. We will also use the PageRank algorithm to rank the pages by importance.
## Dataset Acquisition

## Data Format
We are going use two files of data from SNAP Stanford's dataset (https://snap.stanford.edu/data/enwiki-2013.html). One being a table with ids and the corresponding names of the Wikipedia pages, and the other is a text file with the corresponding connections. The dataset is 4 million nodes and 10 million edges. It is a subset of Wikipedia links, and we are going to use all of the data. 
## Data Correction
To check for data correctness, we will make sure our algorithm checks that the file follows a number-space-number format. If we discover a missing entry, we'll skip over that connection. We will also check make sure that no connections go out of bounds.
## Data Storage
We will use a map using the IDs of the Wikipedia pages as keys, and nodes which store the page and vector of edges as values. The big-O storage of our data will be O(N + E), where N is the number of nodes and E is the number of edges.
## Algorithm 
The inputs for the algorithm will be two valid IDs - one will be the starting node and the other will be the ending node. It is a one-way relationship. We will parse through the ID dataset to map each node to its given title. We will then parse through the textfile to population the nodes with their respective edges in the edge vector. 

For our BFS traversal, we will traverse through the graph until we reach the target node. We will then output the integer distance between the two nodes. The expected runtime for the BFS graph traversal is O(|N|+|E|), where N is the number of nodes and E is the number of edges in the graph. 

Our Iterative Deepening DFS algorithm will serve the same purpose as the BFS traversal, but it will use less memory. The output will also be printed out, and it will also be an integer denoting the distance between two nodes. The expected runtime for this algorithm is O(|N|+|E|) as well. 

Our final algorithm will be the PageRank algorithm, which will rank the pages based on their relative importance. Importance is measured by how many edges the node has, and the significance of the given edge's nodes as well. The input for the function will be the number of iterations, with more iterations resulting in more precise calculations. Once this algorithm runs, it will store all the nodes' importance values in the graph. Once populated, the user can view a particular node's importance value and compare it to other nodes as well. The runtime for this algorithm is O(E * k), where E is the number of edges, and k is the number of iterations. 
## Timeline
Data Acquisition: Already complete

Data Processing: Friday, November 18th

BFS Traversal: Friday, November 25th

Iterative Deepening DFS Algorithm: Friday, December 2nd

PageRank Algorithm: Friday, December 9th

Production of Final Deliverables: Monday, December 12th