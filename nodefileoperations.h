#ifndef NODEFILEOPERATIONS_H
#define NODEFILEOPERATIONS_H

// basic file operations
#include <iostream>
#include <fstream>

#include <vector>

#include "file_operations.h"

#include "node.h"
#include "graph.h"

void WriteNodeType(std::ofstream& file, NodeType nodeType);

NodeType ReadNodeType(std::istream& file);

void WriteNodeStatus(std::ofstream& file, NodeStatus nodeType);

NodeStatus ReadNodeStatus(std::istream& file);

void WriteClassNode(std::ofstream& file, Node* toWriteNode);

Node* ReadClassNode (std::istream& file,
                     QObject *parent = nullptr);

//void ReadClassNode(std::istream& file, Node* toReadNode);

void WriteLocalAdjacencyList  (std::ofstream& file,
                               std::vector< unsigned char > localAdjacencyList);

std::vector< unsigned char > ReadLocalAdjacencyList (std::istream& file);

void WriteAdjacencyList  (std::ofstream& file,
                          adjacencyListType adjacencyList);

adjacencyListType ReadAdjacencyList (std::istream& file);

// Delete previous contend and replace it
void saveNodesToFile(std::string fileName,
                     std::vector<Node*> & vectorNodes,
                     adjacencyListType adjacencyList);

void loadNodesFromFile(std::string fileName,
                       std::vector<Node*> & vectorNodes,
                       adjacencyListType & adjacencyList,
                       QObject *parent = nullptr);



#endif // NODEFILEOPERATIONS_H
