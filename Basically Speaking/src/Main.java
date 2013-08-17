/**
 * SPOJ 870 Basically Speaking
 * Author: Shaofeng Chen
 * Date: 08/16/2013
 */

import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Main bs = new Main();
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext())
		{
			String[] line = scan.nextLine().trim().split("\\s+");
			String rawNumber = line[0];
			int fromBase = Integer.parseInt(line[1]);
			int toBase = Integer.parseInt(line[2]);
			int base10 = bs.convertToBase10(rawNumber, fromBase);
			String anyBase = bs.convertToAnyBase(base10, toBase);
			if (anyBase.length() > 7)
			{
				System.out.println("  ERROR");
			}
			else
			{
				for (int i=0; i<7-anyBase.length(); i++)
				{
					System.out.print(" ");
				}
				System.out.println(anyBase);
			}
 		}
	}
	
	public int convertToBase10(String number, int base)
	{
		int base10  = 0;
		char[] numberChars = number.toCharArray();
		for (int i=0; i<numberChars.length; i++)
		{
			char c = numberChars[i];
			if (c>='0' && c<='9')
			{
				base10 = base10 * base + c-'0';
			}
			else
			{
				base10 = base10 * base + c-'A' + 10;
			}
		}
		return base10;
	}
	
	public String convertToAnyBase(int number, int base)
	{
		StringBuilder sb = new StringBuilder();
		while (number > 0)
		{
			int remainder = number % base;
			if (remainder < 10)
			{
				sb.append(remainder);
			}
			else
			{
				char c = (char) ('A' + remainder - 10);
				sb.append(c);
			}
			number /= base;
		}
		return sb.reverse().toString();
	}
}
