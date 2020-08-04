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

//计算点集的凸包
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
		//应用创建的时候调用
		//随机在窗口中生成点集
		olc::vf2d p;
		for (int i = 0; i < pointNum; i++) {
			p = { (float)(rand() % ScreenWidth()) ,(float)(rand() % ScreenHeight()) };
			points.push_back(p);
		}

		//对points列表进行排序
		std::sort(points.begin(), points.end(),lessPoint);
		upEdge.push(*points.begin());
		downEdge.push(*points.begin());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//每一帧更新，这里每一帧进行一次计算，达到逐步更新的效果


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
