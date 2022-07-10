import java.util.Scanner;

abstract class Shape
{
	abstract void numberOfSides();
}
class Rectangle extends Shape
{
	void numberOfSides()
	{
		System.out.println("Number of sides of the rectangle is 4.");
	}
}
class Triangle extends Shape
{
	void numberOfSides()
	{
		System.out.println("Number of sides of the triangle is 3.");
	}
}
class Hexagon extends Shape
{
	void numberOfSides()
	{
		System.out.println("Number of sides of the hexagon is 6.");
	}
}

public class NumberOfSides {
	public static void main(String arg[]){
		System.out.println("Select Shape\n1.Hexagon\n2.Rectangle\n3.Triangle");
		int q;
		Shape ob;
		Scanner s = new Scanner(System.in);
		q = s.nextInt();
		switch(q)
		{
			case 1:
				ob = new Hexagon();
				ob.numberOfSides();
				break;
			case 2:
				ob = new Rectangle();
				ob.numberOfSides();
				break;
			case 3:
				ob = new Triangle();
				ob.numberOfSides();
				break;
			default:
				System.out.print("Invalid");
		}
	}
}
