#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "ShapeBase.h"

class Triangle: public ShapeBase
{
public:
	Triangle(const Eigen::Vector2f& pos, const Eigen::Vector2f& pos0, const Eigen::Vector2f& pos1, const Eigen::Vector2f& pos2);
	~Triangle();

	void solver(float dt);

	void drawShape();

private:
	Eigen::Vector2f position0;
	Eigen::Vector2f delta0;
	Eigen::Vector2f position1;
	Eigen::Vector2f delta1;
	Eigen::Vector2f position2;
	Eigen::Vector2f delta2;
};


#endif // !TRIANGLE_H
