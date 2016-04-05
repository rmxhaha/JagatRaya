public abstract class Universe {
  Universe(int m){
    maxOrganismPerCell = m;
  }
  public abstract void add(Organism o);
  public abstract void notifyMovement(Organism o);
  public abstract void update(float dt);
  public abstract void killWeakestOrganismAt(int x, int y);
  public abstract void addRace();
  protected int maxOrganismPerCell;

}
