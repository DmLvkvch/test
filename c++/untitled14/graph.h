#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include "edge.h"
#include "vertex.h"
class graph
{
private:
    map<Vertex, map<Vertex, Edge*>> city;
public:
    graph();
    void MakeGraph(Vertex a);
};

#endif // GRAPH_H
