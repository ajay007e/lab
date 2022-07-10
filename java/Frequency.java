import java.util.Scanner;

public class Frequency {
	public static void main(String arg[])
	{	
		System.out.println("Enter a string:");
		Scanner sc = new Scanner(System.in);
		String str=sc.nextLine();
		System.out.println("Enter the Charactor:");
		char ch = sc.nextLine().charAt(0);
		int f =0;
		for(int i=0;i<str.length();i++)
		{
			if(ch == str.charAt(i))
			{
				f++;
			}
		}
		System.out.println("Frequency of \""+ch +"\" is "+f);
	}
}
