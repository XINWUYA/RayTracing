#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <random>
#include <time.h>
#include "ray.h" 
#include "hitableList.h"
#include "sphere.h"
#include "camera.h"

//*************************************************************************************
//Function:
std::default_random_engine RANDON_SEED;
Float generateRandomFloat(Float vMin, Float vMax)
{
	std::uniform_real_distribution<Float> random(vMin, vMax);
	return random(RANDON_SEED);
}

//*************************************************************************************
//Function:
Vec3 getARandomPointInUnitSphere()
{
	Vec3 Point;
	do
	{
		Point = 2.0f * Vec3(generateRandomFloat(-1.0, 1.0), generateRandomFloat(-1.0, 1.0), generateRandomFloat(-1.0, 1.0)) - Vec3(1.0);
	} while (glm::dot(Point, Point) >= 1.0f);

	return Point;
}

//*************************************************************************************
//Function:
Vec3 computeColor(const CRay& vRay, const IHitable* vWorld)
{
	SHitRecord HitRecord;
	if (vWorld->hit(vRay, 0.00001, FLT_MAX, HitRecord))
	{
		Vec3 Target = HitRecord.Pos + HitRecord.Normal + getARandomPointInUnitSphere();
		return 0.5f * computeColor(CRay(HitRecord.Pos, Target - HitRecord.Pos), vWorld);//0.5f表示每次反射将只有0.5的能量被反射出来，另外一半被物体吸收
	}
	Float t = 0.5f * (vRay.getDirection().y + 1.0f);//将范围修改到[0,1]
	return (1.0f - t) * Vec3(1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main()
{
	int WindowWidth = 200;
	int WindowHeight = 100;
	int NumSampler = 100;

	std::ostringstream OutStringStream;
	OutStringStream << "P3\n" << WindowWidth << " " << WindowHeight << "\n255\n" << std::endl;

	std::vector<IHitable*> HitableList;
	auto pHitable0 = new CSphere(Vec3(0.0, -100.5, -1.0), 100.0f);
	auto pHitable1 = new CSphere(Vec3(0.0, 0.0, -1.0), 0.5f);
	HitableList.push_back(pHitable1);
	HitableList.push_back(pHitable0);
	IHitable* pWorld = new CHitableList(HitableList);

	CCamera Camera;

	for (int RowIdx = WindowHeight - 1; RowIdx >= 0; --RowIdx)
	{
		for (int ColIdx = 0; ColIdx < WindowWidth; ++ColIdx)
		{
			Vec3 Color = Vec3(0.0);
			for (int i = 0; i < NumSampler; ++i)
			{
				Float u = Float(ColIdx + generateRandomFloat(0.0f, 1.0f)) / Float(WindowWidth);
				Float v = Float(RowIdx + generateRandomFloat(0.0f, 1.0f)) / Float(WindowHeight);
				
				Color += computeColor(Camera.dumpRay(u, v), pWorld);
			}
			Color /= Float(NumSampler);
			Color = sqrt(Color);//Gamma Correction

			int R = int(255.99f * Color.r);
			int G = int(255.99f * Color.g);
			int B = int(255.99f * Color.b);

			OutStringStream << R << " " << G << " " << B << std::endl;
		}
	}

	std::ofstream OutFile("pic.ppm");
	std::ostreambuf_iterator<char> out(OutFile);
	std::string Str = OutStringStream.str();
	std::copy(Str.begin(), Str.end(), out);
	OutFile.close();
	return 0;
}