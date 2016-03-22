#include "Race.hpp"

class RaceNode
{
public:
    RaceNode(Race* val = NULL) : val(val), next(NULL) {}
    ~RaceNode() {delete val;}

    Race* val;
    RaceNode* next;
};

class RaceList
{
public:
    RaceList();
    ~RaceList();

    void push_back(Race* val);
    void pop_front();
    RaceNode* begin();
    RaceNode* end();
    size_t size();
private:
    RaceNode* beginNode;
    RaceNode* endNode;
    size_t nSize;
};

