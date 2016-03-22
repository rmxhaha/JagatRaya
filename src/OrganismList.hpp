#include "Organism.hpp"

/**
 * OrganismNode class.
 * OrganismNode container node of Organism
 */
class OrganismNode
{
public:
    /** \brief OrganismNode Constructor
     *
     * \param val Organism to contain
     * \return OrganismFactory
     *
     */
    OrganismNode(Organism* val = NULL) : val(val), next(NULL) {}
    /** \brief OrganismNode Destructor
     *
     */
    ~OrganismNode() {delete val;}

    Organism* val;
    OrganismNode* next;
};

/**
 * OrganismList class.
 * OrganismList make list of OrganismNode
 */
class OrganismList
{
public:
    /** \brief OrganismList Constructor
     *
     * \return OrganismList
     *
     */
    OrganismList();
    /** \brief OrganismList Destructor
     *
     */
    ~OrganismList();

    /** \brief push Organism into the back of the list
     * \param val The organism to be pushed in
     */
    void push_back(Organism* val);
    /** \brief pop the front Organism in the list
     */
    void pop_front();

    /** \brief return the first OrganismNode
     * \return OrganismNode*
     */
    OrganismNode* begin();
    /** \brief return the last OrganismNode
     * \return OrganismNode*
     */
    OrganismNode* end();
    /** \brief return size of the list
     * \return size_t
     */
    size_t size();

private:
    OrganismNode* beginNode;
    OrganismNode* endNode;
    size_t nSize;
};
