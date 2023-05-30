#include "exception.hpp"
#include <iostream>
#include "input.hpp"
#include "graph.hpp"


int main(int argc, char* argv[]) {
    try{
        const std::string inputPath = argv[1];
        Graph graph(inputPath);
        int source = inputSource(graph);
        int destination = inputDestination(graph);
        std::cout << "Shortest path from source to destinantion is: " << graph.findShortestPath(source,destination) <<std::endl;
    }
    catch(Graph_validation& exception) {
        std::cout << exception.getMessage();
    }
    return 0;
}        
   
