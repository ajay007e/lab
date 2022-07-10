import java.util.Scanner;

public class palindrome 
{
	public static void main(String arg[]) 
	{
		String str,rev="";
		Scanner s =new Scanner(System.in);
		System.out.println("Enter the String:");
		str =s.nextLine();
		int n=str.length();
		for(int i=n-1;i>=0;i--)
		{
			rev = rev + str.charAt(i);
		}
		if(str.equals(rev))
		{
			System.out.println(str +" is Palindrome");
		}
		else
		{
			System.out.println(str +" is not Palindrome");
		}
	}
	

}
