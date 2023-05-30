#include "exception.hpp"
#include "graph.hpp"

#include <algorithm> //std::copy
#include <iostream>
#include <iterator> //std::back_inserter
#include <fstream>

Graph::Graph(const std::string& fileName ) { 
   readGraphFromFile(fileName);
}

void Graph::readGraphFromFile(const std::string& fileName) {

    std::ifstream input(fileName);
    if(!input) 
        throw Graph_validation("Faild to open input file\n");

    std::string line;
    std::getline(input,line);
    try {
        count_ = std::stoi(line);
    }
    catch(std::invalid_argument) {
        throw Graph_validation("Incorrect Graph representation\n");
    }
    nodes_.reserve(count_);

    while(std::getline(input,line)) {
        if(!line.empty()) {
            addNode(line);
        }
    }
}

void Graph::addNode(const std::string& line) {
    std::vector<int> vec = stringToVector(line);
    if(vec.empty())
        throw Graph_validation("Incorrect Graph representation\n");
    std::copy(std::next(vec.begin()), vec.end(), std::back_inserter(nodes_[vec[0]].adj));
}


std::vector<int> Graph::stringToVector(const std::string& line) {
    
    std::vector<int> vec;
    int i = 0;
    while(line[i] != '\0')
    {
        while(line[i] != '\0' && !isdigit(line[i]))
            ++i;
        if(line[i] != '\0') {
            int index = atoi(&line[i]);
            if(index < 0 || index >= count_)
                throw std::runtime_error("Incorrecr Graph representation\n");
            vec.push_back(index);
        }
        while(line[i] != '\0' && isdigit(line[i]))
            ++i;
    }
    return vec;
}

std::size_t Graph::getSize() const {
    return count_;
}

int Graph::findShortestPath(int source, int destination) {

    Queue q;
    q.push(nodes_[source]);
    nodes_[source].visited = true;
     
    while(!q.empty() && (nodes_[destination].visited != true) ) {
        Node parent = q.front();
        q.pop();

        for(auto i : parent.adj){
            if(!nodes_[i].visited) {
                nodes_[i].visited = true;
                nodes_[i].distance = parent.distance + 1;
                q.push(nodes_[i]);
            }
        }
    }
    return nodes_[destination].distance;

}


