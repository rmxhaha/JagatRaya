#include "Race.hpp"

/**
 * RaceNode class.
 * RaceNode container node of Organism
 */
class RaceNode
{
public:
    /** \brief RaceNode Constructor
     *
     * \param val Race to contain
     * \return Race
     *
     */
    RaceNode(Race* val = NULL) : val(val), next(NULL) {}
    /** \brief RaceNode Destructor
     *
     */
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

