#include "Organism.hpp"

class OrganismNode
{
public:
    OrganismNode(Organism* val = NULL) : val(val), next(NULL) {}
    ~OrganismNode() {delete val;}

    Organism* val;
    OrganismNode* next;
};

class OrganismList
{
public:
    OrganismList();
    ~OrganismList();

    void push_back(Organism* val);
    void pop_front();

    OrganismNode* begin();
    OrganismNode* end();
    size_t size();
private:
    OrganismNode* beginNode;
    OrganismNode* endNode;
    size_t nSize;
};
