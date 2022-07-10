class Three extends Thread
{
	public void run()
	{

		System.out.println("\nMultiples of 3");
		for(int i = 3;i<1000;i+=3)
		{
			System.out.println(i);
		}
	}
}

class Two extends Thread
{
	public void run()
	{	
		System.out.println("\nMultiples of 2");
		for(int i = 2;i<1000;i+=2)
		{
			System.out.println(i);
		}
	}
}

public class ThreadDemo 
{
	public static void main(String arg[]) {
		Three ob1 = new Three();
		Two ob2 = new Two();
		
		ob2.start();
		try
        	{ 
           		ob2.join(); 
       		}
		catch(Exception ex) 
        	{ 
            		System.out.println("Exception has been caught" + ex); 
        	}  
		ob1.start();
		try
        	{ 
           		ob1.join(); 
       		}
		catch(Exception ex) 
        	{ 
            		System.out.println("Exception has been caught" + ex); 
        	}  
	
	}
}
