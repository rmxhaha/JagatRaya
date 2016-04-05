class Human : public Carnivore {
    private static int maxOffspring = 2;

    private int offspringCount;
    /** \brief Human Constructor
     *
     * \param universe Universe it belong in
     * \return Human
     *
     */
    public Human(Universe universe, int x, int y,float currentAge) {
        super();
    }
    /** \brief see Organism::ch
     */
    public char ch() { return 1; }
    /** \brief see Organism::age
     */
    public int age() { return 50000; }
    /** \brief see Organism::power
     */
    public int power() { return 1; }
    /** \brief see Animal::speed
     */
    public float speed() { return 3; }
    /** \brief see Organism::interact
     */
    public void interact(Organism o) {
        if( o instanceof Human ){
            if( offspringCount < Human::maxOffspring && o.offspringCount < Human::maxOffspring ){
                offspringCount ++;
                o.offspringCount ++;
                copulate();
            }
        }
    }


    /** Copulate wll generate new Human if 2 Human interact, copulate has limit to prevent overpopulation.
    */
    private void copulate() {
        Human h = new Human(universe, getX(), getY(),0);
        universe.add(h);
    }
    /** \brief see Animal::update_logic
    */
    private void update_logic() {
        move(goRandom());
    }
};