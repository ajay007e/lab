import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;

class createFile
{
	public static void main(String args[])
	{
		int ch;
		FileReader fileRead = null;
		File file = new File("C:/Users/aj/Documents/newFIle.txt");
		try
		{
			boolean f = file.createNewFile();
			if(f)
				System.out.println("New File is created");
			else
				System.out.println("File already Exists");
			FileWriter newFile = new FileWriter("C:/Users/aj/Documents/newFIle.txt");
			newFile.write("New file content is created.");
			newFile.close();
			fileRead = new FileReader("C:/Users/aj/Documents/newFIle.txt");
			while((ch=fileRead.read())!=-1)
			{
				System.out.print((char)ch);
			}
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}