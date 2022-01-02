//Can Beyaznar 161044038

#include "composedshape.h"

namespace Shapes_namespace
{
	//if container shape is rectangle...	
	ComposedShape::ComposedShape(Rectangle bigShape,Rectangle smallShape)
	{
		
		containerShape_type='R';
		innerShape_type='R';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		containerRectangle=bigShape;
		innerRectangle=smallShape;
	
	}
	ComposedShape::ComposedShape(Rectangle bigShape,Circle smallShape)
	{
		containerShape_type='R';
		innerShape_type='C';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		containerRectangle=bigShape;
		innerCircle=smallShape;
		
		
	}
	ComposedShape::ComposedShape(Rectangle bigShape,Triangle smallShape)
	{
		containerShape_type='R';
		innerShape_type='T';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		containerRectangle=bigShape;
		innerTriangle=smallShape;
		
	}
	//if container shape is circle...	
	
	ComposedShape::ComposedShape(Circle bigShape,Rectangle smallShape)
	{
		containerShape_type='C';
		innerShape_type='R';
		bigShape.setColor("red");
		smallShape.setColor("green");
			
		containerCircle=bigShape;
		innerRectangle=smallShape;
		
	}
	ComposedShape::ComposedShape(Circle bigShape,Circle smallShape)
	{
		containerShape_type='C';
		innerShape_type='C';
		bigShape.setColor("red");
		smallShape.setColor("green");
			
		containerCircle=bigShape;
		innerCircle=smallShape;
		
	}
	ComposedShape::ComposedShape(Circle bigShape,Triangle smallShape)
	{
		containerShape_type='C';
		innerShape_type='T';
		bigShape.setColor("red");
		smallShape.setColor("green");
			
		containerCircle=bigShape;
		innerTriangle=smallShape;
		
		
	}
	
	//if container shape is triangle...	
	ComposedShape::ComposedShape(Triangle bigShape,Rectangle smallShape)
	{
		containerShape_type='T';
		innerShape_type='R';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		containerTriangle=bigShape;
		innerRectangle=smallShape;
		
	
	}
	ComposedShape::ComposedShape(Triangle bigShape,Circle smallShape)
	{
		containerShape_type='T';
		innerShape_type='C';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		
		containerTriangle=bigShape;
		innerCircle=smallShape;
	
	}
	ComposedShape::ComposedShape(Triangle bigShape,Triangle smallShape)
	{
		
		containerShape_type='T';
		innerShape_type='T';
		bigShape.setColor("red");
		smallShape.setColor("green");
		
		containerTriangle=bigShape;
		innerTriangle=smallShape;
		
	}
	
	void ComposedShape::optimalFit()
	{
		if(containerShape_type=='R')
		{
			if(containerRectangle.getHeight()<=0 || containerRectangle.getWidth()<=0 )
			{
				cout<<"You can not calculate of this shape!!"<<endl;
				cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
				return ;
			}
			
			if(innerShape_type=='R')
			{
				if(innerRectangle.getHeight()<=0 || innerRectangle.getWidth()<=0 )
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerRectangle,innerRectangle);
			}
				
					
			else if(innerShape_type=='C')
			{
				if(innerCircle.getRadius()<=0 )
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerRectangle,innerCircle);	
			}
					
			
			else if(innerShape_type=='T')
			{
				if(innerTriangle.getEdge()<=0 || innerTriangle.getHeight()<=0 )
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerRectangle,innerTriangle);
			}
				
			else
			{
				cout<<"You can not calculate of this shape!!"<<endl;
				cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
			}
				
		}
		
		//containerShape=circle...
		else if(containerShape_type=='C')
		{
			if(containerCircle.getRadius()<=0)
			{
				cout<<"You can not calculate of this shape!!"<<endl;
				cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
				return ;	
			}	
			
			if(innerShape_type=='R')
			{
				if(innerRectangle.getHeight()<=0 || innerRectangle.getWidth()<=0 )
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerCircle,innerRectangle);	
			}
				
		
			else if(innerShape_type=='C')
			{
				if(innerCircle.getRadius()<=0)
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerCircle,innerCircle);
			}
				
				
			else if(innerShape_type=='T')
			{
				if(innerTriangle.getEdge()<=0 || innerTriangle.getHeight()<=0)
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerCircle, innerTriangle);
			}
				
				
			else
				cout<<"You can not calculate of this shape!!"<<endl;
		}
		
		//containerShape=triangle...
		else if(containerShape_type=='T')
		{	
			if(innerShape_type=='R')
			{
				if(innerRectangle.getHeight()<=0 || innerRectangle.getWidth()<=0)
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerTriangle, innerRectangle);
			}
				
			else if(innerShape_type=='C')
			{
				if(innerCircle.getRadius()<=0)
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerTriangle, innerCircle);
			}
			
			
			else if(innerShape_type=='T')
			{
				if(innerTriangle.getEdge()<=0 || innerTriangle.getHeight()<=0)
				{
					cout<<"You can not calculate of this shape!!"<<endl;
					cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
					return ;
				}
				optimalFit(containerTriangle, innerTriangle);
			}		
				
			
			else
			cout<<"You can not calculate of this shape!!"<<endl;	
		}
		else
			cout<<"You can not calculate of this shape!!"<<endl;
	}
	
	void ComposedShape::optimalFit(Rectangle bigShape,Rectangle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		
		cout<<"Main shape: Rectangle"<<endl;
		*this+=containerRectangle;
	
		cout<<"Small shape: Rectangle"<<endl;
		Rectangle tempRectangle=innerRectangle;
		double temp;
		int height=tempRectangle.getHeight();
		int width=tempRectangle.getWidth();
		control=testRectinRect(containerRectangle,tempRectangle);
		if(control==2) // if the second possibility is more than another it will swap width and height
		{
			height=tempRectangle.getWidth();
			width=tempRectangle.getHeight();

			tempRectangle.setHeight(height);
			tempRectangle.setWidth(width);

		}
		int NumberofColumns=containerRectangle.getWidth()/width;
		int NumberofRows=containerRectangle.getHeight()/height;
		int remainingWidth=(int)containerRectangle.getWidth()%(int)width;
		int remainingHeight=(int)containerRectangle.getHeight()%(int)height;
		for(y=0; y<NumberofRows; y++)
		{
			for(x=0; x<NumberofColumns; x++)
			{
				tempRectangle.setLoc_X(x*width);
				tempRectangle.setLoc_Y(y*height);
						
				*this+=tempRectangle;
				count++;
			}
		}
		if(height<=remainingWidth )
		{
			temp=tempRectangle.getWidth();
			tempRectangle.setWidth(tempRectangle.getHeight());
			tempRectangle.setHeight(temp);
			for(y=0; y<(containerRectangle.getHeight()/width); y++)
			{
				if((width*(y))+width<= containerRectangle.getHeight())
				{
					for(x=0; x<(remainingWidth/height); x++)
					{
						if(((width*NumberofColumns)+(((x)*height))+height<=containerRectangle.getWidth()))
						{
							tempRectangle.setLoc_X((width*NumberofColumns)+(x*height));
							tempRectangle.setLoc_Y(width*y);
							*this+=tempRectangle;
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
				tempRectangle.setHeight(temp);
				for(y=0; y<(containerRectangle.getWidth()/height); y++)
				{
					if((height*(y))+height<=containerRectangle.getWidth())
					{
						for(x=0; x<(remainingHeight/width); x++)
						{
							if(((height*NumberofRows)+(((x)*width)))+width<=containerRectangle.getHeight())
							{
								tempRectangle.setLoc_X(innerRectangle.getHeight()*y);
								tempRectangle.setLoc_Y((height*NumberofRows)+(x*width));
								*this+=tempRectangle;
								count++;
							}
										
						}
					}
							
				}
		}
		result=(containerRectangle.getArea())-count*innerRectangle.getArea();
			
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
			
	}
	
	void ComposedShape::optimalFit(Rectangle bigShape,Circle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		
		cout<<"Main shape: Rectangle"<<endl;
		*this+=containerRectangle;
		
		cout<<"Small shape: Circle"<<endl;
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
					innerCircle.setLoc_X(innerCircle.getRadius()+innerCircle.getRadius()*2*y);
					innerCircle.setLoc_Y(innerCircle.getRadius()+innerCircle.getRadius()*2*x);
					*this+=innerCircle;
					y++;
					count++;
				}		
					
							
		}
		result=(containerRectangle.getArea())-count*innerCircle.getArea();
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
		
	}
	void ComposedShape::optimalFit(Rectangle bigShape,Triangle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		
		cout<<"Main shape: Rectangle"<<endl;
		*this+=containerRectangle;
		
		cout<<"Small shape: Triangle"<<endl;
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
					innerTriangle.setLoc_X(innerTriangle.getEdge()/2*countTriline);
					innerTriangle.setLoc_Y(containerRectangle.getHeight()-(countLine*innerTriangle.getHeight()));
					innerTriangle.setRotate(count%2);
					*this+=innerTriangle;
							
					count++;
					countTriline++;
				}
			}
			result=(containerRectangle.getArea())-count*innerTriangle.getArea();
		}
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
	}
			
	void ComposedShape::optimalFit(Circle bigShape,Rectangle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		
		cout<<"Main shape: Circle"<<endl;
		*this+=containerCircle;
		
		cout<<"Small shape: Rectangle"<<endl;
		int lineControl=0;
		x=0;
		y=0;
		cout<<endl<<"Please wait..."<<endl;
		while(y<2*containerCircle.getRadius())
		{
			x=0;
			lineControl=0;
			while(x<2*containerCircle.getRadius())
			{
				//**These conditions are looking that are corners of rectangles in the circle, if they are, drawrectangle...
				if(sqrt( pow((containerCircle.getRadius()-x),2)+ pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
				{
					if(sqrt( pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
					{
						if(sqrt( pow((containerCircle.getRadius()-(x)),2)+ pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
						{
							if(sqrt( pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
							{
									innerRectangle.setLoc_X(x);
									innerRectangle.setLoc_Y(y);
									*this+=innerRectangle;
									x+=innerRectangle.getWidth();
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
		result=(containerCircle.getArea())-count*innerRectangle.getArea();
		
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
		
	}
	void ComposedShape::optimalFit(Circle bigShape,Circle smallShape)
	{
		double result=0;
		int count=0;
		int control=0;
		int x,y;
		vector<double> Location_X;
		vector<double> Location_Y;
		unsigned int k;
		
		cout<<"Main shape: Circle"<<endl;
		*this+=containerCircle;
		
		cout<<"Small shape: Circle"<<endl;		
		cout<<endl<<"Please wait..."<<endl;
		for(y=0; y<=2*containerCircle.getRadius(); y++) //for y locations...
		{
			control=0;
			for(x=0; x<=2*containerCircle.getRadius(); x++) //for x locations...
			{
				control=0;
				if( sqrt( pow( (containerCircle.getRadius()-x),2 ) + pow( (containerCircle.getRadius()-y),2 ) ) + innerCircle.getRadius() <= containerCircle.getRadius() ) //this location is suitable to put a circle
				{
					if(count==0)
					{
						Location_X.push_back(x);
						Location_Y.push_back(y);
						innerCircle.setLoc_X(x);
						innerCircle.setLoc_Y(y);
						*this+=innerCircle;
						control=0;
						count++;
					}
						
					else
					{
						for(k=0; k<Location_X.size(); k++)
						{
							
							if( sqrt( pow( (Location_X[k] - x),2 )+pow( (Location_Y[k] - y),2 ) ) >=2*innerCircle.getRadius() ) //Finding distance between of the locations
							{
								control++;
							}
											
						}
						if(control>=count)
						{
							Location_X.push_back(x);
							Location_Y.push_back(y);
							innerCircle.setLoc_X(x);
							innerCircle.setLoc_Y(y);
							*this+=innerCircle;
							control=0;
							count++;
						}
					}
				}
			}
		}
		result=(containerCircle.getArea())-count*innerCircle.getArea();
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
	}
	void ComposedShape::optimalFit(Circle bigShape,Triangle smallShape)
	{
		double result=0;
		int count=0;
		int control=0;
		int x=0,y=0;
		int countLine=0;
		int countTriline=0;
		
		
		cout<<"Main shape: Circle"<<endl;
		*this+=containerCircle;
		
		cout<<"Small shape: Triangle"<<endl;
		cout<<endl<<"Please wait..."<<endl;
		while(y<2*containerCircle.getRadius())
		{		
			x=0;
			countTriline=0;
			while(x<2*containerCircle.getRadius())
			{
				control=1;
				if((countTriline+countLine)%2==0)
				{
					if(sqrt(pow(x-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
					{
						if(sqrt(pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius() && sqrt(pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius())
						{
							innerTriangle.setLoc_X(x);
							innerTriangle.setLoc_Y(y);
							innerTriangle.setRotate((countTriline+countLine)%2);
							*this+=innerTriangle;
							
							x+=innerTriangle.getEdge()/2;
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
					if(sqrt(pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius() && sqrt(pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius())
					{
						if(sqrt(pow(x-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
						{	
							innerTriangle.setLoc_X(x);
							innerTriangle.setLoc_Y(y);
							innerTriangle.setRotate((countTriline+countLine)%2);
							*this+=innerTriangle;
							x+=innerTriangle.getEdge()/2;
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
		result=(containerCircle.getArea())-count*innerTriangle.getArea();
		
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
	}
			
	void ComposedShape::optimalFit(Triangle bigShape,Rectangle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		int count1=0,count2=0;
		int countRectline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
		int i,j;
		int temp;
		double newHeight;
		double width,height;
		
		cout<<"Container shape: Triangle"<<endl;
			*this+=containerTriangle;
			
		Rectangle tempRectangle=innerRectangle;
		cout<<"Small shape: Rectangle"<<endl;
							
				
		width=tempRectangle.getWidth();
		height=tempRectangle.getHeight();
		//it will compare 2 possibility and find which will put triangles most...
			
		countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
		for(i=0; i<countLine; i++)
		{
			newHeight=(containerTriangle.getHeight()-i*height);
			countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
	
			for(j=0; j<countRectline; j++)
				count1++;
				
		}
		//swapped values...
		width=tempRectangle.getHeight();
		height=tempRectangle.getWidth();
				
		countLine=(containerTriangle.getHeight()-(tempRectangle.getWidth()/(2*sqrt(3))))/height;
		countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
		for(i=0; i<countLine; i++)
		{
			newHeight=(containerTriangle.getHeight()-i*height);
			countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
	
			for(j=0; j<countRectline; j++)
				count2++;
				
		}
		if(count2>=count1)
		{
			temp=tempRectangle.getHeight();
			tempRectangle.setHeight(tempRectangle.getWidth());
			tempRectangle.setWidth(temp);
			countLine=(containerTriangle.getHeight()-(tempRectangle.getWidth()/(2*sqrt(3))))/height;
			for(i=0; i<countLine; i++)
			{
				newHeight=(containerTriangle.getHeight()-i*height);
				countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
		
				for(j=0; j<countRectline; j++)
				{
					tempRectangle.setLoc_X(((i+1)*height/sqrt(3))+width*j);
					tempRectangle.setLoc_Y(containerTriangle.getHeight()-((i+1)*height));
					*this+=tempRectangle;
					count++;
				}
						
			}
		}
		else if(count1>count2)
		{
			width=tempRectangle.getWidth();
			height=tempRectangle.getHeight();
			
			countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
			for(i=0; i<countLine; i++)
			{
				newHeight=(containerTriangle.getHeight()-i*height);
				countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
			
				for(j=0; j<countRectline; j++)
				{
					tempRectangle.setLoc_X(((i+1)*height/sqrt(3))+width*j);
					tempRectangle.setLoc_Y(containerTriangle.getHeight()-((i+1)*height));
					*this+=tempRectangle;
					count++;
				}
				
			}
		}
		result=(containerTriangle.getArea())-count*innerRectangle.getArea();
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
		
	}
	void ComposedShape::optimalFit(Triangle bigShape,Circle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		int countCircleline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
		
		cout<<"Container shape: Triangle"<<endl;
			*this+=containerTriangle;
		
		cout<<"Small shape: Circle"<<endl;	
		countLine=((containerTriangle.getEdge()*sqrt(3)/2)-innerCircle.getRadius())/2*innerCircle.getRadius();
	
		for(y=0; y<countLine; y++)
		{
	
			countCircleline=((((containerTriangle.getEdge()-innerCircle.getRadius()*sqrt(3))/innerCircle.getRadius())+1)/2)-y;
			for(x=0; x<countCircleline; x++)
			{
				innerCircle.setLoc_X((innerCircle.getRadius()*sqrt(3))+(x*2*innerCircle.getRadius())+y*innerCircle.getRadius());
				innerCircle.setLoc_Y(containerTriangle.getHeight()-((innerCircle.getRadius())+(y*innerCircle.getRadius()*sqrt(3))));
				*this+=innerCircle;
				count++;
			}
		}
				
		result=(containerTriangle.getArea())-count*innerCircle.getArea();	
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
	}
	void ComposedShape::optimalFit(Triangle bigShape,Triangle smallShape)
	{
		double result=0;
		int count=0;
		int control;
		int x,y;
		int totalLine=containerTriangle.getHeight()/innerTriangle.getHeight();		
		int totalTriinline;
		
		cout<<"Container shape: Triangle"<<endl;
			*this+=containerTriangle;
						
		cout<<"Small shape: Triangle"<<endl;
		
		for(y=0; y<totalLine; y++)
		{
			totalTriinline=(containerTriangle.getEdge()/innerTriangle.getEdge())-(y);
			for(x=0; x<2*totalTriinline-1; x++)
			{
				innerTriangle.setLoc_X((innerTriangle.getEdge()/2*(x+1))+y*innerTriangle.getEdge()/2);
				innerTriangle.setLoc_Y(containerTriangle.getHeight()-((y+1)*innerTriangle.getHeight()));
				innerTriangle.setRotate((2*y+x)%2);
				*this+=innerTriangle;
				count++;
			}
		}
		result=(containerTriangle.getArea())-count*innerTriangle.getArea();				
			
		cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
		cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
	}
	
	int testRectinRect(Rectangle backgroundShape,Rectangle smallShape) //this function compares swapped height and width of small shape to find maximum count...
	{
		int width, height;
		int count1=0, count2=0;
		
		height=smallShape.getHeight();
		width=smallShape.getWidth();
		
		int NumberofColumns=backgroundShape.getWidth()/width;
		int NumberofRows=backgroundShape.getHeight()/height;
		int remainingWidth=(int)backgroundShape.getWidth()%width;
		int remainingHeight=(int)backgroundShape.getHeight()%height;
		
		count1=NumberofColumns*NumberofRows;
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
		
		count2=NumberofColumns*NumberofRows;
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
	
	ComposedShape ComposedShape:: operator +=( const Rectangle& Rectangle_I)
	{
		
		Polygon tempPolygon(Rectangle_I);
		this->allShapes.push_back(tempPolygon);
		return *this;
	}
	
	ComposedShape ComposedShape:: operator +=(const Circle& Circle_I)
	{
		Polygon tempPolygon(Circle_I);
		this->allShapes.push_back(tempPolygon);
		return *this;
	}
	
	ComposedShape ComposedShape:: operator +=(const Triangle& Triangle_I)
	{
		Polygon tempPolygon(Triangle_I);
		this->allShapes.push_back(tempPolygon);
		return *this;
	}
	
	const Polygon& ComposedShape::operator [](int index)
	{
		if(index>allShapes.size())
		{
			cout<<"Illegal index in Polygon vector of ComposedShape class !!"<<endl;
			exit(0); //It is error!!
		}
		return allShapes[index];
			
	}
	
	ostream& operator <<(std::ostream& outputStream, const ComposedShape& ComposedShape_I)
	{
		
		for(int i=0; i<ComposedShape_I.getAllShapesVector().size(); i++)
			outputStream<<ComposedShape_I.getAllShapesVector()[i];
		
		return outputStream;
	}
}






