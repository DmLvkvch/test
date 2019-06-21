#ifndef EDGE_H
#define EDGE_H


class Edge
{
private:
    int weight;

public:
    Edge();
};

class Ground:public Edge{
    int weight;
    Ground(int w){
        weight = w;
    }
};

class Water:public Edge{
    int weight;
    Water(int w){
        weight = w;
    }
};

class Air:public Edge{
    int weight;
    Air(int w){
        weight = w;
    }
};
#endif // EDGE_H
