import java.util.Scanner;
import java.io.*;

class byteStream {
	public static void main(String args[])throws IOException
	{
		int i;
		FileInputStream fin;
		FileOutputStream fout;
		try {
			// open input file
			try {
				fin = new FileInputStream(args[0]);
			} catch(FileNotFoundException e) {
				System.out.println("Input File Not Found");
				return;
			}

			// open output file
			try {
				fout = new FileOutputStream(args[1]);
			} catch(FileNotFoundException e) {
				System.out.println("Error Opening Output File");
				return;
			}
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Usage: CopyFile From To");
			return;
		}
		
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fout));
		Scanner s = new Scanner(System.in);
		 
		for (int j = 0; j < 5; j++) {
			bw.write(s.nextLine());
			bw.newLine();
		}
		bw.close();
		
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
	}
}