/**
 * SPOJ 1025 Fashion Shows
 * Author: Shaofeng Chen
 * Date: 08/17/2013
 */
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t = 0;
		int shows = 0;
		int i = 0;
		int j = 0;
		t = scan.nextInt();
		for (i=0; i<t; i++)
		{
			shows = scan.nextInt();
			int[] men = new int[shows];
			int[] women = new int[shows];
			for (j=0; j<shows; j++)
			{
				men[j] = scan.nextInt();
			}
			for (j=0; j<shows; j++)
			{
				women[j] = scan.nextInt();
			}
			Arrays.sort(men);
			Arrays.sort(women);
			int bonds = 0;
			for (j=0; j<shows; j++)
			{
				bonds += men[j]*women[j];
			}
			System.out.println(bonds);
		}
	}

}
