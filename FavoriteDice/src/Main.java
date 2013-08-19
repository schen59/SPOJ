import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * 
 */

/**
 * SPOJ 1026 Favorite Dice
 * @date 08/18/2013
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
		int t = scanner.nextInt();
		for (int i=0; i<t; i++)
		{
			int n = scanner.nextInt();
			double res = 0;
			for (int k=1; k<=n; k++)
			{
				res += n/(double)k;
			}
			BigDecimal b = new BigDecimal(res);  
		    b = b.setScale(2, BigDecimal.ROUND_CEILING); 
			System.out.println(b);
		}
	}

}
