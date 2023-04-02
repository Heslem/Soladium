#pragma once

class Component
{
public:
	Component();
	virtual ~Component();
	Component(const Component&) = delete;

	virtual void start() = 0;
	virtual void update() = 0;
protected:
};