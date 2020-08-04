#pragma once
#ifndef  POINT_H
#define POINT_H

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <vector>
#include <stack>

bool lessPoint(const olc::vf2d& lhs, const olc::vf2d& rhs) {
	if (lhs.x < rhs.x)return true;
	else if (lhs.x == rhs.x) {
		if (lhs.y < rhs.y) return true;
		return false;
	}
	else return false;
}

bool largePoint(const olc::vf2d& lhs, const olc::vf2d& rhs) {
	if (lhs.x > rhs.x)return true;
	else if (lhs.x == rhs.x) {
		if (lhs.y > rhs.y) return true;
		return false;
	}
	else return false;
}

//����㼯��͹��
class VanPointHull : public olc::PixelGameEngine

{
public:
	VanPointHull(int pointNum)
	{
		sAppName = "calculate points hull";
		this->pointNum = pointNum;
	}

public:
	bool OnUserCreate() override
	{
		//Ӧ�ô�����ʱ�����
		//����ڴ��������ɵ㼯
		olc::vf2d p;
		for (int i = 0; i < pointNum; i++) {
			p = { (float)(rand() % ScreenWidth()) ,(float)(rand() % ScreenHeight()) };
			points.push_back(p);
		}

		//��points�б��������
		std::sort(points.begin(), points.end(),lessPoint);
		upEdge.push(*points.begin());
		downEdge.push(*points.begin());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//ÿһ֡���£�����ÿһ֡����һ�μ��㣬�ﵽ�𲽸��µ�Ч��


		for (int i = 0; i < points.size(); i++) {
			Draw(points[i].x, points[i].y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		}
				
		return true;
	}

private:
	std::vector<olc::vf2d> points;
	std::stack<olc::vf2d> upEdge;
	std::stack<olc::vf2d> downEdge;
	int pointNum;
};

#endif // ! POINT_H
