#include "ShapeBase.h"



ShapeBase::ShapeBase(const Eigen::Vector2f& pos):shapePosition(pos)
{
}

ShapeBase::~ShapeBase()
{
}

void  ShapeBase::BaseSolver(float dt) {

	//�����ٶȺͽ��ٶ�
	shapeVelocity += shapeAcceleration * dt;
	shapeAngularVelocity += shapeAngularAcceleration * dt;

	

	//�������ٶȸ�������λ�ã����ٶȶ����Ĳ�Ӱ�죩
	shapePosition += shapeVelocity * dt;
}

void ShapeBase::drawShape()
{
	//Draw(shapePosition.x, shapePosition.y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
}
