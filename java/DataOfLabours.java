class Employee
{
	String name,address;
	int age,salary;
	long mob;
	
	void printSalary()
	{
		System.out.println(salary+"\n");
	}
	
}

class Manager extends Employee
{
	String dept;
	Manager(String name,int age,long mob,String address,int salary,String dept)
	{
		this.salary = salary;
		System.out.println("Name:"+name+"\nAge:"+age+"\nMobile:"+mob+"\nAddress:"+address+"\nDepartment:"+dept);
	}
}

class Officer extends Employee
{
	String spec;
	Officer(String name,int age,long mob,String address,int salary,String spec)
	{
		this.salary = salary;
		System.out.println("Name:"+name+"\nAge:"+age+"\nMobile:"+mob+"\nAddress:"+address+"\nSpecialization:"+spec);
	}
}
public class DataOfLabours {
	public static void main(String arg[])
	{
		Manager mg = new Manager("Ajay Mathew",20,8547769897L,"Edathazhe House",25000,"CSE");
		System.out.print("Salary of the Manager is ");
		mg.printSalary();
		Officer of = new Officer("Ajay Mathew",20,8547769897L,"Edathazhe House",25000,"Java Developer");
		System.out.print("Salary of the Officer is ");
		of.printSalary();
	}
}
