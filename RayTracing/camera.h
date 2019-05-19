#pragma once
#include "ray.h"

class CCamera
{
public:
	CCamera() = default;
	~CCamera() = default;

	CRay dumpRay(Float u, Float v) const { return CRay(m_CameraPosition, m_LowerLeftCorner + u * m_Horizontal + v * m_Vertical - m_CameraPosition); }

private:
	Vec3 m_CameraPosition = Vec3(0.0);
	Vec3 m_LowerLeftCorner = Vec3(-2.0, -1.0, -1.0);
	Vec3 m_Horizontal = Vec3(4.0, 0.0, 0.0);
	Vec3 m_Vertical = Vec3(0.0, 2.0, 0.0);
};