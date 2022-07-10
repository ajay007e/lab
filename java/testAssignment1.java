import java.util.Scanner;

public class testAssignment1 {
	public static void main(String arg[]) {
		int i,e;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the internal mark:");
		i=s.nextInt();
		System.out.print("Enter the external mark:");
		e=s.nextInt();
		try {
			if(i>40 || e>60)
				throw new Exception();
		}
		catch(Exception w) {
			System.out.println(w);
		}
	}
}