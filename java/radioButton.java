import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class radioButton implements ActionListener {
	private JFrame mainFrame;
	private JLabel headerLabel;
	private JLabel jlab1;
	private JPanel controlPanel1,controlPanel2,controlPanel3;
	JRadioButton b1,b2,b3;
	ButtonGroup bg;
	JButton b4,b5,b6;
	
	public radioButton() {
		prepareGUI();	
	}
	private void prepareGUI() {
		mainFrame = new JFrame("RADIO BUTTON AND COLOR BUTTON");
		mainFrame.setSize(400,300);
		mainFrame.setLayout(new GridLayout(5,1));
		headerLabel = new JLabel("",JLabel.CENTER);
		
		b1 = new JRadioButton("Red   ");
		b1.addActionListener(this);
		b2 = new JRadioButton("Yellow");
		b2.addActionListener(this);
		b3 = new JRadioButton("Green ");
		b3.addActionListener(this);
		bg = new ButtonGroup();
		b4 = new JButton("Red");
		b4.setPreferredSize(new Dimension(120,30));
		b5 = new JButton("Yellow");
		b5.setPreferredSize(new Dimension(120,30));
		b6 = new JButton("Green");
		b6.setPreferredSize(new Dimension(120,30));
		bg.add(b1);
		bg.add(b2);
		bg.add(b3);
		
		jlab1 = new JLabel("Select a RadioButton",JLabel.CENTER);
		controlPanel1 = new JPanel();
		controlPanel2 = new JPanel();
		controlPanel3 = new JPanel();
		mainFrame.add(headerLabel);
		mainFrame.add(controlPanel1);
		mainFrame.add(controlPanel2);
		mainFrame.add(controlPanel3);
		mainFrame.add(jlab1);
			//mainFrame.setVisible(true);
		mainFrame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent WindowEvent) {
				System.exit(0);
			}});
	}
	
	private void showEvent() {
		headerLabel.setText("Control in action : JRadioButton");
		controlPanel1.setLayout(new FlowLayout(FlowLayout.CENTER));
		controlPanel1.add(b1);
		controlPanel1.add(b4);
		controlPanel2.setLayout(new FlowLayout(FlowLayout.CENTER));
		controlPanel2.add(b2);
		controlPanel2.add(b5);
		controlPanel3.setLayout(new FlowLayout(FlowLayout.CENTER));
		controlPanel3.add(b3);
		controlPanel3.add(b6);
		mainFrame.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		jlab1.setText("You selected "+e.getActionCommand());
		String command = e.getActionCommand();
		if(command.equals("Red   ")) {
			b4.setBackground(Color.RED);
			b4.setOpaque(true);
			b5.setBackground(null);
			b6.setBackground(null);
		}
		else if(command.equals("Yellow")) {
			b5.setBackground(Color.YELLOW);
			b5.setOpaque(true);
			b4.setBackground(null);
			b6.setBackground(null);
		}
		else if(command.equals("Green ")) {
			b6.setBackground(Color.GREEN);
			b6.setOpaque(true);
			b4.setBackground(null);
			b5.setBackground(null);
		}
	}
	public static void main(String args[]) {
		radioButton Demo = new radioButton();
		Demo.showEvent();
	}
}
