import java.util.Random;

public class OrganismFactory {
    private float currentAge;
    private Universe universe;
    private Random randomGenerator;

    OrganismFactory(Universe universe, float currentAge) {
        this.universe = universe;
        this.currentAge = currentAge;
        this.randomGenerator = new Random();
    }

    Organism CreateRandom() {
        int x = randomGenerator.nextInt(universe.board.GetW());
        int y = randomGenerator.nextInt(universe.board.GetH());

        return CreateRandomAt(x, y);
    }

    Organism CreateRandomAt(int x, int y) {
        Organism ox;
        switch (randomGenerator.nextInt(9) + 1) {
            case 1:
                ox = new Deer(universe, x, y, currentAge);
                break;
            case 2:
                ox = new Alien(universe, x, y, currentAge);
                break;
            case 3:
                ox = new Eagle(universe, x, y, currentAge);
                break;
            case 4:
                ox = new Grass(universe, x, y, currentAge);
                break;
            case 5:
                ox = new Human(universe, x, y, currentAge);
                break;
            case 6:
                ox = new Poison_Ivy(universe, x, y, currentAge);
                break;
            case 7:
                ox = new Tiger(universe, x, y, currentAge);
                break;
            case 8:
                ox = new Rabbit(universe, x, y, currentAge);
                break;
            case 9:
                ox = new Turtle(universe, x, y, currentAge);
                break;
            case 10:
                ox = new Horse(universe, x, y, currentAge);
                break;
            default:
                break;
        }

        universe.add(ox);
        return ox;
    }

    Organism CreateDeer(int x, int y) {
        Organism ox = new Deer(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateTiger(int x, int y) {
        Organism ox = new Tiger(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateAlien(int x, int y) {
        Organism ox = new Alien(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateEagle(int x, int y) {
        Organism ox = new Eagle(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateGrass(int x, int y) {
        Organism ox = new Grass(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateHuman(int x, int y) {
        Organism ox = new Human(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreatePoisonIvy(int x, int y) {
        Organism ox = new Poison_Ivy(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateTurtle(int x, int y) {
        Organism ox = new Turtle(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateRabbit(int x, int y) {
        Organism ox = new Rabbit(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }

    Organism CreateHorse(int x, int y) {
        Organism ox = new Horse(universe, x, y, currentAge);
        universe.add(ox);
        return ox;
    }
}
