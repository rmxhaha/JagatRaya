#ifndef MAHKLUP_HIDUP
#define MAHKLUP_HIDUP


#include "Universe.hpp"

class Universe;
class Organism {
public:
	/** \brief Organism Constructor
     *
     * \param universe Universe it belong in
     * \return Organism
     *
     */
	Organism(Universe& u, int x, int y, float currentAge);

	/** \brief X location of the organism
		\return
	*/
	int getX()const ;
	/** \brief Y location of the organism
		\return int
	*/
	int getY() const;

	/** \brief true if organism is dead
		\return bool
	*/
    float getCurrentAge() const;

	bool isDead() const;
	/** \brief true if organism is alive
		\return bool
	*/
	bool isAlive() const;

    /** \brief ch is a character of the organism it represents
     * \return char of the organism it represent
     */
	virtual char ch() const = 0;
	/** \brief age is maximum age before the organism it represents die because of old
     *  \return int of the maximum age
     */
	virtual int age() const = 0;
	/** \brief power is power of the organism it represents
     * \return int of power the organism it represent
     */
	virtual int power() const = 0;
	/** \brief do the organism behaviour if reach time.
	 *  \param dt delta time for doing the organism behaviour
	*/
	virtual void update(float dt); // delta time in milliseconds
	/** \brief interaction between organism
	 *  \param organism which this organism will interact with
     */
	virtual void interact(Organism*) = 0;
	/** \brief kill the organism
     */
    void forceKill();
protected:
    void setX( int _x );
    void setY( int _y );
    void setCurrentAge( float age );

    float cAge; // current age
	bool is_dead;
	int x,y;
	Universe* universe;
};

#endif
