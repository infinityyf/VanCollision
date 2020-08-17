#pragma once
#ifndef  SHAPEBASE_H
#define SHAPEBASE_H

#include "Eigen/Dense"

//������ײ�����
class ShapeBase 
{
public:
	ShapeBase(const Eigen::Vector2f& pos);
	virtual ~ShapeBase();

	void BaseSolver(float dt);					//��������
	
	virtual void drawShape();					//��̬��Ϊ���๹���麯����������Ǿ�̬�󶨣�

protected:
	Eigen::Vector2f shapePosition;				//����
	Eigen::Vector2f shapeVelocity;				//���ٶ�
	Eigen::Vector2f shapeAngularVelocity;		//���ٶ�

	Eigen::Vector2f shapeAcceleration;			//���ٶ�
	Eigen::Vector2f shapeAngularAcceleration;	//�Ǽ��ٶ�

	float shapeMass;
};


#endif // ! SHAPEBASE_H

