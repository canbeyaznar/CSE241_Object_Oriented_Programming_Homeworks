
#include "polygonvect.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

namespace Shapes_namespace {

	PolygonVect::PolygonVect(Rectangle Rectangle_I) noexcept {
	
			color=Rectangle_I.getColor();
			AreaOfShape=Rectangle_I.area();
			PerimeterOfShape=Rectangle_I.perimeter();
				
			PolygonVect *tempPoint=new PolygonVect;
			tempPoint->setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y());
			pointsOfShapes.push_back(tempPoint);
	
			tempPoint=new PolygonVect;
			tempPoint->setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y());
			pointsOfShapes.push_back(tempPoint);
	
			tempPoint=new PolygonVect;
			tempPoint->setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
			pointsOfShapes.push_back(tempPoint);
	
			tempPoint=new PolygonVect;
			tempPoint->setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
			pointsOfShapes.push_back(tempPoint);
	}
	
	PolygonVect::PolygonVect(Circle Circle_I) noexcept {
	
			double PI=3.14159;
			int tX=1,tY=-1;
			
			color=Circle_I.getColor();
			AreaOfShape=Circle_I.area();
			PerimeterOfShape=Circle_I.perimeter();
			
			PolygonVect *tempPoint=new PolygonVect;
			tempPoint->setLocations(Circle_I.getLoc_X(),Circle_I.getLoc_Y()-Circle_I.getRadius());
			pointsOfShapes.push_back(tempPoint);
			
			for(int i=1; i<100; i++)
			{
				tempPoint=new PolygonVect;
				tempPoint->setLocations(Circle_I.getLoc_X()+(tX*Circle_I.getRadius()*sin(i*PI/50)),Circle_I.getLoc_Y()+(tY*Circle_I.getRadius()*cos(i*PI/50)) );
				pointsOfShapes.push_back(tempPoint);
			}
	}
	
	PolygonVect::PolygonVect(Triangle Triangle_I) noexcept {
	
			color=Triangle_I.getColor();
			AreaOfShape=Triangle_I.area();
			PerimeterOfShape=Triangle_I.perimeter();
			
			PolygonVect *tempPoint=new PolygonVect;
			if(Triangle_I.getRotate()==0)
			{
				tempPoint->setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y());
				pointsOfShapes.push_back(tempPoint);
				
				tempPoint=new PolygonVect;
				tempPoint->setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
				pointsOfShapes.push_back(tempPoint);
				
				tempPoint=new PolygonVect;
				tempPoint->setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
				pointsOfShapes.push_back(tempPoint);
			}
			else if(Triangle_I.getRotate()==1)
			{
				tempPoint->setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
				pointsOfShapes.push_back(tempPoint);
				
				tempPoint=new PolygonVect;
				tempPoint->setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
				pointsOfShapes.push_back(tempPoint);
				
				tempPoint=new PolygonVect;
				tempPoint->setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y()+Triangle_I.getHeight());
				pointsOfShapes.push_back(tempPoint);
			}
			else
				cout<<"THERE IS A PROBLEM IN CODE!!"<<endl;
	}
	
	PolygonVect::PolygonVect(const PolygonVect & copyPolygon) noexcept {
	
			color=copyPolygon.color;
			AreaOfShape=copyPolygon.area();
			PerimeterOfShape=copyPolygon.perimeter();
			
			for(int i=0; i<pointsOfShapes.size(); i++)
				pointsOfShapes.push_back(copyPolygon.pointsOfShapes[i]);
	}
	
	PolygonVect::~PolygonVect() {
	
			this->pointsOfShapes.clear();
			this->pointsOfShapes.shrink_to_fit();
	}
	
	PolygonVect& PolygonVect::operator =(const PolygonVect & copyPolygon) noexcept {
	
			if(this==&copyPolygon)
				return *this;
			
			this->AreaOfShape=copyPolygon.area();
			this->PerimeterOfShape=copyPolygon.perimeter();
			this->pointsOfShapes.clear();
			this->pointsOfShapes.shrink_to_fit();
			this->color=copyPolygon.color;
			
			for(int i=0; i<copyPolygon.getSize(); i++)
				this->pointsOfShapes.push_back(copyPolygon.pointsOfShapes[i]);
				
			return *this;	
	}
	
	void PolygonVect::draw(ostream & outs) noexcept {
	
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
