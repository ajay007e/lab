import java.util.Scanner;
import java.lang.*;

class Shapes
{
	double area,v1,v2,v3,p;
	
	void area(double v1)
	{
		this.v1 =v1;
		area = (22.0/7.0)*v1*v1;
		System.out.println("Area of the Circle is "+area);
	}
	void area(double v1,double v2)
	{
		this.v1 = v1;
		this.v2 = v2;
		area = v1*v2;
		System.out.println("Area of the Rectangle is "+area);
	}
	void area(double v1,double v2,double v3)
	{
		this.v1 = v1;
		this.v2 = v2;
		this.v3 = v3;
		p = (v1+v2+v3)/2 ; 
        area = Math.sqrt((p-v1)*(p-v2)*(p-v3)*p);
        System.out.println("Area of the Triangle is "+area);
	}
}

public class AreaOfShape {
	public static void main(String arg[]){
		System.out.println("To Calculate the Area of Shape\nEnter :1.Circle\n       2.Rectangle\n       3.Triangle");
		int q;
		double v1,v2,v3;
		Shapes ob = new Shapes();
		Scanner s = new Scanner(System.in);
		q = s.nextInt();
		switch(q)
		{
			case 1:
				System.out.println("Radious of the Circle:");
				v1 = s.nextDouble();
				ob.area(v1);
				break;
			case 2:
				System.out.println("Side of Rectangle:");
				v1 = s.nextDouble();
				v2 = s.nextDouble();
				ob.area(v1,v2);
				break;
			case 3:
				System.out.println("Sides of Triangle:");
				v1 = s.nextDouble();
				v2 = s.nextDouble();
				v3 = s.nextDouble();
				ob.area(v1,v2,v3);
				break;
			default:
				System.out.print("Invalid");
		}
	}
}
