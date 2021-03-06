
import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JPanel;


import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JButton;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JRadioButton;


public class MyMain {
	
	private JFrame frame;
	private JTextField txtWidth;
	private JTextField txtHeight;
	private JTextField txtRadius;
	private JTextField txtEdge;
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	
	/**
	 * 
	 * @param ShapesArr Shape Array
	 * @param g Grapghics Parameter
	 */
	public static void drawAll(Shape[] ShapesArr, Graphics g)
	{
		
		for(Shape i : ShapesArr) {
			i.draw(g);
		}
	}
	/**
	 * 
	 * @param ShapesArr Shape Array
	 * @return Polygon[]
	 */
	public static Polygon[] convertAll(Shape[] ShapesArr)
	{
		
		Polygon[] Result = new Polygon[ShapesArr.length];
		for(int i=0; i<ShapesArr.length; ++i)
		{
			if(ShapesArr[i] instanceof Rectangle)
				Result[i] = new PolygonDyn( ((Rectangle) ShapesArr[i]) );
			
			else if(ShapesArr[i] instanceof Circle)
				Result[i] = new PolygonDyn( ((Circle) ShapesArr[i]) );
			
			else if(ShapesArr[i] instanceof Triangle)
				Result[i] = new PolygonDyn( ((Triangle) ShapesArr[i]) );
			
			else if(ShapesArr[i] instanceof PolygonDyn)
				Result[i] = new PolygonDyn( ((PolygonDyn) ShapesArr[i]) );
			
			else if(ShapesArr[i] instanceof PolygonVect)
				Result[i] = new PolygonVect( ((PolygonVect) ShapesArr[i]) );
			
			else
				System.out.println("CAN NOT CONVERT THIS CLASS!!");
			
		}
		
		return Result;
		
	}
	/**
	 * 
	 * @param ShapesArr Shape Array
	 */
	public static void sortShapes(Shape[] ShapesArr)
	{
		
		for(int i=0; i<ShapesArr.length; ++i)
		{
			for(int j=0; j<ShapesArr.length; ++j)
			{
				if(ShapesArr[i].area()<=ShapesArr[j].area())
				{
					Shape tempShape=ShapesArr[i];
					ShapesArr[i]=ShapesArr[j];
					ShapesArr[j]=tempShape;
				}
			}
		}
		
		for(int i=0; i<ShapesArr.length; ++i)
			System.out.println((i+1)+". Shape: "+ShapesArr[i].getClass().getName()+" Area: "+ShapesArr[i].area());

		
	}
	
	public static void main(String[] args) {
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyMain window = new MyMain();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	/**
	 * 
	 */
	public MyMain() {
		initialize();
	}
	
	/**
	 * 
	 */
	private void initialize() {
		
		//Create a frame to contain all other GUI elements
		frame = new JFrame();
		frame.setBounds(100, 100, 970, 725);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		
		//Create a panel for drawing shapes, you can think this as canvas
		final JPanel panel = new JPanel();
		//FlowLayout flowLayout = (FlowLayout) panel.getLayout();
		panel.setBackground(Color.WHITE);
		panel.setBounds(0, 0, 944, 576);
		frame.getContentPane().add(panel);
		
		//Label above combo box, just immutable plain text
		JLabel containerShapeLabel = new JLabel("Container shape");
		containerShapeLabel.setHorizontalAlignment(SwingConstants.CENTER);
		containerShapeLabel.setBounds(10, 582, 99, 14);
		frame.getContentPane().add(containerShapeLabel);
		//Label above combo box, just immutable plain text
		JLabel lblInnerShape = new JLabel("Inner shape");
		lblInnerShape.setHorizontalAlignment(SwingConstants.CENTER);
		lblInnerShape.setBounds(403, 582, 100, 14);
		frame.getContentPane().add(lblInnerShape);
		
		// A button that will clear our panel (canvas) when clicked
		// This can be done using callback function mouseClicked
		// The GUI engine will execute mouseClicked function when
		// the user clicks our clear button.
		JButton btnClear = new JButton("Clear");
		btnClear.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// Clear panel by filling white :)
				// The Graphics reference is used to draw shapes.
				// When we call panel.getGraphics(), we reach the brush and palette
				// to design our paint that will be painted on the panel(canvas). 
				// After we design our paint,
				// we need to call the paintComponents method, which will
				// ACTUALLY paint the panel with the design that we made.
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g); // the panel will change when THIS function is executed
			}
		});
		
		btnClear.setBounds(869, 604, 75, 23);
		frame.getContentPane().add(btnClear);
		
		final JRadioButton rdbtnNewRadioButton = new JRadioButton("Rectangle");
		rdbtnNewRadioButton.setBounds(10, 604, 99, 23);
		frame.getContentPane().add(rdbtnNewRadioButton);
		
		final JRadioButton rdbtnNewRadioButton_1 = new JRadioButton("Circle");
		rdbtnNewRadioButton_1.setBounds(10, 630, 109, 23);
		frame.getContentPane().add(rdbtnNewRadioButton_1);
		
		final JRadioButton rdbtnNewRadioButton_2 = new JRadioButton("Triangle");
		rdbtnNewRadioButton_2.setBounds(10, 655, 109, 23);
		frame.getContentPane().add(rdbtnNewRadioButton_2);
		
		final JRadioButton rdbtnNewRadioButton_3 = new JRadioButton("Rectangle");
		rdbtnNewRadioButton_3.setBounds(403, 604, 109, 23);
		frame.getContentPane().add(rdbtnNewRadioButton_3);
		
		final JRadioButton rdbtnNewRadioButton_4 = new JRadioButton("Circle");
		rdbtnNewRadioButton_4.setBounds(403, 630, 109, 23);
		frame.getContentPane().add(rdbtnNewRadioButton_4);
		
		final JRadioButton rdbtnNewRadioButton_5 = new JRadioButton("Triangle");
		rdbtnNewRadioButton_5.setBounds(403, 655, 109, 23);
		frame.getContentPane().add(rdbtnNewRadioButton_5);
		
		txtWidth = new JTextField();
		txtWidth.setText("1");
		txtWidth.setBounds(125, 605, 46, 20);
		frame.getContentPane().add(txtWidth);
		txtWidth.setColumns(10);
		
		txtHeight = new JTextField();
		txtHeight.setText("1");
		txtHeight.setColumns(10);
		txtHeight.setBounds(181, 605, 46, 20);
		frame.getContentPane().add(txtHeight);
		
		txtRadius = new JTextField();
		txtRadius.setText("1");
		txtRadius.setColumns(10);
		txtRadius.setBounds(125, 631, 46, 20);
		frame.getContentPane().add(txtRadius);
		
		txtEdge = new JTextField();
		txtEdge.setText("1");
		txtEdge.setColumns(10);
		txtEdge.setBounds(125, 656, 46, 20);
		frame.getContentPane().add(txtEdge);
		
		textField = new JTextField();
		textField.setText("1");
		textField.setColumns(10);
		textField.setBounds(518, 605, 46, 20);
		frame.getContentPane().add(textField);
		
		textField_1 = new JTextField();
		textField_1.setText("1");
		textField_1.setColumns(10);
		textField_1.setBounds(574, 605, 46, 20);
		frame.getContentPane().add(textField_1);
		
		textField_2 = new JTextField();
		textField_2.setText("1");
		textField_2.setColumns(10);
		textField_2.setBounds(518, 631, 46, 20);
		frame.getContentPane().add(textField_2);
		
		textField_3 = new JTextField();
		textField_3.setText("1");
		textField_3.setColumns(10);
		textField_3.setBounds(518, 656, 46, 20);
		frame.getContentPane().add(textField_3);
		
		
		JButton button = new JButton("Draw");
		button.setBounds(869, 578, 75, 23);
		frame.getContentPane().add(button);
		
		JButton btnNewButton = new JButton("drawAll");
		btnNewButton.setBounds(739, 578, 109, 23);
		frame.getContentPane().add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("convertAll");
		btnNewButton_1.setBounds(739, 604, 109, 23);
		frame.getContentPane().add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("sortShapes");
		btnNewButton_2.setBounds(739, 630, 109, 23);
		frame.getContentPane().add(btnNewButton_2);
		
		JLabel lblWidth = new JLabel("Width");
		lblWidth.setHorizontalAlignment(SwingConstants.CENTER);
		lblWidth.setBounds(125, 587, 46, 14);
		frame.getContentPane().add(lblWidth);
		
		JLabel lblHeight = new JLabel("Height");
		lblHeight.setHorizontalAlignment(SwingConstants.CENTER);
		lblHeight.setBounds(181, 587, 46, 14);
		frame.getContentPane().add(lblHeight);
		
		JLabel lblRadius = new JLabel("Radius");
		lblRadius.setHorizontalAlignment(SwingConstants.CENTER);
		lblRadius.setBounds(181, 634, 46, 14);
		frame.getContentPane().add(lblRadius);
		
		JLabel lblEdge = new JLabel("Edge");
		lblEdge.setHorizontalAlignment(SwingConstants.CENTER);
		lblEdge.setBounds(181, 659, 46, 14);
		frame.getContentPane().add(lblEdge);
		
		JLabel label = new JLabel("Radius");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setBounds(574, 634, 46, 14);
		frame.getContentPane().add(label);
		
		JLabel label_1 = new JLabel("Edge");
		label_1.setHorizontalAlignment(SwingConstants.CENTER);
		label_1.setBounds(574, 659, 46, 14);
		frame.getContentPane().add(label_1);
		
		JLabel label_2 = new JLabel("Width");
		label_2.setHorizontalAlignment(SwingConstants.CENTER);
		label_2.setBounds(518, 587, 46, 14);
		frame.getContentPane().add(label_2);
		
		JLabel label_3 = new JLabel("Height");
		label_3.setHorizontalAlignment(SwingConstants.CENTER);
		label_3.setBounds(574, 587, 46, 14);
		frame.getContentPane().add(label_3);
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				// Print currently selected items of combo boxes
				//Container Shape = Rectangle
				if(rdbtnNewRadioButton.isSelected() && rdbtnNewRadioButton_3.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					
					String width = txtWidth.getText();
					String height = txtHeight.getText();
					
					
					
					int tempWidth = Integer.parseInt(width);
					int tempHeight = Integer.parseInt(height);
					
					Rectangle myRectangle = new Rectangle(tempWidth,tempHeight);
					
					String secondWidth = textField.getText();
					String secondHeight = textField_1.getText();
					
					int secondtempWidth = Integer.parseInt(secondWidth);
					int secondtempHeight = Integer.parseInt(secondHeight);
					
					Rectangle mySecondRectangle = new Rectangle(secondtempWidth,secondtempHeight);
					
					ComposedShape myCS = new ComposedShape(myRectangle,mySecondRectangle);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else if(rdbtnNewRadioButton.isSelected() && rdbtnNewRadioButton_4.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String width = txtWidth.getText();
					String height = txtHeight.getText();
					
					int tempWidth = Integer.parseInt(width);
					int tempHeight = Integer.parseInt(height);
					
					Rectangle myRectangle = new Rectangle(tempWidth,tempHeight);
					
					String secondString= textField_2.getText();
					
					int secondInput = Integer.parseInt(secondString);
					
					Circle mySecondShape = new Circle(secondInput);
					
					ComposedShape myCS = new ComposedShape(myRectangle,mySecondShape);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else if(rdbtnNewRadioButton.isSelected() && rdbtnNewRadioButton_5.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String width = txtWidth.getText();
					String height = txtHeight.getText();
					
					int tempWidth = Integer.parseInt(width);
					int tempHeight = Integer.parseInt(height);
					
					Rectangle myRectangle = new Rectangle(tempWidth,tempHeight);
					
					String secondString= textField_3.getText();
					
					int secondInput = Integer.parseInt(secondString);
					
					Triangle mySecondShape = new Triangle(secondInput);
					
					ComposedShape myCS = new ComposedShape(myRectangle,mySecondShape);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				//Container Shape = Circle
				else if(rdbtnNewRadioButton_1.isSelected() && rdbtnNewRadioButton_3.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String radius = txtRadius.getText();
					
					int tempRadius = Integer.parseInt(radius);
					
					Circle myCircle = new Circle(tempRadius);
					
					String secondWidth = textField.getText();
					String secondHeight = textField_1.getText();
					
					int secondtempWidth = Integer.parseInt(secondWidth);
					int secondtempHeight = Integer.parseInt(secondHeight);
					
					Rectangle mySecondRectangle = new Rectangle(secondtempWidth,secondtempHeight);
					
					ComposedShape myCS = new ComposedShape(myCircle,mySecondRectangle);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else if(rdbtnNewRadioButton_1.isSelected() && rdbtnNewRadioButton_4.isSelected() )
				{
					
					Graphics g = panel.getGraphics();
					
					String radius = txtRadius.getText();
					
					int tempRadius = Integer.parseInt(radius);
					
					Circle myCircle = new Circle(tempRadius);
					
					String secondRadius = textField_2.getText();
					
					int secondRad= Integer.parseInt(secondRadius);
					
					Circle mySecondCircle= new Circle(secondRad);
					
					ComposedShape myCS = new ComposedShape(myCircle,mySecondCircle);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else if(rdbtnNewRadioButton_1.isSelected() && rdbtnNewRadioButton_5.isSelected() )
				{
					
					Graphics g = panel.getGraphics();
					String radius = txtRadius.getText();
					int tempRadius = Integer.parseInt(radius);
					Circle myCircle = new Circle(tempRadius);
					
					String Edge = textField_3.getText();
					int myEdge= Integer.parseInt(Edge);
					Triangle myTriangle= new Triangle(myEdge);
					
					ComposedShape myCS = new ComposedShape(myCircle,myTriangle);
					myCS.optimalFit();
					myCS.draw(g);
					
					
				}
				
				//Container Shape = Triangle
				else if(rdbtnNewRadioButton_2.isSelected() && rdbtnNewRadioButton_3.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String edge = txtEdge.getText();
					int myEdge = Integer.parseInt(edge);
					
					Triangle myTriangle = new Triangle(myEdge);
					
					String secondWidth = textField.getText();
					String secondHeight = textField_1.getText();
					
					int secondtempWidth = Integer.parseInt(secondWidth);
					int secondtempHeight = Integer.parseInt(secondHeight);
					
					Rectangle mySecondRectangle = new Rectangle(secondtempWidth,secondtempHeight);
					
					
					ComposedShape myCS = new ComposedShape(myTriangle,mySecondRectangle);
					myCS.optimalFit();
					myCS.draw(g);
					
				}
				
				else if(rdbtnNewRadioButton_2.isSelected() && rdbtnNewRadioButton_4.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String edge = txtEdge.getText();
					int myEdge = Integer.parseInt(edge);
					
					Triangle myTriangle = new Triangle(myEdge);
					
					String secondRadius = textField_2.getText();
					
					int secondRad= Integer.parseInt(secondRadius);
					
					Circle mySecondCircle= new Circle(secondRad);
					
					ComposedShape myCS = new ComposedShape(myTriangle,mySecondCircle);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else if(rdbtnNewRadioButton_2.isSelected() && rdbtnNewRadioButton_5.isSelected() )
				{
					Graphics g = panel.getGraphics();
					
					String edge = txtEdge.getText();
					int myEdge = Integer.parseInt(edge);
					
					Triangle myTriangle = new Triangle(myEdge);
					
					String secondEdge = textField_3.getText();
					int mysecondEdge= Integer.parseInt(secondEdge);
					Triangle mysecondTriangle= new Triangle(mysecondEdge);
					
					ComposedShape myCS = new ComposedShape(myTriangle,mysecondTriangle);
					myCS.optimalFit();
					myCS.draw(g);
				}
				
				else
					System.out.println("UNKNOWN!!");
				
			}
		});
		
		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				
				Graphics g = panel.getGraphics();
				
				Shape myShape[] = new Shape[4];
				myShape[0] = new Rectangle(100,60);
				myShape[1] = new Circle(75,120,120);
				myShape[2] = new PolygonDyn(new Triangle(37));
				
				Triangle myTri = new Triangle(67);
				myTri.setLoc_X(60);
				myTri.setLoc_Y(60);
				myShape[3] = new PolygonVect(myTri);
				
				drawAll(myShape,g);
			}
			
		});
		
		btnNewButton_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				
				Graphics g = panel.getGraphics();
				
				Shape myShape[] = new Shape[4];
				myShape[0] = new Rectangle(100,60);
				myShape[1] = new Circle(75,120,120);
				myShape[2] = new PolygonDyn(new Triangle(37));
				
				Triangle myTri = new Triangle(67);
				myTri.setLoc_X(60);
				myTri.setLoc_Y(60);
				myShape[3] = new PolygonVect(myTri);
				
				Polygon myPolygon[] = new Polygon[3];
				myPolygon=convertAll(myShape);
				
				for(int i=0; i<myPolygon.length; ++i)
				{
					myPolygon[i].draw(g);
				}
					
			
			}
			
		});
		
		btnNewButton_2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				
				Graphics g = panel.getGraphics();
				
				Shape myShape[] = new Shape[4];
				
				myShape[0] = new Circle(75,120,120);
				myShape[1] = new Rectangle(100,60);
				myShape[2] = new PolygonDyn(new Triangle(37));
				
				Triangle myTri = new Triangle(67);
				myTri.setLoc_X(60);
				myTri.setLoc_Y(60);
				myShape[3] = new PolygonVect(myTri);
				
				sortShapes(myShape);
				
				for(int i=0; i<myShape.length; ++i)
				{
					myShape[i].draw(g);
				}
					
			
			}
			
		});
		
	}
}
