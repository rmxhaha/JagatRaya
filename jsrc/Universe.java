class Universe {
    public Board board; // expose ?

    private Vector<Organism> mList;
    private Vector<Race> rList;
    private int maxOrganismPerCell;
    /** \brief Universe Constructor
     *  \param board board of the Universe simulation
     *  \param m maximum number of Organism per cell
     */
    public Universe(Board board, int m) throws Exception{
        board = b;
        maxOrganismPerCell = m;
        mList = (Vector<Organism>)new Vector();
        rList = (Vector<Race>)new Vector();
        if( maxOrganismPerCell < 1 ) throw new Exception("MaxOrganismPerCell must be more than 0");
    }

    /** \brief add new organism to this Universe
     *
     * \param m Organism* organism inside Universe
     * \return void
     *
     */
    public void add(Organism m) {
        mList.add(m);
        killWeakestOrganismAt(m.getX(), m.getY());
    }
    /** \brief notifyUniverse of a movement so Universe may notify to all organism where this notification is relevant
     *
     *  \param x the organism who moved
     *  \return
     */
    public void notifyMovement(Organism o) {
        killWeakestOrganismAt(o.getX(), o.getY());
        Vector<Organism> pool = mList.stream()
                                    .filter(it -> o.getX() == it.getX() && o.getY() == it.getY());
                                    .collect(toVector());

        for( Organism it: pool ){
            if( it == o ) continue;
            it.interact(o);
            if( o.isAlive())
                o.interact(it);
        }
    }

    /** \brief Update all Organism inside the universe
     *
     *  \param dt delta time from previous update
     *  \return void
     */
    public void update(float dt) {
        mList.stream()
            .filter(it -> it.isAlive())
            .forEach(it -> it.update(dt));

        rList.stream()
            .filter(it -> it.getState()!=RaceState::RACE_END)
            .forEach(it -> it.updateRace());
    }

    /** \brief kill the weakest organism in x,y coordinate if that cell exceed N limits per cell
     *
     *  \param x coordinate
     *  \param y coordinate
     *  \return void
     */
    public void killWeakestOrganismAt(int x, int y) {
        Vector<Organism> pool = mList.stream()
                                    .filter(it -> x == it.getX() && y == it.getY())
                                    .collect(toVector());

        // 1 for himself not counted
        while( pool.size() > maxOrganismPerCell ){
            // kill the weakest regardless of interaction
            Organism weakest = pool.firstElement();
            for( Organism it: pool)
            {
                if( it.power() < weakest.power() ){
                    weakest = it;
                }
            }
            weakest.forceKill();
            pool.remove(weakest);
        }
    }
    /** \brief notify all Rabbit and Turtle when a race is announced
     *
     *  \param sx starting coordinate
     *  \param sy starting coordinate
     *  \param ex finish coordinate
     *  \param ey finish coordinate
     *  \return void
     */
    public void addRace() {
        int sx = Math.rand() % board.GetH();
        int sy = Math.rand() % board.GetW();
        int ex = Math.rand() % board.GetH();
        int ey = sy;
        Race Ra = new Race(sx,sy,ex,ey);
        RList.add(Ra);
        mList.stream()
            .filter(it -> it instanceof Rabbit || it instanceof Turtle)
            .forEach(it -> it.triggerRace(Ra));
    }

};