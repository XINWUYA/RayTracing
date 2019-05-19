#pragma once
#include "ray.h"

struct SHitRecord
{
	Float t = 0.0f;
	Vec3 Pos;
	Vec3 Normal;
};

class IHitable
{
public:
	IHitable() = default;
	virtual ~IHitable() = default;

	virtual bool hit(const CRay& vRay, Float vtMin, Float vtMax, SHitRecord& voRecord) const = 0;
};