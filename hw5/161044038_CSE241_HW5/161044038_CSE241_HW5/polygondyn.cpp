
#include "polygondyn.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

namespace Shapes_namespace {

PolygonDyn::PolygonDyn(Rectangle Rectangle_I) noexcept {

		AreaOfShape=Rectangle_I.area();
		PerimeterOfShape=Rectangle_I.perimeter();
		
		sizeOfPoints=4;
		pointsOfShapes=new Polygon*[sizeOfPoints];
		color=Rectangle_I.getColor();
		
		PolygonDyn *tempPoint=new PolygonDyn;
		tempPoint->setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y());
		pointsOfShapes[0]=tempPoint;

		tempPoint=new PolygonDyn;
		tempPoint->setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y());
		pointsOfShapes[1]=tempPoint;

		tempPoint=new PolygonDyn;
		tempPoint->setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		pointsOfShapes[2]=tempPoint;

		tempPoint=new PolygonDyn;
		tempPoint->setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		pointsOfShapes[3]=tempPoint;
}

PolygonDyn::PolygonDyn(Circle Circle_I) noexcept {

		double PI=3.14159;
		int tX=1,tY=-1;
		
		AreaOfShape=Circle_I.area();
		PerimeterOfShape=Circle_I.perimeter();
		
		sizeOfPoints=100;
		pointsOfShapes=new Polygon*[sizeOfPoints];
		color=Circle_I.getColor();
		
		PolygonDyn *tempPoint=new PolygonDyn;
		tempPoint->setLocations(Circle_I.getLoc_X(),Circle_I.getLoc_Y()-Circle_I.getRadius());
		pointsOfShapes[0]=tempPoint;
		
		for(int i=1; i<sizeOfPoints; i++)
		{
			tempPoint=new PolygonDyn;
			tempPoint->setLocations(Circle_I.getLoc_X()+(tX*Circle_I.getRadius()*sin(i*PI/50)),Circle_I.getLoc_Y()+(tY*Circle_I.getRadius()*cos(i*PI/50)) );
			pointsOfShapes[i]=tempPoint;
		}
}

PolygonDyn::PolygonDyn(Triangle Triangle_I) noexcept {

		AreaOfShape=Triangle_I.area();
		PerimeterOfShape=Triangle_I.perimeter();
		
		sizeOfPoints=3;
		pointsOfShapes=new Polygon*[sizeOfPoints];
		color=Triangle_I.getColor();
		
		PolygonDyn *tempPoint=new PolygonDyn;
		if(Triangle_I.getRotate()==0)
		{
			tempPoint->setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y());
			pointsOfShapes[0]=tempPoint;
			
			tempPoint=new PolygonDyn;
			tempPoint->setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
			pointsOfShapes[1]=tempPoint;
			
			tempPoint=new PolygonDyn;
			tempPoint->setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
			pointsOfShapes[2]=tempPoint;
		}
		else if(Triangle_I.getRotate()==1)
		{
			tempPoint->setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
			pointsOfShapes[0]=tempPoint;
			
			tempPoint=new PolygonDyn;
			tempPoint->setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
			pointsOfShapes[1]=tempPoint;
			
			tempPoint=new PolygonDyn;
			tempPoint->setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y()+Triangle_I.getHeight());
			pointsOfShapes[2]=tempPoint;
		}
		else
			cout<<"THERE IS A PROBLEM IN CODE!!"<<endl;
}

PolygonDyn::PolygonDyn(const PolygonDyn & copyPolygon) noexcept {

		sizeOfPoints=copyPolygon.sizeOfPoints;
		AreaOfShape=copyPolygon.area();
		PerimeterOfShape=copyPolygon.perimeter();
		
		pointsOfShapes=new Polygon*[sizeOfPoints];
		color=copyPolygon.color;
		
		for(int i=0; i<sizeOfPoints; i++)
			pointsOfShapes[i]=copyPolygon.pointsOfShapes[i];
}

PolygonDyn::~PolygonDyn() {

		delete []pointsOfShapes;
}

PolygonDyn& PolygonDyn::operator =(const PolygonDyn & copyPolygon) noexcept {

		if(this==&copyPolygon)
			return *this;
		
		AreaOfShape=copyPolygon.area();
		PerimeterOfShape=copyPolygon.perimeter();
		
		delete []this->pointsOfShapes;
		this->sizeOfPoints=copyPolygon.sizeOfPoints;
		this->pointsOfShapes=new Polygon*[this->sizeOfPoints];
		this->color=copyPolygon.color;
		
		for(int i=0; i<this->sizeOfPoints; i++)
			this->pointsOfShapes[i]=copyPolygon.pointsOfShapes[i];
			
		return *this;	
}

void PolygonDyn::draw(ostream & outs) noexcept {

		outs<<"<polygon points=\"";
		for(int i=0; i<this->getSize(); i++)
		{
			outs<<this->pointsOfShapes[i]->getLocX()<<",";
			outs<<this->pointsOfShapes[i]->getLocY()<<" ";
		}
		outs<<"\" stroke=\"black\" stroke-width=\"0.5\" ";
		outs<<"fill=\""<<this->getColor()<<"\"/>"<<endl;
}


}
