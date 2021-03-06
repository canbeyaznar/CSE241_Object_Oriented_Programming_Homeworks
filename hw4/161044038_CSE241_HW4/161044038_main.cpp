//Can Beyaznar 161044038

#include "composedshape.h"

using namespace Shapes_namespace;

int main()
{
	Rectangle r1(500,250), r2(9,17);
	Circle c1(100), c2(10);
	Triangle t1(500),t2(16);
	
	//**ComposedShape Examples**
	//CONTAINER RECTANGLE EXAMPLES...
	
	//for rectangle in rectangle
	ofstream File1;
	File1.open("output1.svg");
	File1<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x1(r1,r2);
	x1.optimalFit();
	File1<<x1;

	File1<<endl<<"</svg>";
	File1.close();

	//for circle in rectangle
	ofstream File2;
	File2.open("output2.svg");
	File2<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x2(r1,c2);
	x2.optimalFit();
	File2<<x2;

	File2<<endl<<"</svg>";
	File2.close();


	//for triangle in rectangle
	ofstream File3;
	File3.open("output3.svg");
	File3<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x3(r1,t2);
	x3.optimalFit();
	File3<<x3;

	File3<<endl<<"</svg>";
	File3.close();


	//CONTAINER CIRCLE EXAMPLES
	
	//for rectangle in circle
	ofstream File4;
	File4.open("output4.svg");
	File4<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x4(c1,r2);
	x4.optimalFit();
	File4<<x4;
	
	File4<<endl<<"</svg>";
	File4.close();


	//for circle in circle
	ofstream File5;
	File5.open("output5.svg");
	File5<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x5(c1,c2);
	x5.optimalFit();
	File5<<x5;
	
	File5<<endl<<"</svg>";
	File5.close();


	//for triangle in circle
	ofstream File6;
	File6.open("output6.svg");
	File6<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x6(c1,t2);
	x6.optimalFit();
	File6<<x6;
	
	File6<<endl<<"</svg>";
	File6.close();

	//CONTAINER TRIANGLE EXAMPLES
	
	//for rectangle in triangle
	ofstream File7;
	File7.open("output7.svg");
	File7<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x7(t1,r2);
	x7.optimalFit();
	File7<<x7;
	
	File7<<endl<<"</svg>";
	File7.close();


	//for circle in triangle
	ofstream File8;
	File8.open("output8.svg");
	File8<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x8(t1,c2);
	x8.optimalFit();
	File8<<x8;
	
	File8<<endl<<"</svg>";
	File8.close();


	//for triangle in triangle
	ofstream File9;
	File9.open("output9.svg");
	File9<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x9(t1,t2);
	x9.optimalFit();
	File9<<x9;
	
	File9<<endl<<"</svg>";
	File9.close();
	
	
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	//Polygon Class Examples
	Rectangle firstRect(300,175), secondRect(7,16);
	Circle firstCircle(100), secondCircle(9);
	Triangle firstTriangle(263),secondTriangle(13);
	
	int sizeoffArr=6;
	
	Polygon *polygonArr=new Polygon[sizeoffArr];
	ComposedShape *composedShapeArr=new ComposedShape[sizeoffArr];
	
	//conversion constructors of polygon
	polygonArr[0]=firstRect;
	polygonArr[1]=firstCircle;
	polygonArr[2]=firstTriangle;
	polygonArr[3]=secondRect;
	polygonArr[4]=secondCircle;
	polygonArr[5]=firstRect;
	
	//Polygon plus and assign operator 
	Polygon tempPolygon=polygonArr[0]+polygonArr[2]+polygonArr[3];
	
	//conversion constructors of polygon
	vector <Polygon::Point2D> tempPoints;
	
	for(int i=0; i<tempPolygon.getSize(); i++)
		tempPoints.push_back(tempPolygon[i]); //index overload
	
	Polygon Result(tempPoints);
	
	ofstream File10;
	File10.open("output10.svg");
	File10<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;

	File10<<Result;

	File10<<endl<<"</svg>";
	File10.close();
	
	// == and != operators...
	
	cout<<"Compare that these two polygons are equal or not... "<<endl<<endl;
	for(int i=0; i<sizeoffArr; i++)
	{
		for(int j=i; j<sizeoffArr; j++ )
		{
			if(polygonArr[i] == polygonArr[j])
				cout<<"polygonArr["<< i <<"] and polygonArr["<<j<< "] are equal"<<endl;
	
			if(polygonArr[i] != polygonArr[j])
				cout<<"polygonArr["<< i <<"] and polygonArr["<<j<< "] are not equal"<<endl;
		}
	}
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	
	
	
	return 0;
}
