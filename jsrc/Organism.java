abstract class Organism {
    protected float cAge; // current age
	protected bool is_dead;
	protected int x,y;
	protected Universe universe;
	/** \brief Organism Constructor
     *
     * \param universe Universe it belong in
     * \return Organism
     *
     */
	public Organism(Universe _u, int _x, int _y, float age) {
		universe = _u;
		x = _x;
		y = _y;
		currentAge = age;
		is_dead = false;
	}

	/** \brief X location of the organism
		\return
	*/
	public int getX() {
		return x;
	}
	/** \brief Y location of the organism
		\return int
	*/
	public int getY() {
		return y;
	}

	/** \brief true if organism is dead
		\return bool
	*/
    public float getCurrentAge() {
    	return currentAge;
    }

	public boolean isDead() {
		return is_dead;
	}
	/** \brief true if organism is alive
		\return bool
	*/
	public boolean isAlive() {
		return !is_dead;
	}

    /** \brief ch is a character of the organism it represents
     * \return char of the organism it represent
     */
	public abstract char ch();
	/** \brief age is maximum age before the organism it represents die because of old
     *  \return int of the maximum age
     */
	public abstract int age();
	/** \brief power is power of the organism it represents
     * \return int of power the organism it represent
     */
	public abstract int power();
	/** \brief do the organism behaviour if reach time.
	 *  \param dt delta time for doing the organism behaviour
	*/
	public abstract void update(float dt); // delta time in milliseconds
	/** \brief interaction between organism
	 *  \param organism which this organism will interact with
     */
	public abstract void interact(Organism);
	/** \brief kill the organism
     */
    public void forceKill() {
	    is_dead = true;
	    universe.board.DelEl(ch(),x,y);
	}

    protected void setX( int _x ) {
    	x = _x;
    }
    protected void setY( int _y ) {
    	y = _y;
    }
    protected void setCurrentAge( float age ) {
    	currentAge = age;
    }

};