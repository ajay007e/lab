import java.io.*;
import java.util.Scanner;
class charStream {
	public static void main(String args[])throws IOException
	{
		int i;
		FileReader fin;
		FileWriter fout;
		try {
			// open input file
			try {
				fin = new FileReader(args[0]);
			} catch(FileNotFoundException e) {
				System.out.println("Input File Not Found");
				return;
			}

			// open output file
			try {
				fout = new FileWriter(args[1]);
			} catch(FileNotFoundException e) {
				System.out.println("Error Opening Output File");
				return;
			}
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Usage: CopyFile From To");
			return;
		}
		
		
		
		Scanner s = new Scanner(System.in);
		 
		for (int j = 0; j < 5; j++) {
			fout.write(s.nextLine());
			fout.write("\n");
		}
		
		// Copy File
		try {
			do {
				i = fin.read();
				if(i != -1) fout.write(i);
			} while(i != -1);
		} catch(IOException e) {
			System.out.println("File Error");
		}
		fin.close();
		fout.close();
		s.close();
	}
}