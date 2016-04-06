/**
 * Horse class.
 * Horse can eat plants.
 */
public class Horse extends Herbivore{
    /** \brief Horse Constructor
     *
     * \param universe Universe it belong in
     * \return Horse
     *
     */
    public Horse(Universe u,int x,int y,float currentAge){
        super(u,x,y,currentAge);
        universe.board.SetEl(ch(),y,x);
    }
    /** \brief see Animal::update_logic
    */
    protected void update_logic(){
        //Update Horse move
        int prey_x = 0;
		int prey_y = 0;
		if(!findPrey('G',prey_x,prey_y,x,y)&&!findPrey('P',prey_x,prey_y,x,y)){
			move(goRandom());
		}
		else{
			move(goTo(prey_x,prey_y));
		}
    }
    /** \brief see Organism::ch
     */
    public char ch(){
        return 'H';
    }
    /** \brief see Organism::age
     */
    public int age(){
        return 30000;
    }
    /** \brief see Organism::power
     */
    public int power(){
        return 5;
    }
    /** \brief see Animal::speed
     */
    public float speed(){
        return 5.0f;
    }
    /** \brief see Organism::interact
     */
    public void interact(Organism O){
        if(O instanceof Grass){
            O.forceKill();
		}
    }
};
