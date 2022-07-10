import java.awt.*;
import java.awt.event.*;

public class AwtControlDemo3{

   public Frame mainFrame;
   private Label headerLabel;
   private Label statusLabel;
   private Panel controlPanel;
	Button RButton;
	Button YButton;
	Button BButton;
	Button GButton;
   public AwtControlDemo3(){
      prepareGUI();
   }

   public static void main(String[] args){
      AwtControlDemo3 awtControlDemo = new AwtControlDemo3();
      awtControlDemo.showEventDemo();
   }

   private void prepareGUI(){
      mainFrame = new Frame("Java AWT Examples");
      mainFrame.setSize(400,400);
      mainFrame.setLayout(new GridLayout(3, 1));
      //mainFrame.setBackground(Color.RED);
      mainFrame.addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent windowEvent){
            System.exit(0);
         }        
      });    
      headerLabel = new Label();
      headerLabel.setAlignment(Label.CENTER);
      statusLabel = new Label();        
      statusLabel.setAlignment(Label.CENTER);
      statusLabel.setSize(350,100);

      controlPanel = new Panel();
      controlPanel.setLayout(new FlowLayout());

      mainFrame.add(headerLabel);
      mainFrame.add(controlPanel);
      mainFrame.add(statusLabel);
      mainFrame.setVisible(true);  
   }

   public void showEventDemo(){
      headerLabel.setText("Control in action: Button"); 

       RButton = new Button("RED");
       BButton = new Button("BLUE");
       GButton = new Button("GREEN");
       YButton = new Button("YELLOW");


      RButton.setActionCommand("RED");
      BButton.setActionCommand("BLUE");
      GButton.setActionCommand("GREEN");
      YButton.setActionCommand("YELLOW");

      RButton.addActionListener(new ButtonClickListener()); 
      BButton.addActionListener(new ButtonClickListener()); 
      GButton.addActionListener(new ButtonClickListener()); 
      YButton.addActionListener(new ButtonClickListener()); 
      //controlPanel.add(okButton);
      //controlPanel.add(submitButton);
      //controlPanel.add(cancelButton);
	controlPanel.add(RButton);
	controlPanel.add(BButton);
	controlPanel.add(GButton);  
	controlPanel.add(YButton);     

      mainFrame.setVisible(true);  
   }

   public class ButtonClickListener implements ActionListener{
      public void actionPerformed(ActionEvent e) {
         String command = e.getActionCommand();  
         if( command.equals( "RED" ))  {
            statusLabel.setText("RED Button clicked.");
	RButton.setBackground(Color.RED);
	BButton.setBackground(null);
	YButton.setBackground(null);
	GButton.setBackground(null);
	
         }
         else if( command.equals( "GREEN" ) )  {
            statusLabel.setText("GREEN Button clicked."); 
	GButton.setBackground(Color.GREEN);
	BButton.setBackground(null);
	YButton.setBackground(null);
	RButton.setBackground(null);
		
         }
	else if( command.equals( "BLUE" ) )  {
            statusLabel.setText("BLUE Button clicked.");
	BButton.setBackground(Color.BLUE);
	RButton.setBackground(null);
	YButton.setBackground(null);
	GButton.setBackground(null);

         }
         else  {
            statusLabel.setText("YELLOW Button clicked.");
	YButton.setBackground(Color.YELLOW);
	BButton.setBackground(null);
	RButton.setBackground(null);
	GButton.setBackground(null);

         }  	
      }		
   }
}