#ifndef TECH_H
#define TECH_H

#include <fstream>
#include <vector>
#include <map>
#include "module.h"

using namespace std;

class Tech
{
public:
	
	Tech(fstream& infile, fstream& outfile) :
		_techNum(0) {
		parseInput(infile);
	}
	~Tech() {
	}

	int 	getTechNum() const			{ return _techNum; }
	const 	vector<Net*> getNets()			{ return _nets; }
	
	//void reportLibCell() const;
	//void reportInstance() const;
	//void reportDie() const;
	//void reportNet() const;
	
	void parseInput(fstream& infile);
	void setTechNum(const int technum)		{ _techNum = technum; }
	void parseOutput(fstream& outfile);
	
private:
	int					_techNum;
	map<string,map<string,Libcell>>		_libCell;
	map<string,Instance>			_instances;
	vector<Die>				_dies;		//[0]:top
	vector<int>				_termInfo;	//width,height,spacing
	vector<Net>				_nets;
};

#endif

