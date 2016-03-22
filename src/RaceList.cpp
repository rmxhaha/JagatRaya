#include "RaceList.hpp"

RaceList::RaceList() {
    beginNode = NULL;
    endNode = NULL;
    nSize = 0;
}

RaceList::~RaceList(){};

void RaceList::push_back(Race* val) {
    nSize++;
    if (endNode == NULL)
    {
        beginNode = new RaceNode(val);
        endNode = beginNode;
        return;
    }
    RaceNode* tmp = new RaceNode(val);
    endNode->next = tmp;
    endNode = tmp;
    endNode -> next = NULL;
}

void RaceList::pop_front() {
    if (nSize == 0) {
        return;
    }
    nSize--;
    beginNode = beginNode -> next;
}

RaceNode* RaceList::begin() { return beginNode; }
RaceNode* RaceList::end() { return NULL; }
size_t RaceList::size() {return nSize; }

