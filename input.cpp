#include "input.hpp"
#include <iostream>
#include "exception.hpp"
#include "graph.hpp"


int inputSource(const Graph& graph) {
    int s;
    std::cout << "Enter Source node to calculate the shortest path: ";
    std::cin >> s;
    if(s < 0 || s > graph.getSize()-1) {
        throw Graph_validation("Source node is out of range\n");
    } 
    return s;
}

int inputDestination(const Graph& graph) {
    int d;
    std::cout << "Enter Destination node to calculate the shortest path: ";
    std::cin >> d;
    if(d < 0 || d > graph.getSize()-1) {
        throw Graph_validation("Deestination node is out of range\n");
    } 
    return d;
}
