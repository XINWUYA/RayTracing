#pragma once
#include "hitable.h"

class CSphere : public IHitable
{
public:
	CSphere() = default;
	CSphere(const Vec3& vCenter, Float vRadius);
	~CSphere() = default;

	virtual bool hit(const CRay& vRay, Float vtMin, Float vtMax, SHitRecord& voRecord) const override;

private:
	Vec3 m_Center = Vec3(0.0, 0.0, -1.0);
	Float m_Radius = 0.5f;
};