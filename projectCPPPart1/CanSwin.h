#ifndef __CANSWIM_H
#define __CANSWIM_H
class CanSwin
{
protected:
	int speedSwim;

public: // TODO s/swin/swim/
	CanSwin(int sps)
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
