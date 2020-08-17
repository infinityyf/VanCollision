#include "ShapeBase.h"



ShapeBase::ShapeBase(const Eigen::Vector2f& pos):shapePosition(pos)
{
}

ShapeBase::~ShapeBase()
{
}

void  ShapeBase::BaseSolver(float dt) {

	//更新速度和角速度
	shapeVelocity += shapeAcceleration * dt;
	shapeAngularVelocity += shapeAngularAcceleration * dt;

	

	//根据线速度更新质心位置（角速度对质心不影响）
	shapePosition += shapeVelocity * dt;
}

void ShapeBase::drawShape()
{
	//Draw(shapePosition.x, shapePosition.y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
}
