#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Shape/ShapeBase.h"
#include "Shape/triangle.h"

class VanCollision : public olc::PixelGameEngine

{
public:
	VanCollision()
	{
		sAppName = "calculate points hull";
	}
	ShapeBase* shape0;
public:
	bool OnUserCreate() override
	{
		//应用创建的时候调用
		shape0 = new Triangle(Eigen::Vector2f(0.0, 0.0), Eigen::Vector2f(1.0, 1.0), Eigen::Vector2f(-1.0, -1.0), Eigen::Vector2f(0.0, 1.0));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//每一帧更新
		ClearBuffer(olc::BLACK, true);
		return true;
	}
};

int main()
{
	VanCollision* app = new VanCollision();
	if (app->Construct(256, 240, 4, 4))
		app->Start();

	return 0;
}