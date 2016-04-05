/**
 * Deer class.
 * Deer can eat plants.
 * Deer can avoid tiger if tiger is near. Deer will look for other deer if tiger is far.
 */
class Deer:public Herbivore{
	/** \brief Deer Constructor
     *
     * \param universe Universe it belong in
     * \return Deer
     *
     */
	public Deer(Universe u,int x,int y,float currentAge){
		super();
	}
	/** \brief see Animal::update_logic
	*/ 
	private void update_logic(){
		int prey_x;
		int prey_y;
		if(findPrey('T',prey_x,prey_y,x,y)){
			move(avoid(prey_x,prey_y));
		}
		else{
			if(findPrey('D',prey_x,prey_y,x,y)){
				move(goTo(prey_x,prey_y));
			}
			else{
				move(goRandom());
			}
		}
	}
    /** \brief see Organism::ch
     */
    public char ch(){ return 'D';}
    /** \brief see Organism::age
     */
	public int age() { return 30000;}
    /** \brief see Organism::power
     */
	public int power(){ return 5;}
    /** \brief see Animal::speed
     */
    public float speed(){ return 5;}
    /** \brief see Organism::interact
     */
    public void interact(Organism O){
		if(O instanceof Grass){
		O.forceKill();
		}
	}
};