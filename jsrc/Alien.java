/**
 * Alien class.
 * Alien will kill everything in it's way. Alien have the highest speed.
 */
class Alien extends Carnivore{
	/** \brief Alien Constructor
     *
     * \param universe Universe it belong in
     * \return Alien
     *
     */
	public Alien(Universe u,int x, int y,float currentAge){
		super();
	}
	/** \brief see Animal::update_logic
	*/
	protected void update_logic(){
		int prey_x;
		int prey_y;
		if(!find(prey_x,prey_y,x,y)){
			move(goRandom());
		}
		else{
			move(goTo(prey_x,prey_y));
		}
	}
	/** \brief find the nearest organism from the alien
	 * 	\param prey_x, prey_y Location of the prey
	 * 	\param predator_x,predator_y Location of the alien
	*/
	public bool find(int prey_x,int prey_y,int predator_x,int predator_y){
		Vector<Target> vec;
		Board board = universe->board;
		int i = 0;
		int j;
		Target T;

		while(i<board.GetH()){
			j=0;
			while(j<board.GetW()){
				if(board.GetEl(i,j).length()>0){
					T.x = i;
					T.y = j;
					T.distance = (predator_x-T.x)*(predator_x-T.x) + (predator_y-T.y)*(predator_y-T.y);
					vec.push_back(T);
				}
				j++;
			}
			i++;
		}
		if(vec.size()>0){
			int min;
			if(vec[0].x!=x && vec[0].y){
				min = vec[0].distance;
				prey_x=vec[0].x;
				prey_y=vec[0].y;
				i=1;
			}
			else{
				min = vec[1].distance;
				prey_x=vec[1].x;
				prey_y=vec[1].y;
				i=2;
			}
			while(i<vec.size()){
				if(vec[i].distance<min && vec[i].x!=x && vec[i].y!=y){
					prey_x=vec[i].x;
					prey_y=vec[i].y;
				}
				i++;
			}
			return true;
		}
		else{
			return false;
		}
	}
    /** \brief see Organism::ch
     */
    public char ch() {return '@';}
    /** \brief see Organism::age
     */
	public int age() {return 3;}
    /** \brief see Organism::power
     */
	public int power() {return 50;}
    /** \brief see Animal::speed
     */
    public float speed(){return 50000;}
    /** \brief see Organism::interact
     */
    public void interact(Organism O){
		O.forceKill();
	}
};