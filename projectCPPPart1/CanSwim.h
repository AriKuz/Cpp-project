#ifndef __CANSWIM_H
#define __CANSWIM_H
class CanSwim
{
protected:
	int speedSwim;

public:
	CanSwim(int sps)
	{
		setSpeed(sps);
	}
	virtual void swim() const = 0;
	void setSpeed(int speed) 
	{
		speedSwim = speed;
	}
	int getSpeed() 
	{
		return speedSwim;
	}

};
#endif
