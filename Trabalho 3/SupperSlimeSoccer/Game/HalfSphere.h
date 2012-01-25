#ifndef _SSS_HALFSPHERE_
#define _SSS_HALFSPHERE_

#pragma once
class HalfSphere
{
private:
	int _radius;

public:
	HalfSphere(int radius);
	~HalfSphere(void);

	void Draw(short detailLevel); 
};

#endif