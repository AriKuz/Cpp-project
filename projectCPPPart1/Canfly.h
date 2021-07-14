#ifndef __CANFLY_H
#define __CANFLY_H
class Canfly
{
protected:
	int speedOfFlight;

public:
	Canfly(int sof);
	virtual void fly() const = 0 ;
	int getSpeed() { return speedOfFlight; }
	void setSpeed(int s) { speedOfFlight = s; }
};
#endif
