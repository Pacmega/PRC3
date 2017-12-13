#ifndef VALVEROW_H_
#define VALVEROW_H_ 

class valveRow
{
public:
	valveRow();
	~valveRow();

	int open();
	int close();

private:
	bool opened;
	
};

#endif