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

    OrganismNode* begin();
    OrganismNode* end();
    size_t size();
private:
    OrganismNode* beginNode;
    OrganismNode* endNode;
    size_t nSize;
};
