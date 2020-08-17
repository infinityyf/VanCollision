#pragma once
#ifndef  SHAPEBASE_H
#define SHAPEBASE_H

#include "Eigen/Dense"

//定义碰撞体基类
class ShapeBase 
{
public:
	ShapeBase(const Eigen::Vector2f& pos);
	virtual ~ShapeBase();

	void BaseSolver(float dt);					//基础更新
	
	virtual void drawShape();					//多态，为子类构造虚函数表（否则就是静态绑定）

protected:
	Eigen::Vector2f shapePosition;				//质心
	Eigen::Vector2f shapeVelocity;				//线速度
	Eigen::Vector2f shapeAngularVelocity;		//角速度

	Eigen::Vector2f shapeAcceleration;			//加速度
	Eigen::Vector2f shapeAngularAcceleration;	//角加速度

	float shapeMass;
};


#endif // ! SHAPEBASE_H

