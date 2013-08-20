import java.util.Scanner;

/**
 * 
 */

/**
 * SPOJ 1419 A Game With Numbers
 * @date 08/19/2013
 * @author Sherwin
 *
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		if (n % 10 != 0)
		{
			System.out.println("1");
			System.out.println(n % 10);
		}
		else
		{
			System.out.println("2");
		}
	}

}
