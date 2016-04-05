
class Organism {
  protected float cAge;
  protected boolean is_dead;
  protected int x,y;
  //protected Universe universe;

  public int getX(){
    return x;
  }
  public int getY(){
    return y;
  }

  Organism(int x, int y, float currentAge){
    this.x = x;
    this.y = y;
    this.cAge = currentAge;
  }

};
