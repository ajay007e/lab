import java.util.*;

public class Sum {
	public static void main(String[] args)
	{
		int n;
		int sum = 0;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter integers with one space gap:");
		String str = s.nextLine();
		StringTokenizer st = new StringTokenizer(str," ");
		while(st.hasMoreTokens())
		{
			String temp = st.nextToken();
			n = Integer.parseInt(temp);
			System.out.print(n+"  ");
			sum += n;
		}
		System.out.println();
		System.out.print("Sum of integers is "+sum);
		s.close();
	}
}
