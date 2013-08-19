import java.util.Scanner;

/**
 * SPOJ 1028 Hubulullu
 * @date 08/17/2013
 * @author Sherwin
 *
 */
public class Main {

	/**
	 * @param args
	 */
	static String[] player = {"Airborne", "Pagfloyd"};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t = 0;
		t = scan.nextInt();
		for (int i=0; i<t; i++)
		{
			int n = scan.nextInt();
			int who = scan.nextInt();
			System.out.println(player[who] + " wins.");
		}
	}

}
