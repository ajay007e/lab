import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class calculator implements ActionListener {
	private JFrame mainFrame;
	private JLabel headerLabel,footLabel,numLabel1,numLabel2,resultLabel;
	private JPanel controlPanel1,controlPanel2;
	JTextField t1,t2,t3;
	JButton plus,minus,multi,div;
	
	public calculator() {
		prepareGUI();
	}
	private void prepareGUI() {
		mainFrame = new JFrame("MY CalC");
		mainFrame.setSize(500,300);
		mainFrame.setLayout(new GridLayout(4,1));
		headerLabel = new JLabel("",JLabel.CENTER);
		
		numLabel1= new JLabel("Number 1: ", JLabel.RIGHT);
        	numLabel2 = new JLabel("Number 2: ", JLabel.CENTER);
		resultLabel = new JLabel("Result : ",JLabel.LEFT);
		t1 = new JTextField(6);
		t1.setPreferredSize(new Dimension(100,20));
		t2 = new JTextField(6);
		t2.setPreferredSize(new Dimension(100,20));
		t3 = new JTextField(6);
		t3.setPreferredSize(new Dimension(100,20));
		
		plus = new JButton("Add");
		plus.setPreferredSize(new Dimension(60,30));
		plus.addActionListener(this);
		minus = new JButton("Sub");
		minus.setPreferredSize(new Dimension(60,30));
		minus.addActionListener(this);
		multi = new JButton("Mul");
		multi.setPreferredSize(new Dimension(60,30));
		multi.addActionListener(this);
		div = new JButton("Div");
		div.setPreferredSize(new Dimension(60,30));
		div.addActionListener(this);

		footLabel = new JLabel("",JLabel.CENTER);		
		controlPanel1 = new JPanel();
		controlPanel2 = new JPanel();
		mainFrame.add(headerLabel);
		mainFrame.add(controlPanel1);
		mainFrame.add(controlPanel2);
		mainFrame.add(footLabel);
		
		mainFrame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent WindowEvent) {
				System.exit(0);
			}});	
	}
	
	private void showEvent() {
		controlPanel1.setLayout(new FlowLayout(FlowLayout.CENTER));
		controlPanel1.add(numLabel1);
		controlPanel1.add(t1);
		controlPanel1.add(numLabel2);
		controlPanel1.add(t2);
		controlPanel1.add(resultLabel);
		controlPanel1.add(t3);
		controlPanel2.setLayout(new FlowLayout(FlowLayout.CENTER));
		controlPanel2.add(plus);
		controlPanel2.add(minus);
		controlPanel2.add(multi);
		controlPanel2.add(div);
		mainFrame.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {  
        	String s1=t1.getText();  
        	String s2=t2.getText();  
        	int a=Integer.parseInt(s1);  
        	int b=Integer.parseInt(s2);  
        	int c=0;
        	
		headerLabel.setText("");
	    	footLabel.setText("");
        	if(e.getSource()==plus) {  
        	    c=a+b;
		    footLabel.setText(a+" + "+b+" = "+c); 
        	}
        	else if(e.getSource()==minus) {  
        	    c=a-b; 
		    footLabel.setText(a+" - "+b+" = "+c); 
        	}
        	else if(e.getSource()==multi){  
        	    c=a*b;  
		    footLabel.setText(a+" x "+b+" = "+c);
        	}
       		else if(e.getSource()==div && b!=0){  
            	    c=a/b;  
		    footLabel.setText(a+" / "+b+" = "+c);
        	}
		String result=String.valueOf(c); 
        	t3.setText(result);

		if(e.getSource()==div && b==0) {
	    		headerLabel.setText("ERROR..");
	    		footLabel.setText("Division with 0 is not defined"); 
        		t3.setText("");
        	}
	}

	public static void main(String args[]) {
		calculator Demo = new calculator();
		Demo.showEvent();
	}
}
