#pragma once

class Object
{
public:
	Object();
	~Object();
	virtual int value() = 0;
	virtual void show() = 0;
	virtual void input() = 0;

};

