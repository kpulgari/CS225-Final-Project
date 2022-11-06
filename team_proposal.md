## Leading Question 
We are going to create a Wikipedia search-based tool to find the distance between two given links. We are going to make a graph with the links as directed edges and the nodes will be represented as pages. We will use Dijkstra's algorithm to output the shortest path between the given inputs.
## Dataset Acquisition

## Data Format
We are going use two files of data from SNAP Stanford's dataset. One being a table with ids and the corresponding names of the Wikipedia pages, and the other is a text file with the corresponding connections. The dataset is 4 million nodes and 10 million edges. It is a subset of Wikipedia links, and we are going to use all of the data. 
## Data Correction
To check for data correctness, we will make sure our algorithm checks that the file follows a number-space-number format. If we discover a missing entry, we'll skip over that connection. We will also check make sure that no connections go out of bounds.
## Data Storage
We will use a map using the IDs of the Wikipedia pages as keys, and nodes which store the page and vector of edges as values. The big-O storage of our data will be O(N + E), where N is the number of nodes and E is the number of edges.
## Algorithm 
The inputs for the algorithm will be two valid IDs - one will be the starting node and the other will be the ending node. It is a one-way relationship. We will parse through the ID dataset to map each node to its given title. We will then parse through the textfile to population the nodes with their respective edges in the edge vector. 

The expected output for our algorithm will be a integer that represents the shortest path between two IDs. We will print out the result.

Using Dikstra's algorithm, the anticipated runtime for our algorithm is O((V+E)log(V)), where V is the number of nodes and E is the number of edges. 
## Timeline
Data Acquisition: Already complete

Data Processing: 1-2 Weeks

Completion of Individual Algorithm: 2 Weeks

Production of Final Deliverables: 1 Week
