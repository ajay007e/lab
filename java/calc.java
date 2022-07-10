import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class calc implements ActionListener{

	private JFrame frame;
	private JTextField textField;
	JButton one,two,three,four,five,six,seven,eight,nine,zero,plus,minus,multi,div,deci,equal,del,clr;
	
	double a=0,b=0,result=0;
	int operator=0;
	
	public calc() {
		prepareGUI();
	}
	
	private void prepareGUI() {
		frame = new JFrame("CALCULATOR");
		textField = new JTextField();
		
		one = new JButton("1");
		two = new JButton("2");
		three =new JButton("3");
		four = new JButton("4");
		five = new JButton("5");
		six = new JButton("6");
		seven = new JButton("7");
		eight = new JButton("8");
		nine = new JButton("9");
		zero = new JButton("0");
		
		plus = new JButton("+");
		minus = new JButton("-");
		multi = new JButton("x");
		div = new JButton("/");
		equal = new JButton("=");
		
		deci = new JButton(".");
		del = new JButton("del");
		clr = new JButton("C");
		
		textField.setBounds(30,40,280,30);
		seven.setBounds(40,100,50,40);
		eight.setBounds(110,100,50,40);
		nine.setBounds(180,100,50,40);
		plus.setBounds(250,100,50,40);
		
		four.setBounds(40,170,50,40);
		five.setBounds(110,170,50,40);
		six.setBounds(180,170,50,40);
		minus.setBounds(250,170,50,40);
		
		one.setBounds(40,240,50,40);
		two.setBounds(110,240,50,40);
		three.setBounds(180,240,50,40);
		multi.setBounds(250,240,50,40);
		
		zero.setBounds(40,310,50,40);
		deci.setBounds(110,310,50,40);
		equal.setBounds(180,310,50,40);
		div.setBounds(250,310,50,40);
		
		del.setBounds(60,380,100,40);
		clr.setBounds(180,380,100,40);
		
		frame.add(textField);
		frame.add(seven);
		frame.add(eight);
		frame.add(nine);
		frame.add(plus);
		frame.add(four);
		frame.add(five);
		frame.add(six);
		frame.add(minus);
		frame.add(one);
		frame.add(two);
		frame.add(three);
		frame.add(multi);
		frame.add(zero);
		frame.add(deci);
		frame.add(equal);
		frame.add(div);
		frame.add(del);
		frame.add(clr);
		
		frame.setLayout(null);
		frame.setSize(350,500);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		
		one.addActionListener(this);
		two.addActionListener(this);
		three.addActionListener(this);
		four.addActionListener(this);
		five.addActionListener(this);
		six.addActionListener(this);
		seven.addActionListener(this);
		eight.addActionListener(this);
		nine.addActionListener(this);
		zero.addActionListener(this);
		plus.addActionListener(this);
		minus.addActionListener(this);
		multi.addActionListener(this);
		div.addActionListener(this);
		deci.addActionListener(this);
		equal.addActionListener(this);
		del.addActionListener(this);
		clr.addActionListener(this);
		
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==one)
			textField.setText(textField.getText().concat("1"));
		
		if(e.getSource()==two)
			textField.setText(textField.getText().concat("2"));
		
		if(e.getSource()==three)
			textField.setText(textField.getText().concat("3"));
		
		if(e.getSource()==four)
			textField.setText(textField.getText().concat("4"));
		
		if(e.getSource()==five)
			textField.setText(textField.getText().concat("5"));
		
		if(e.getSource()==six)
			textField.setText(textField.getText().concat("6"));
		
		if(e.getSource()==seven)
			textField.setText(textField.getText().concat("7"));
		
		if(e.getSource()==eight)
			textField.setText(textField.getText().concat("8"));
	
		if(e.getSource()==nine)
			textField.setText(textField.getText().concat("9"));
		
		if(e.getSource()==zero)
			textField.setText(textField.getText().concat("0"));
		
		if(e.getSource()==deci)
			textField.setText(textField.getText().concat("."));
		
		if(e.getSource()==plus)
		{
			a=Double.parseDouble(textField.getText());
			operator=1;
			textField.setText("");
		} 
		
		if(e.getSource()==minus)
		{
			a=Double.parseDouble(textField.getText());
			operator=2;
			textField.setText("");
		}
		
		if(e.getSource()==multi)
		{
			a=Double.parseDouble(textField.getText());
			operator=3;
			textField.setText("");
		}
		
		if(e.getSource()==div)
		{
			a=Double.parseDouble(textField.getText());
			operator=4;
			textField.setText("");
		}
		
		if(e.getSource()==equal)
		{
			b=Double.parseDouble(textField.getText());
		
			switch(operator)
			{
				case 1: result=a+b;
					break;
		
				case 2: result=a-b;
					break;
		
				case 3: result=a*b;
					break;
		
				case 4: result=a/b;
					break;
		
				default: result=0;
			}
		
			textField.setText(""+result);
		}
		
		if(e.getSource()==clr)
			textField.setText("");
		
		if(e.getSource()==del)
		{
			String s=textField.getText();
			textField.setText("");
			for(int i=0;i<s.length()-1;i++)
			textField.setText(textField.getText()+s.charAt(i));
		}		
	}
	
	public static void main(String args[])
	{
		new calc();
	}
	
	
}
