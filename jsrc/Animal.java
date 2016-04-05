abstract class Animal extends Organism {
    protected float timebuffer;
	/** \brief Animal Constructor
     *
     * \param universe Universe it belong in
     * \return Animal
     *
     */
	public Animal(Universe u, int x, int y,float currentAge) {
		super();
		timebuffer = 0.0;
	}
	/** \brief speed of animal for moving
	* 	\return float
	*/
	public abstract float speed();
	/** \brief Time buffer of the animal
	 * 	\return float
	*/
    public float getTimebuffer() {
    	return timebuffer;
    }
	/** \brief do the animal behaviour if reach time.
	 *  \param dt delta time for doing the animal behaviour 
	*/
    public void update(float dt) {
    	Organism.update(dt);
    	if (isDead()) {
    		return;
    	}
    	float d = 1000/speed();
	    timebuffer += dt;

	    while( timebuffer > d ){
	        update_logic();
	        timebuffer -= d;
	    }
    }

	/** \brief find the direction where animal should move to, if the animal want to run from its predator.
	 * 	\param x,y Location of the thing animal should avoid
	 * 	\return direction_t
	*/
	protected direction_t avoid(int x, int y) {
		if( tx < x ){ // run right
	        if( ty < y ) // run up
	            return direction_t.UP_RIGHT;
	        if( ty > y ) // run down
	            return direction_t.DOWN_RIGHT;
	        return direction_t.RIGHT;
	    }
	    if( x < tx ){ // run left
	        if( ty < y ) // run up
	            return direction_t.UP_LEFT;
	        if( ty > y ) // run down
	            return direction_t.DOWN_LEFT;
	        return direction_t.LEFT;
	    }
	    if( ty < y ) // run up
	        return direction_t.UP;
	    if( ty > y ) // run down
	        return direction_t.DOWN;
	    // on the same coor
	    return direction_t.UP_LEFT;
	}
	/** \brief find the direction where animal should move to, if the animal want to go to its prey / herd.
	 * 	\param x,y Location of the thing animal should go to.
	 * 	\return direction_t
	*/
	protected direction_t goTo(int x, int y) {
		if( tx > x ){ // run right
	        if( ty > y ) // run up
	            return direction_t.UP_RIGHT;
	        if( ty < y ) // run down
	            return direction_t.DOWN_RIGHT;
	        return direction_t.RIGHT;
	    }
	    if( x > tx ){ // run left
	        if( ty > y ) // run up
	            return direction_t.UP_LEFT;
	        if( ty < y ) // run down
	            return direction_t.DOWN_LEFT;
	        return direction_t.LEFT;
	    }
	    if( ty > y ) // run up
	        return direction_t.UP;
	    if( ty < y ) // run down
	        return direction_t.DOWN;
	    return direction_t.NO_WHERE;
	}
	/** \brief return random direction.
	 * 	\return direction_t
	*/
	protected direction_t goRandom() {
		int d = Math.rand() % 8;
	    switch(d){
	    case 0: return direction_t.UP;
	    case 1: return direction_t.DOWN;
	    case 2: return direction_t.LEFT;
	    case 3: return direction_t.RIGHT;
	    case 4: return direction_t.UP_LEFT;
	    case 5: return direction_t.UP_RIGHT;
	    case 6: return direction_t.DOWN_LEFT;
	    case 7: return direction_t.DOWN_RIGHT;
	    default : return direction_t.UP;
	    }
	}
	/** \brief find the nearest target from the Animal
	 *  \param prey_ch symbol of the target
	 * 	\param prey_x, prey_y Location of the prey
	 * 	\param predator_x,predator_y Location of the Animal
	*/
	protected boolean findPrey(char prey_ch,int & prey_x,int & prey_y,int predator_x,int predator_y) {
		Board board = universe.board;
	    int closest_prey = 1000000000;
	    boolean prey_found = false;
	    prey_x = predator_x;
	    prey_y = predator_y;

	    for( int x = 0; x < board.GetW(); ++ x ){
	        for( int y = 0; y < board.GetH(); ++ y ){
	            if( board.GetEl(y,x).find(prey_ch) != string::npos){
	                prey_found = true;
	                int dx = predator_x - x;
	                int dy = predator_y - y;
	                if( closest_prey > dx*dx+dy*dy )
	                {
	                    closest_prey = dx*dx+dy*dy;
	                    prey_x = x;
	                    prey_y = y;
	                }
	            }
	        }
	    }
	    return prey_found;
	}
	/** \brief move to the direction
	 *  \param direction direction where the animal should move to
	*/
	protected void move(direction_t direction) {
		int dx = 0, dy = 0;

	    switch( direction ){
		case direction_t.NO_WHERE:      break;
		case direction_t.UP:        dy = 1; break;
		case direction_t.DOWN:      dy = -1; break;
		case direction_t.LEFT:      dx = -1; break;
		case direction_t.RIGHT:     dx = 1; break;
		case direction_t.UP_LEFT:   dy = 1; dx = -1; break;
		case direction_t.DOWN_LEFT: dy = -1; dx = -1; break;
		case direction_t.UP_RIGHT:  dy = 1; dx = 1; break;
		case direction_t.DOWN_RIGHT: dy = -1; dx = 1; break;
	    }


	    // plus GetW getH is for negative number mod
	    int tx = x + dx;
	    int ty = y + dy;

	    if( tx >= universe.board.GetW() )
	        tx = universe.board.GetW() - 1;
	    else if( tx < 0 )
	        tx = 0;

	    if( ty >= universe.board.GetH() )
	        ty = universe.board.GetH() - 1;
	    else if( ty < 0 )
	        ty = 0;


	    // update The board here


	    if( x == tx && y == ty ) return;

	    universe.board.DelEl(ch(),y,x);
	    universe.board.SetEl(ch(),ty,tx);
	    x = tx;
	    y = ty;
	    universe.notifyMovement(this);
	}
    /** \brief behaviour of the animal
	*/
	protected abstract void update_logic();

}