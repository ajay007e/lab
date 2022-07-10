import java.util.Scanner;
 
abstract class Person
{  
  String name; 
  int age; 
  int phonenumber; 
  String address;  
  Person(String name1,int age1) 
  { 
    name=name1; 
    age=age1; 
  } 
  abstract void display();  
} 
 
class Employee extends Person
{ 
  double salary; 
  Employee(String name1,int age1,int phone1,String address1,double salary1) 
  {  
     super(name1,age1);  
     phonenumber=phone1; 
     address=address1; 
     salary=salary1; 
  }  
  void printSal()
  { 
    System.out.println(salary); 
  }  
   void display() 
   { 
     System.out.println(name);
   } 
}  
 
class Researcher extends Employee
{  
  String specialization ; 
   Researcher(String name1,int age1,int phone1,String address1,double salary1,String specialization1) 
   {  
     super(name1,age1,phone1,address1,salary1);  
     specialization=specialization1; 
   }  
  void display() 
  { 
    System.out.println(name+" " + age + " " + phonenumber+" "+address + " " + specialization); 
  } 
} 
 
class HOD extends Employee
{  
  String department ;  
   HOD(String name1,int age1,int phone1,String address1,double salary1,String department1) 
   {  
     super(name1,age1,phone1,address1,salary1);  
     department=department1; 
   }  
  void display() 
  { 
    System.out.println(name+" " + age + " " + phonenumber+" "+address + " " + department); 
  } 
} 

 
  

 
class Inherit { 
public static void main(String args[]) { 
  Researcher[] r = new Researcher[5];
  HOD[] h = new HOD[5];
  Scanner in = new Scanner(System.in);
  int m=0,num,n,i,age,mob;
  double sal;
  String name,adr,ex;
  for(i=0;i<5;i++)
  {
    System.out.print("Name of HOD "+(i+1)+":");
    name = in.next();
    System.out.print("Age of HOD "+(i+1)+":");
    age = in.nextInt();
    System.out.print("Phone Number of HOD "+(i+1)+":");
    mob = in.nextInt();
    System.out.print("Address of HOD "+(i+1)+":");
    adr = in.next();
    System.out.print("Salary of HOD "+(i+1)+":");
    sal = in.nextDouble();
    System.out.print("Department of HOD "+(i+1)+":");
    ex = in.next();
    h[i] = new HOD(name,age,mob,adr,sal,ex); 
  }
  for(i=0;i<5;i++)
  {
    System.out.print("Name of Researcher "+(i+1)+":");
    name = in.next();
    System.out.print("Age of Researcher "+(i+1)+":");
    age = in.nextInt();
    System.out.print("Phone Number of Researcher "+(i+1)+":");
    mob = in.nextInt();
    System.out.print("Address of Researcher "+(i+1)+":");
    adr = in.next();
    System.out.print("Salary of Researcher "+(i+1)+":");
    sal = in.nextDouble();
    System.out.print("Department of Researcher "+(i+1)+":");
    ex = in.next();
    r[i] = new Researcher(name,age,mob,adr,sal,ex); 
  }
  while(m==0)
    {
      System.out.println("1 for Researcher \n2 for HOD ");
      num = in.nextInt();
      switch(num){
        case 1:
          System.out.print("Which Researcher you need :");
          n = in.nextInt();
          System.out.println("\nDetails"); 
          r[n-1].display(); 
          System.out.print("Salary of "+ r[n-1].name +" is "); 
          r[n-1].printSal(); 
          System.out.println();
          break;
        case 2:
          System.out.print("Which HOD you need :");
          n = in.nextInt();
          System.out.println("\nDetails"); 
          h[n-1].display(); 
          System.out.print("Salary of "+ h[n-1].name +" is "); 
          h[n-1].printSal(); 
          System.out.println();
          break;
        default :
          System.out.println("Invalid");
      }
      System.out.println("Do you want to continue ?\n Press 1 to Exit \n Press 0 to Continue");
      m = in.nextInt();
    } 
  } 
}