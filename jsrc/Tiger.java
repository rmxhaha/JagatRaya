/**
 * Tiger class.
 * Tiger will chase deer and horse.
 * Tiger can eat deer and horse.
 */
 
class Tiger extends Carnivore{
	/** \brief Tiger Constructor
	 *
	 * \param universe Universe it belong in
	 * \return Tiger
	 *
	 */
	public Tiger(Universe u,int x,int y,float currentAge){
		super(u, x, y, currentAge);
	}
	/** \brief see Animal::update_logic
	*/
	protected void update_logic(){
		int prey_x;
		int prey_y;
		if( findPrey('D',prey_x,prey_y,x,y)){
			move(goTo(prey_x,prey_y));
		}
		else if( findPrey('H',prey_x,prey_y,x,y)){
			move(goTo(prey_x,prey_y));
		}
		else {
			move(goRandom());
		}
	}
    /** \brief see Organism::ch
     */
    public char ch() { return 'T';}
    /** \brief see Organism::age
     */
	public int age() {return 30000;}
    /** \brief see Organism::power
     */
	public int power() { return 8;}
    /** \brief see Animal::speed
     */
    public float speed() { return 5;}
    /** \brief see Organism::interact
     */
    public void interact(Organism O){
		if(O instanceof Deer){
		O.forceKill();
		}
		else if(O instanceof Horse){
			O.forceKill();
		}
	}
};