import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		int w,h;
		Scanner scanner = new Scanner(System.in);
		w = scanner.nextInt();
		h = scanner.nextInt();
		N = scanner.nextInt();
		
		Board b = new Board(w,h);
		Universe u = new Universe(b,N);
		OrganismFactory organismFactory = new OrganismFactory(u);
		organismFactory.CreateEagle(0,0);
		organismFactory.CreateHuman(1,1);
		
		while( true ){
			Thread.sleep(100);
			u.board.PrintBoard();
			u.update(100);
		}

	}
}