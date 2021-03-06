import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import javax.swing.JPanel;
/**
 * 
 * @author Can Beyaznar
 *
 */
public class ComposedShape extends JPanel implements Shape {

	private Shape[] shapeList;
	private Shape containerShape;
	private Shape innerShape;
	private double area;
	private double perimeter;
	
	/**
	 * Default Constructor
	 */
	public ComposedShape() {
		shapeList=null;
	}
	/**
	 * 
	 * @param containerS Shape parameter
	 * @param innerS Shape parameter
	 */
	public ComposedShape(Shape containerS, Shape innerS) {
		shapeList=new Shape[1];
		
		if(containerS instanceof Rectangle)
			shapeList[0]=new Rectangle( (Rectangle) containerS );
		
		else if(containerS instanceof Circle)
			shapeList[0]=new Circle( (Circle) containerS );
		
		else if(containerS instanceof Triangle)
			shapeList[0]=new Triangle( (Triangle) containerS );
		
		this.containerShape = containerS;
		this.innerShape = innerS;
	}
	
	/**
	 * 
	 * @return shapeList.length
	 */
	public int Size() {
		return shapeList.length;
	}
	
	/**
	 * 
	 * @param myShape Shape
	 */
	public void add(Shape myShape) {
		
		Shape[] newList = new Shape[shapeList.length+1];
		int size = shapeList.length+1;
		for(int i=0; i<shapeList.length; ++i)
		{	
			if(shapeList[i] instanceof Rectangle)
				newList[i] = new Rectangle( (Rectangle) shapeList[i]  );
			
			else if(shapeList[i] instanceof Circle)
				newList[i] = new Circle( (Circle) shapeList[i]  );
			
			else if(shapeList[i] instanceof Triangle)
				newList[i] = new Triangle( (Triangle) shapeList[i]  );
		}
			
		if(myShape instanceof Rectangle)
			newList[shapeList.length] = new Rectangle( (Rectangle) myShape  );
		
		else if(myShape instanceof Circle)
			newList[shapeList.length] = new Circle( (Circle) myShape  );
		
		else if(myShape instanceof Triangle)
			newList[shapeList.length] = new Triangle( (Triangle) myShape  );
		
		shapeList = new Shape[size];
		for(int i=0; i<size; ++i)
		{
			if(newList[i] instanceof Rectangle)
				shapeList[i] = new Rectangle( (Rectangle) newList[i]  );
			
			else if(newList[i] instanceof Circle)
				shapeList[i] = new Circle( (Circle) newList[i]  );
			
			else if(newList[i] instanceof Triangle)
				shapeList[i] = new Triangle( (Triangle) newList[i]  );
		}
	}
	
	@Override
	public int compare(Shape o1, Shape o2) {
		
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}
	
	@Override
	public double area() {
		
		double result=0;
		for(int i=0; i<shapeList.length; ++i)
			result = result + shapeList[i].area();
		
		return result;
	}

	@Override
	public double perimeter() {
		
		double result=0;
		for(int i=0; i<shapeList.length; ++i)
			result =result + shapeList[i].perimeter();
		
		return result;
	}

	@Override
	public Shape increment() {
		
		for(int i=0; i<shapeList.length; ++i)
			shapeList[i].increment();
		
		return this;
	}

	@Override
	public Shape decrement() {
		
		for(int i=0; i<shapeList.length; ++i)
			shapeList[i].decrement();
		
		return this;
	}
	
	/**
	 * 
	 */
	@Override
	public void draw(Graphics g) {
		paintComponent(g);
	}
	
	/**
	 * 
	 */
	public void paintComponent(Graphics g) {
		
		super.paintComponent(g);
		g.setColor(Color.RED);
		shapeList[0].draw(g);
		
		g.setColor(Color.GREEN);
		for(int i=1; i<shapeList.length; ++i)
			shapeList[i].draw(g);
	}
	
	/**
	 * 
	 */
	void optimalFit() {
		double result=0;
		int count=0;
		int control;
		int x,y;
		
		if(containerShape instanceof Rectangle) {
			
			System.out.println("Container Shape: Rectangle");
			Rectangle containerRectangle = new Rectangle((Rectangle) containerShape);
			if(innerShape instanceof Rectangle)
			{
				
				System.out.println("Inner Shape: Rectangle");
				Rectangle innerRectangle=new Rectangle((Rectangle)innerShape);
				Rectangle tempRectangle=new Rectangle((Rectangle)innerShape);
				double temp;
				double height=tempRectangle.getHeight();
				double width=tempRectangle.getWidth();
				control=testRectinRect(containerRectangle,tempRectangle);
				if(control==2) // if the second possibility is more than another it will swap width and height
				{
					height=tempRectangle.getWidth();
					width=tempRectangle.getHeight();
				}
				int NumberofColumns=(int)(containerRectangle.getWidth()/width);
				int NumberofRows=(int)(containerRectangle.getHeight()/height);
				int remainingWidth=(int)containerRectangle.getWidth()%(int)width;
				int remainingHeight=(int)containerRectangle.getHeight()%(int)height;
				for(y=0; y<NumberofRows; y++)
				{
					for(x=0; x<NumberofColumns; x++)
					{
						Rectangle tempShape = new Rectangle(tempRectangle);
						tempShape.setLoc_X(x*width);
						tempShape.setLoc_Y(y*height);
						
						Shape newS = new Rectangle(tempShape);
						add(newS);
						count++;
					}
				}
				if(height<=remainingWidth )
				{
					temp=tempRectangle.getWidth();
					tempRectangle.setWidth(tempRectangle.getHeight());
					tempRectangle.setHeight((int)temp);
					for(y=0; y<(containerRectangle.getHeight()/width); y++)
					{
						if((width*(y))+width<= containerRectangle.getHeight())
						{
							for(x=0; x<(remainingWidth/height); x++)
							{
								if(((width*NumberofColumns)+(((x)*height))+height<=containerRectangle.getWidth()))
								{
									Rectangle tempShape = new Rectangle(tempRectangle);
									tempShape.setLoc_X((width*NumberofColumns)+(x*height));
									tempShape.setLoc_Y(width*y);
									System.out.println(tempShape.getLocX()+" "+tempShape.getLocY() );
									Shape newS = new Rectangle(tempShape);
									add(newS);
									count++;
								}		
							}
						}
					}				
				}
				else if(width<=remainingHeight)
				{
						temp=tempRectangle.getWidth();
						tempRectangle.setWidth(tempRectangle.getHeight());
						tempRectangle.setHeight((int)temp);
						for(y=0; y<(containerRectangle.getWidth()/height); y++)
						{
							if((height*(y))+height<=containerRectangle.getWidth())
							{
								for(x=0; x<(remainingHeight/width); x++)
								{
									if(((height*NumberofRows)+(((x)*width)))+width<=containerRectangle.getHeight())
									{
										Rectangle tempShape = new Rectangle(tempRectangle);
										tempShape.setLoc_X(innerRectangle.getHeight()*y);
										tempShape.setLoc_Y((height*NumberofRows)+(x*width));
										Shape newS = new Rectangle(tempShape);
										add(newS);
										count++;
									}
												
								}
							}
									
						}
				}
				result=(containerRectangle.area())-count*innerRectangle.area();
			}
			
			else if(innerShape instanceof Circle) {
				
				System.out.println("Inner Shape: Circle");
				Circle innerCircle = new Circle((Circle) innerShape);
				y=0;
				x=0;
				control=1;
				while(control==1)
				{
						if( (2*innerCircle.getRadius()+innerCircle.getRadius()*2*y) > containerRectangle.getWidth() )
						{
							y=0;
							x++;
						}
								
						else if((2*innerCircle.getRadius()+innerCircle.getRadius()*2*x > containerRectangle.getHeight()))
						{
							control=0;
						}
								
						else
						{
							Circle temp = new Circle(innerCircle);
							temp.setLoc_X(innerCircle.getRadius()+innerCircle.getRadius()*2*y);
							temp.setLoc_Y(innerCircle.getRadius()+innerCircle.getRadius()*2*x);
							
							Shape newS = new Circle(temp);
							add(newS);
							y++;
							count++;
						}			
				}
				result=(containerRectangle.area())-count*innerCircle.area();
			}

			else if(innerShape instanceof Triangle) {
				
				System.out.println("Inner Shape: Triangle");
				Triangle innerTriangle = new Triangle((Triangle) innerShape);
				int totalCount=0,countTriline=1,countLine=1; //**countTriline will take how many triangles put in one line, countLine will take how many lines used to put triangles...
				control=1;
				while(control==1)
				{	
	
					if(innerTriangle.getHeight()*(countLine)>containerRectangle.getHeight())
					{
						control=0;	
					}
					else
					{
						if((innerTriangle.getEdge()/2)*(double)(countTriline+1)>containerRectangle.getWidth() )
						{
							countLine++;
							totalCount=totalCount+countTriline-1;
							countTriline=1;
							
						}
						else
						{
							
							Triangle tempShape = new Triangle(innerTriangle);
							tempShape.setLoc_X(tempShape.getEdge()/2*countTriline);
							tempShape.setLoc_Y(containerRectangle.getHeight()-(countLine*tempShape.getHeight()));
							tempShape.setRotate(count%2);
							Shape newS = new Triangle(tempShape);
							add(newS);
							
							count++;
							countTriline++;
						}
					}
					
				}
				result=(containerRectangle.area())-count*innerTriangle.area();
			}
			
		}
		
		else if(containerShape instanceof Circle) {
			
			System.out.println("Container Shape: Circle");
			Circle containerCircle = new Circle((Circle) containerShape);
			
			if(innerShape instanceof Rectangle) {
				System.out.println("Inner Shape: Rectangle");
				Rectangle innerRectangle = new Rectangle((Rectangle) innerShape);
				
				int lineControl=0;
				x=0;
				y=0;
				
				while(y<2*containerCircle.getRadius())
				{
					x=0;
					lineControl=0;
					while(x<2*containerCircle.getRadius())
					{
						//**These conditions are looking that are corners of rectangles in the circle, if they are, drawrectangle...
						if(Math.sqrt( Math.pow((containerCircle.getRadius()-x),2)+ Math.pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
						{
							if(Math.sqrt( Math.pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ Math.pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
							{
								if(Math.sqrt( Math.pow((containerCircle.getRadius()-(x)),2)+ Math.pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
								{
									if(Math.sqrt( Math.pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ Math.pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
									{
										
											Rectangle tempShape = new Rectangle(innerRectangle);
											tempShape.setLoc_X(x);
											tempShape.setLoc_Y(y);
											Shape newS = new Rectangle(tempShape);
											add(newS);
											x+=tempShape.getWidth();
											lineControl=1;
											count++;
									}
									else
										x++;
								}
								else
										x++;
							}
							else
								x++;
								
						}
						else
							x++;	
					}
					if(lineControl==1)
					{
						y+=innerRectangle.getHeight();
						lineControl=0;
					}
					else
						y++;
				}
				result=(containerCircle.area())-count*innerRectangle.area();
		
			}
			
			else if(innerShape instanceof Circle) {
				System.out.println("Inner Shape: Circle");
				Circle innerCircle = new Circle((Circle) innerShape);
				
				ArrayList<Double> Location_X = new ArrayList<Double>();
				ArrayList<Double> Location_Y= new ArrayList<Double>();
				int k;
				control=0;
			
				for(y=0; y<=2*containerCircle.getRadius(); y++) //for y locations...
				{
					control=0;
					for(x=0; x<=2*containerCircle.getRadius(); x++) //for x locations...
					{
						control=0;
						if( Math.sqrt( Math.pow( (containerCircle.getRadius()-x),2 ) + Math.pow( (containerCircle.getRadius()-y),2 ) ) + innerCircle.getRadius() <= containerCircle.getRadius() ) //this location is suitable to put a circle
						{
							if(count==0)
							{
								
								Circle tempShape = new Circle(innerCircle);
								Location_X.add((double)x);
								Location_Y.add((double)y);
								tempShape.setLoc_X(x);
								tempShape.setLoc_Y(y);
								Shape newS = new Circle(tempShape);
								add(newS);
								control=0;
								count++;
							}
								
							else
							{
								for(k=0; k<Location_X.size(); k++)
								{
									
									if( Math.sqrt( Math.pow( (Location_X.get(k) - x),2 ) + Math.pow( (Location_Y.get(k) - y),2 ) ) >=2*innerCircle.getRadius() ) //Finding distance between of the locations
									{
										control++;
									}
												
								}
								if(control>=count)
								{
									Circle tempShape = new Circle(innerCircle);
									Location_X.add((double)x);
									Location_Y.add((double)y);
									tempShape.setLoc_X(x);
									tempShape.setLoc_Y(y);
									Shape newS = new Circle(tempShape);
									add(newS);
									control=0;
									count++;
								}
							}
						}
					}
				}
				result=(containerCircle.area())-count*innerCircle.area();
				
			}

			else if(innerShape instanceof Triangle) {
				System.out.println("Inner Shape: Triangle");
				Triangle innerTriangle = new Triangle((Triangle) innerShape);
				
				int countLine=0;
				int countTriline=0;
				x=0;
				y=0;
				control=0;	
				
				while(y<2*containerCircle.getRadius())
				{
					
					x=0;
					countTriline=0;
					while(x<2*containerCircle.getRadius())
					{
						control=1;
						if((countTriline+countLine)%2==0)
						{
							if(Math.sqrt(Math.pow(x-containerCircle.getRadius(),2)+Math.pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
							{
								if(Math.sqrt(Math.pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+Math.pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius()
										&& Math.sqrt(Math.pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+Math.pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius())
								{
									Triangle tempShape = new Triangle(innerTriangle);
									tempShape.setLoc_X(x);
									tempShape.setLoc_Y(y);
									tempShape.setRotate((countTriline+countLine)%2);
									Shape newS = new Triangle(tempShape);
									add(newS);
									
									x+=tempShape.getEdge()/2;
									countTriline++;
									control=1;
									count++;
								}
								else
									x++;
								
							}
							else
								x++;
						}
						else if((countTriline+countLine)%2==1)
						{
							if(Math.sqrt(Math.pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+Math.pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius()
									&& Math.sqrt(Math.pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+Math.pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius())
							{
								if(Math.sqrt(Math.pow(x-containerCircle.getRadius(),2)+Math.pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
								{	
									Triangle tempShape = new Triangle(innerTriangle);
									tempShape.setLoc_X(x);
									tempShape.setLoc_Y(y);
									tempShape.setRotate((countTriline+countLine)%2);
									Shape newS = new Triangle(tempShape);
									add(newS);
									x+=tempShape.getEdge()/2;
									countTriline++;
									control=1;
									count++;
								}
								else
									x++;
							}
							else
								x++;
							
						}
						
					}
					if(control==1)
					{
						y+=innerTriangle.getHeight();
						countLine++;
						control=0;
					}
					else
						y++;
				}
				result=(containerCircle.area())-count*innerTriangle.area();
				
			}
			
		}

		else if(containerShape instanceof Triangle) {
			
			System.out.println("Container Shape: Triangle");
			Triangle containerTriangle = new Triangle((Triangle) containerShape);
			
			if(innerShape instanceof Rectangle) {
				System.out.println("Inner Shape: Rectangle");
				Rectangle innerRectangle = new Rectangle((Rectangle) innerShape);
				Rectangle tempRectangle=new Rectangle(innerRectangle);
				
				int count1=0,count2=0;
				int countRectline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
				int i,j;
				double newHeight;
				double temp;
				
				double width,height;
				width=tempRectangle.getWidth();
				height=tempRectangle.getHeight();
				//it will compare 2 possibility and find which will put triangles most...
				
				countLine=(int)(containerTriangle.getHeight()-(width/(2*Math.sqrt(3))))/(int)height;
				for(i=0; i<countLine; i++)
				{
					newHeight=(containerTriangle.getHeight()-i*height);
					countRectline=(int)((2*newHeight/Math.sqrt(3))-(2*height/Math.sqrt(3)))/(int)width;
			
					for(j=0; j<countRectline; j++)
						count1++;
					
				}
				//swapped values...
				width=tempRectangle.getHeight();
				height=tempRectangle.getWidth();
				
				countLine=(int)((containerTriangle.getHeight()-(width/(2*Math.sqrt(3))))/height);
				for(i=0; i<countLine; i++)
				{
					newHeight=(containerTriangle.getHeight()-i*height);
					countRectline=(int)(((2*newHeight/Math.sqrt(3))-(2*height/Math.sqrt(3)))/width);
			
					for(j=0; j<countRectline; j++)
						count2++;
					
				}
				if(count2>=count1)
				{
					temp=tempRectangle.getHeight();
					tempRectangle.setHeight(tempRectangle.getWidth());
					tempRectangle.setWidth((int)temp);
					countLine=(int)((containerTriangle.getHeight()-(tempRectangle.getWidth()/(2*Math.sqrt(3))))/height);
					for(i=0; i<countLine; i++)
					{
						newHeight=(containerTriangle.getHeight()-i*height);
						countRectline=(int)(((2*newHeight/Math.sqrt(3))-(2*height/Math.sqrt(3)))/width);
				
						for(j=0; j<countRectline; j++)
						{
							Rectangle tempShape = new Rectangle(tempRectangle);
							tempShape.setLoc_X(((i+1)*height/Math.sqrt(3))+width*j);
							tempShape.setLoc_Y(containerTriangle.getHeight()-((i+1)*height));
							Shape newS = new Rectangle(tempShape);
							add(newS);
							count++;
						}
						
					}
				}
				else if(count1>count2)
				{
					width=tempRectangle.getWidth();
					height=tempRectangle.getHeight();
					
					countLine=(int)((containerTriangle.getHeight()-(width/(2*Math.sqrt(3))))/height);
					for(i=0; i<countLine; i++)
					{
						newHeight=(containerTriangle.getHeight()-i*height);
						countRectline=(int)(((2*newHeight/Math.sqrt(3))-(2*height/Math.sqrt(3)))/width);
				
						for(j=0; j<countRectline; j++)
						{
							Rectangle tempShape = new Rectangle(tempRectangle);
							tempShape.setLoc_X(((i+1)*height/Math.sqrt(3))+width*j);
							tempShape.setLoc_Y(containerTriangle.getHeight()-((i+1)*height));
							Shape newS = new Rectangle(tempShape);
							add(newS);
							count++;
						}
						
					}
				}
				result=(containerTriangle.area())-count*innerRectangle.area();
			}
			
			else if(innerShape instanceof Circle) {
				System.out.println("Inner Shape: Circle");
				Circle innerCircle = new Circle((Circle) innerShape);
				
				int countCircleline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
				
				countLine=(int)(((containerTriangle.getEdge()*Math.sqrt(3)/2)-innerCircle.getRadius())/2*innerCircle.getRadius());
				
				for(y=0; y<countLine; y++)
				{
	
					countCircleline=(int)(((((containerTriangle.getEdge()-innerCircle.getRadius()*Math.sqrt(3))/innerCircle.getRadius())+1)/2)-y);
					for(x=0; x<countCircleline; x++)
					{
						Circle tempShape = new Circle(innerCircle);
						tempShape.setLoc_X((tempShape.getRadius()*Math.sqrt(3))+(x*2*tempShape.getRadius())+y*tempShape.getRadius());
						tempShape.setLoc_Y(containerTriangle.getHeight()-((tempShape.getRadius())+(y*tempShape.getRadius()*Math.sqrt(3))));
						Shape newS = new Circle(tempShape);
						add(newS);
						count++;
					}
				}
				
				result=(containerTriangle.area())-count*innerCircle.area();
			}

			else if(innerShape instanceof Triangle) {
				System.out.println("Inner Shape: Triangle");
				Triangle innerTriangle = new Triangle((Triangle) innerShape);
			
				int totalLine=(int)(containerTriangle.getHeight()/innerTriangle.getHeight());		
				int totalTriinline;
				for(y=0; y<totalLine; y++)
				{
					totalTriinline=(int)((containerTriangle.getEdge()/innerTriangle.getEdge())-(y));
					for(x=0; x<2*totalTriinline-1; x++)
					{
						Triangle tempShape = new Triangle(innerTriangle);
						tempShape.setLoc_X((tempShape.getEdge()/2*(x+1))+y*tempShape.getEdge()/2);
						tempShape.setLoc_Y(containerTriangle.getHeight()-((y+1)*tempShape.getHeight()));
						tempShape.setRotate((2*y+x)%2);
						Shape newS = new Triangle(tempShape);
						add(newS);
						count++;
					}
				}
				result=(containerTriangle.area())-count*innerTriangle.area();
			}
			
		}
		
		System.out.println("I can fit at most "+count+" small shapes into main container. The empty area (red) in container is "+result+".");
		System.out.println("----------------------------------------------------------------------\n");
		
	}
	/**
	 * Just an auxiliary function for Rectangle to Rectangle in OptimalFit Function.
	 * @param backgroundShape Rectangle
	 * @param smallShape Rectangle
	 * @return 1, 2 or -1
	 */
	private int testRectinRect(Rectangle backgroundShape,Rectangle smallShape) //this function compares swapped height and width of small shape to find maximum count...
	{
		double width, height;
		int count1=0, count2=0;
		
		height=smallShape.getHeight();
		width=smallShape.getWidth();
		
		double NumberofColumns=backgroundShape.getWidth()/width;
		double NumberofRows=backgroundShape.getHeight()/height;
		double remainingWidth=(int)backgroundShape.getWidth()%width;
		double remainingHeight=(int)backgroundShape.getHeight()%height;
		
		count1=(int)(NumberofColumns*NumberofRows);
		if(height<=remainingWidth)
		{
			count1=count1+(int)(remainingWidth/smallShape.getHeight())*(int)(backgroundShape.getHeight()/width);
		}
		else if(width<=remainingHeight)
		{
			count1=count1+(int)(remainingHeight/smallShape.getWidth())*(int)(backgroundShape.getWidth()/height);
		}
		//swapped height and width to find maximum count
		height=smallShape.getWidth();
		width=smallShape.getHeight();
		
		NumberofColumns=backgroundShape.getWidth()/width;
		NumberofRows=backgroundShape.getHeight()/height;
		remainingWidth=(int)backgroundShape.getWidth()%width;
		remainingHeight=(int)backgroundShape.getHeight()%height;
		
		count2=(int)(NumberofColumns*NumberofRows);
		if(height<=remainingWidth)
		{
			count2=count2+(int)(remainingWidth/smallShape.getHeight())*(int)(backgroundShape.getHeight()/width);

		}
		else if(width<=remainingHeight)
		{
			count2=count2+(int)(remainingHeight/smallShape.getWidth())*(int)(backgroundShape.getWidth()/height);
		}
		if(count1>=count2)
			return 1;
		else if(count1<count2)
			return 2;
		else 
			return -1;
	}
}


