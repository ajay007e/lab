import java.util.Scanner;

public class testAssignment2 {
	public static void main(String arg[]) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the size of numbers:");
		int n=s.nextInt();
		try {
			if(n<=0)
				throw new Exception();
		}
		catch(Exception w) {
			System.out.println(w);
		}
		int a[] = new int[n];
		if(n>0){
			System.out.print("Enter the numbers:");
			for(int i=0;i<n;i++){
				a[i] = s.nextInt();
			}
		}
	}
}