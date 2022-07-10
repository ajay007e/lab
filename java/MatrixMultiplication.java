import java.util.Scanner;

public class MatrixMultiplication {
	public static void main(String[] args)
	{
		int r1,c1,r2,c2,i,j,k;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter no. of rows in 1st Matrix:");
		r1 = s.nextInt();
		System.out.print("Enter no. of colunms in 1st Matrix:");
		c1 = s.nextInt();
		System.out.print("Enter no. of rows in 2st Matrix:");
		r2 = s.nextInt();
		System.out.print("Enter no. of colunms in 2st Matrix:");
		c2 = s.nextInt();
		if(c1 == r2)
		{
			int a[][] = new int[r1][c1];
			int b[][] = new int[r2][c2];
			int c[][] = new int[r1][c2];
			System.out.println("Enter all elements of 1st Matrix");
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					a[i][j] = s.nextInt();
				}
			}
			System.out.println("Enter all elements of 2st Matrix");
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					b[i][j] = s.nextInt();
				}
			}
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					for(k=0;k<r2;k++)
					{
						c[i][j] += a[i][k] * b[k][j];
					}
				}
			}
			System.out.println("1st Matrix");
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					System.out.print(a[i][j]+"  ");
				}
				System.out.println();
			}
			System.out.println("2st Matrix");
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					System.out.print(b[i][j]+"  ");
				}
				System.out.println();
			}
			System.out.println("Result Matrix");
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					System.out.print(c[i][j]+"  ");
				}
				System.out.println();
			}
		}
		else
		{
			System.out.println("Multiplication is not possible");
		}
	}

}
