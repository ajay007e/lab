import java.util.Scanner;

public class transpose {
	public static void main(String arg[]) {
		int r,c,i,j;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of rows of the matrix : ");
		r = sc.nextInt();
		System.out.print("Enter the number of columns of the matrix : ");
		c = sc.nextInt();
		int a[][] = new int[r][c];
		int b[][] = new int[c][r];
		
		System.out.println("Enter all elements of Matrix ->");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				a[i][j] = sc.nextInt();
			}
		}
		
		for(i=0;i<c;i++)
		{
			for(j=0;j<r;j++)
			{
				b[i][j] = a[j][i];
			}
		}
		
		
		System.out.println("\nOriginal Matrix\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				System.out.print(a[i][j]+"  ");
			}
			System.out.println();
		}
		
		System.out.println("\nTranspose Matrix\n");
		for(i=0;i<c;i++)
		{
			for(j=0;j<r;j++)
			{
				System.out.print(b[i][j]+"  ");
			}
			System.out.println();
		}
		
	}
}