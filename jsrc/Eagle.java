class Eagle : public Carnivore {
	/** \brief Eagle Constructor
     *
     * \param universe Universe it belong in
     * \return Eagle
     *
     */
	public Eagle(Universe u,int x, int y,float currentAge){
		super();
	}
    /** \brief see Organism::ch
     */
    public char ch() {return 'E';}
    /** \brief see Organism::age
     */
	public int age() {return 30000;}
    /** \brief see Organism::power
     */
	public int power() { return 5;}
    /** \brief see Animal::speed
     */
    public float speed() { return 7;}
    /** \brief see Organism::interact
     */
    public void interact(Organism O){
		if(O instanceof Turtle){
		O.forceKill();
		}
		if(O instanceof Rabbit){
		O.forceKill();
		}
	}
	/** \brief see Animal::update_logic
	*/
	private void update_logic(){
		if(y==0 && x!=universe.board.GetW()-1){
		move(direction_t::RIGHT);
		}
		else if(y==universe.board.GetH()-1 && x!=0){
			move(direction_t::LEFT);
		}
		else{
			if(x==0){
				move(direction_t::DOWN);
			}
			else if(x==universe.board.GetW()-1){
				move(direction_t::UP);
			}
			else{
				move(direction_t::LEFT);
			}
		}
	}
};