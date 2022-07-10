class MTable{
	synchronized void printTable(int x) {
		for(int i = 1 ; i<11 ; i++)
			System.out.println(i+"x"+x+"="+i*x);
		System.out.println();
	}
}

class Thread1 extends Thread{  
	MTable t;
	Thread1(MTable t){
		this.t =t;
	}
	public void run(){  
		t.printTable(10);
	}
}

class Thread2 extends Thread{  
	MTable t;
	Thread2(MTable t){
		this.t =t;
	}
	public void run(){  
		t.printTable(5);
	}
}

public class Synchronization {
	public static void main(String arg[]) {
	MTable t = new MTable();
	Thread1 t1 = new Thread1(t);
	Thread2 t2 = new Thread2(t);
	t1.start();
	t2.start();
	}
}
