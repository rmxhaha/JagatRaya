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
    OrganismList() {
        beginNode = NULL;
        endNode = NULL;
        nSize = 0;
    }
    ~OrganismList(){};

    void push_back(Organism* val) {
        nSize++;
        if (endNode == NULL)
        {
            beginNode = new OrganismNode(val);
            endNode = beginNode;
            return;
        }
        OrganismNode* tmp = new OrganismNode(val);
        endNode -> next = tmp;
        endNode = tmp;
        endNode -> next = NULL;
    }

    OrganismNode* begin() { return beginNode; }
    OrganismNode* end() { return NULL; }
    size_t size() {return nSize; }
private:
    OrganismNode* beginNode;
    OrganismNode* endNode;
    size_t nSize;
};
