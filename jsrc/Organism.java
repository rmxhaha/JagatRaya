
public abstract class Organism {
  protected float cAge;
  protected boolean is_dead;
  protected int x,y;
  //protected Universe universe;

  public Organism(int x, int y, float currentAge){
    this.x = x;
    this.y = y;

    cAge = currentAge;
    is_dead = false;
  }
  public int getX(){
    return x;
  }
  public int getY(){
    return y;
  }
  protected void setX(int _x){
    x=_x;
  }
  protected void setY(int _y){
    y=_y;
  }
  protected void setCurrentAge(float age){
    cAge = age;
  }
  public abstract char ch();
  public abstract int age();
  public abstract int power();
  public abstract void update(float dt);
  public abstract void interact(Organism pair);
  public void forceKill(){
    is_dead = true;
  }

};
