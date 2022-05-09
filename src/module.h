#ifndef MODULE_H
#define MODULE_H

#include <vector>
#include <map>
#include <string>
#include "tech.h"

using namespace std;

class Libcell
{
public:
	Libcell(string& name, int width, int height ,int pinCount) :_name(name), _width(width), _height(height), _pinCount(pinCount) { }
	~Libcell()  { }

	const string getName()				{ return _name; }
	const int getWidth()				{ return _width; }
	const int getHeight()				{ return _height; }
	const int getPinCount()				{ return _pinCount; }
	Pin getPin(string name)				{ return _pins[name]; }
	
	void addPin(string name,Pin pin)	{ _pins.insert( pair<string,Pin>(name,pin) ); }

protected:
	string				_name;
	int					_width;    
	int					_height;
	int  		  		_pinCount;
	map<string,Pin>		_pins;
};

class Die
{
public:
	Die(string& techName) :_techName(name) {
		_dieSize = vectpr<pair<int,int>>(2);
		_rowInfo = vector<int>(5);
		}
	~Die() { }

	const string getTechName()			{ return _techName; }
	const int getDiePosX1()				{ return _dieSize[0].first; }
	const int getDiePosY1()				{ return _dieSize[0].second; }
	const int getDiePosX2()				{ return _dieSize[1].first; }
	const int getDiePosY2()				{ return _dieSize[1].second; }
	const int getRowPosX()				{ return _rowInfo[0]; }
	const int getRowPosY()				{ return _rowInfo[1]; }
	const int getRowLength()			{ return _rowInfo[2]; }
	const int getRowGeight()			{ return _rowInfo[3]; }
	const int getRowCount()				{ return _rowInfo[4]; }
	const int getMaxUtil()				{ return _maxUtil; }
	
	void setMaxUtil(double maxUtil) 	{ _maxUtil = maxUtil }
	void setDieSize(int x1,int y1,int x2,int y2) { 
	_dieSize[0] = make_pair(x1,y1);		_dieSize[1] = make_pair(x2,y2);
	}
	void setRow(int posX, int posY, int length, int height, int count) {
		vector[0] = posX;	vector[1] = posY;	vector[2] = length;
		vector[3] = height;	vector[4] = count;
	}

private:
	string 					_techName;
    vector<pair<int,int>>	_dieSize = vector<pair<int,int>>(2);	//[0]:(x1,y1),[1]:(x2,y2) 
	vector<int>				_rowInfo = vector<int>(5);				//x,y,length,height,count
	double					_maxUtil;	
};


class Instance : public Pin
{
public:
	Instance(string& name) : Pin(name, 0, 0), _tb(0) { 
	}
	~Instance() { }

	const string getTechName()			{ return _techName; }
	const int getTb()					{ return _tb; }
	
	void setTb(int tb) 					{ _tb = tb; }
	void setTechName(string techName) 	{ _techName = techName; }
	
private:
    //string		_cellName;
	string		_techName;
	int			_tb;		//0:top 1:bottom
};


class Net
{
public:
    Net(string name, int pinnum) :_name(name), _pinNum(pinnum) {
	}
    ~Net()  { }

	const string getNetName()						{ return _name; }
	const int getPinNum()							{ return _pinNum; }
	const vector<pair<string,string>> getWireList()	{ return _connections; }
	
	void addConnect(pair<string,string> wire)		{ _connections.push_back(wire); }
	
private:
	string							_name;
	int								_pinNum;
	vector<pair<string,string>>		_connections;
};

class Pin
{
public:
    Pin(string name, int x, int y) :_name(name), _x(x), _y(y) {
	}
    ~Pin()  { }

	const string getName()		{ return _name; }
	const int getPosX()			{ return _x }
	const int getPosY()			{ return _y }
	
	void setName(string name) 	{ _name = name; }
	void setPos(int x, int y)	{
		_x = x;		_y = y;
	}

private:
	string		_name;
	int			_x;
	int			_y;
};

#endif  // MODULE_H
