import java.math.BigInteger;
import java.util.Scanner;

/**
 * SPOJ 1030 Tripple Fat Ladies
 */

/**
 * @author Sherwin
 *
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for (int i=0; i<t; i++)
		{
			BigInteger k = scan.nextBigInteger();
			System.out.println(k.subtract(BigInteger.valueOf(1)).multiply(BigInteger.valueOf(250)).add(BigInteger.valueOf(192)));
		}
	}

}
