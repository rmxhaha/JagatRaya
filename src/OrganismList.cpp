#include "OrganismList.hpp"

OrganismList::OrganismList() {
    beginNode = NULL;
    endNode = NULL;
    nSize = 0;
}

OrganismList::~OrganismList(){};

void OrganismList::push_back(Organism* val) {
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

void OrganismList::pop_front() {
    if (nSize == 0) {
        return;
    }
    nSize--;
    beginNode = beginNode -> next;
}

OrganismNode* OrganismList::begin() { return beginNode; }
OrganismNode* OrganismList::end() { return NULL; }
size_t OrganismList::size() {return nSize; }
