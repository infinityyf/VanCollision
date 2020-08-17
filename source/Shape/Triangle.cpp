#include "triangle.h"


Triangle::Triangle(const Eigen::Vector2f& pos, const Eigen::Vector2f& pos0, const Eigen::Vector2f& pos1, const Eigen::Vector2f& pos2):ShapeBase(pos),delta0(pos0-pos), delta1(pos1 - pos), delta2(pos2 - pos)
{
}

Triangle::~Triangle()
{
}

void Triangle::solver(float dt)
{
	BaseSolver(dt);

	//更新三个点
	position0 = shapePosition + delta0;
	position1 = shapePosition + delta1;
	position2 = shapePosition + delta2;
}

void Triangle::drawShape()
{
	ShapeBase::drawShape();
	//Draw(position0.x, position0.y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
	//Draw(position1.x, position1.y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
	//Draw(position2.x, position2.y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
}
