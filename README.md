# CS225-Final-Project
Final Project for CS 225

The entry folder contains “main.cpp”, which is where the user can run our algorithms on a graph created either from the full dataset or our sample dataset. The lib folder contains all our datasets. The files enwiki-2013-names.csv and enwiki-2013.txt are the files we obtained from the Stanford SNAP group at https://snap.stanford.edu/data/enwiki-2013.html. The other two files are sample data that we created for testing. Our src folder contains the code for our two classes: DataParser and Graph. Finally, our tests folder contains the test cases for all our functions.

We have two classes in this project: DataParser and Graph. The graph class creates a data structure to represent our data as a graph and contains functions that run each of our algorithms on the structure. The DataParser class takes the datafiles that have information about which pages are connected to which and populates a graph using that data.

Our main file prompts the user for input to create a graph and run our algorithms on it. First, they can choose whether to populate their graph with the full dataset or the sample dataset we created to test our algorithms with simpler data. Then, they can choose which of our three algorithms they want to run on the data, and with what parameter values, and the program will output the result in the terminal. After this, the user can choose to terminate their program or run a different algorithm.

To run the main function, the user must run “make”, and then run “./bin/exec”. The user will then be prompted for the relevant input in the terminal.

To run our tests, the user must run “make tests”, and then run “./bin/tests” to run all of the test cases or “./bin/tests xxx” to run a specific test case, where xxx is the tag of that test case.
