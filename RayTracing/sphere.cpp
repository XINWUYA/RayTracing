#include "sphere.h"

CSphere::CSphere(const Vec3& vCenter, Float vRadius) : m_Center(vCenter), m_Radius(vRadius)
{
}

//*************************************************************************************
//Function:
bool CSphere::hit(const CRay& vRay, Float vtMin, Float vtMax, SHitRecord& voRecord) const
{
	Vec3 oc = vRay.getOrigininalVertex() - m_Center;
	Float a = glm::dot(vRay.getDirection(), vRay.getDirection());
	Float b = 2.0f * glm::dot(oc, vRay.getDirection());
	Float c = glm::dot(oc, oc) - m_Radius * m_Radius;
	Float Discriminant = b * b - 4.0f * a * c;
	if (Discriminant > 0.0f)
	{
		Float RootValue = (-b - std::sqrt(Discriminant)) / (2.0f * a);
		if (RootValue < vtMax && RootValue > vtMin)
		{
			voRecord.t = RootValue;
			voRecord.Pos = vRay.dumpPointAtParameter(RootValue);
			voRecord.Normal = glm::normalize(voRecord.Pos - m_Center);
			return true;
		}

		RootValue = (-b + std::sqrt(Discriminant)) / (2.0f * a);
		if (RootValue < vtMax && RootValue > vtMin)
		{
			voRecord.t = RootValue;
			voRecord.Pos = vRay.dumpPointAtParameter(RootValue);
			voRecord.Normal = glm::normalize(voRecord.Pos - m_Center);
			return true;
		}
	}

	return false;
}
