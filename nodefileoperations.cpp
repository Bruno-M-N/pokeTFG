#include "nodefileoperations.h"

void WriteNodeType(std::ofstream& file, NodeType nodeType)
{	char charNodeType = (char) nodeType;
    //Write 1 byte to the file
    file.write((char*) (&charNodeType),1 );
}

NodeType ReadNodeType (std::istream& file)
{   char charNodeType = 0;
    //Read 1 byte from the file
    file.read( (char*) (&charNodeType), 1);
    NodeType nodeType = (NodeType) charNodeType;
    return nodeType;
}

void WriteNodeStatus(std::ofstream& file, NodeStatus nodeStatus)
{	char charNodeStatus = (char) nodeStatus;
    //Write 1 byte to the file
    file.write((char*) (&charNodeStatus),1 );
}

NodeStatus ReadNodeStatus (std::istream& file)
{   char charNodeStatus = 0;
    //Read 1 byte from the file
    file.read( (char*) (&charNodeStatus), 1);
    NodeStatus nodeStatus = (NodeStatus) charNodeStatus;
    return nodeStatus;
}

void WriteClassNode (std::ofstream& file, Node* toWriteNode)
{   uint8_t data = toWriteNode->getIdentifier();
    file.write((char*) &data, 1);
    WriteUint32_t(file, (uint32_t) toWriteNode->getX());
    WriteUint32_t(file, (uint32_t) toWriteNode->getY());
    WriteNodeType(file, toWriteNode->getNodeType());
    WriteNodeStatus(file, toWriteNode->getNodeStatus());
}

Node* ReadClassNode (std::istream& file, QObject *parent)
{   uint8_t data = 0;
    file.read( (char*) &data, 1);
    Node *toReadNode = new Node ((unsigned char) data, 0, 0, NodeType::Normal, NodeStatus::Free, parent);
    toReadNode->setX(ReadUint32_t(file));
    toReadNode->setY(ReadUint32_t(file));
    toReadNode->setNodeType(ReadNodeType(file));
    toReadNode->setNodeStatus(ReadNodeStatus(file));

    //Node *ptrNode = &toReadNode;
    return toReadNode; //ptrNode;
//    unsigned char nodeIdentifier = (unsigned char) data;
//    int positionX = ReadUint32_t(file);
//    int positionY = ReadUint32_t(file);
//    NodeType nodeTypeValue = ReadNodeType(file);
//    NodeStatus nodeStatusValue = ReadNodeStatus(file);
//    //printf("opa");
//    return Node(nodeIdentifier, positionX, positionY,
//                nodeTypeValue, nodeStatusValue);
}

//void ReadClassNode (std::istream& file, Node* toReadNode)
//{   uint8_t data = 0;
//    file.read( (char*) &data, 1);
//    toReadNode->setIdentifier((unsigned char) data);
//    toReadNode->setX(ReadUint32_t(file));
//    toReadNode->setY(ReadUint32_t(file));
//    toReadNode->setNodeType(ReadNodeType(file));
//    toReadNode->setNodeStatus(ReadNodeStatus(file));
//}

void WriteLocalAdjacencyList  (std::ofstream& file,
                               std::vector< unsigned char > localAdjacencyList)
{   uint32_t lenght = localAdjacencyList.size();
    //std::cout << "String size: " << length << std::endl;

    WriteUint32_t(file, lenght);
    for (unsigned int i = 0; i < lenght; i++)
    {   uint8_t data = localAdjacencyList[i];
        file.write((char*) &data, 1);
    }
}

std::vector< unsigned char > ReadLocalAdjacencyList (std::istream& file)
{   uint32_t lenght = ReadUint32_t(file);
    int8_t data = 0;

    std::vector< unsigned char > localAdjacencyList;
    localAdjacencyList.reserve(lenght);

    for (unsigned int i = 0; i < lenght; i++)
    {   file.read( (char*) &data, 1);
        localAdjacencyList.push_back( (unsigned char) data);
    }
    return localAdjacencyList;
}

void WriteAdjacencyList  (std::ofstream& file,
                          adjacencyListType adjacencyList)
{   uint32_t lenght = adjacencyList.size();
    //std::cout << "String size: " << length << std::endl;

    WriteUint32_t(file, lenght);
    for (unsigned int i = 0; i < lenght; i++)
    {   WriteLocalAdjacencyList(file, adjacencyList[i]);
    }
}

adjacencyListType ReadAdjacencyList (std::istream& file)
{   uint32_t lenght = ReadUint32_t(file);

    adjacencyListType adjacencyList;
    adjacencyList.reserve(lenght);

    for (unsigned int i = 0; i < lenght; i++)
    {   adjacencyList.push_back(ReadLocalAdjacencyList(file));
    }
    return adjacencyList;
}

/// Delete previous contend and replace it
void saveNodesToFile(std::string fileName,
                     std::vector<Node*> &vectorNodes,
                     adjacencyListType adjacencyList)
{	std::cout << fileName << std::endl;
    std::ofstream File;

    // ios::out - output - File open for writing: the internal stream buffer
    // supports output operations.
    // ios::binary - binary - Operations are performed in binary mode rather
    // than text.
    File.open(fileName, std::ios::out | std::ios::binary);

    unsigned int vectorNodeSize = vectorNodes.size();

    if (File.is_open())
    {	WriteUint32_t(File, (uint32_t) vectorNodeSize);
        for (unsigned int i = 0; i < vectorNodeSize; i++)
        {	WriteClassNode(File, vectorNodes[i]);
        }
        WriteAdjacencyList(File, adjacencyList);
    }else
    {	std::cout<<"\nCouldn't open the file.\n";
    }
    File.close();
}

void loadNodesFromFile(std::string fileName,
                       std::vector<Node*> & vectorNodes,
                       adjacencyListType &adjacencyList,
                       QObject *parent)
{	std::cout << fileName << std::endl;
    std::ifstream File;

    // ios::in - input - File open for reading: the internal stream buffer
    // supports input operations.
    // ios::ate - at end - 	The output position starts at the end of the file.
    // ios::binary - binary - Operations are performed in binary mode rather
    // than text.
    File.open(fileName, std::ios::in | std::ios::ate | std::ios::binary);

    if (File.is_open())
    {	std::streampos fileSize, current;


        // get length of file:

        // Get position in input sequence
        // Returns the position of the current character in the input stream.
        fileSize = File.tellg();
        // Set position in input sequence
        // Sets the position of the next character to be extracted from the
        // input stream.
        File.seekg(0, std::ios::beg); //ios_base::beg : beginning of the stream
        std::cout << "\nLoading data from binary file \"" << fileName <<
                     "\". File data size: " << fileSize << " bytes.\n" <<
                     std::endl;

        uint32_t lenght = ReadUint32_t(File);
        vectorNodes.reserve(lenght);
        for (unsigned int i = 0; i < lenght; i++)
        {	//Node node(0, 0, 0, NodeType::Normal, NodeStatus::Free);
            //Node node = ReadClassNode(File, ptrNode);
            Node *ptrNode = ReadClassNode(File, parent);
            vectorNodes.push_back(ptrNode);
            ptrNode = nullptr;
        }
        adjacencyList = ReadAdjacencyList(File);


//        ReadClassNode(File, node);
//        vectorNodes.push_back(node);
//        current = File.tellg();
//        //std::cout << "\nCurrent: " << current;
//        // Minimize the number of potential reallocations, by reserving an
//        // approximation of the number of nodes written in the file + 1 +
//        // the current size
//        vectorNodes.reserve(vectorNodes.size() + (int)(fileSize / current + 1));

//        for (;;)//current < fileSize;)
//        {	ReadClassNode(File, node);
//            current = File.tellg();
//            //std::cout << "\nCurrent: " << current;
//            vectorNodes.push_back(node);
//            if (File.peek() == EOF) break;
//        }
    }else
    {	std::cout<<"\nCouldn't open the file.\n";
    }
    File.close();
}

