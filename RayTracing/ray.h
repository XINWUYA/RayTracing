#pragma once
#include "common.h"

class CRay
{
public:
	CRay() = default;
	CRay(const Vec3& vOriginalVertex, const Vec3& vDirection) : m_OriginalVertex(vOriginalVertex), m_Direction(glm::normalize(vDirection)) { }
	~CRay() = default;

	const Vec3& getOrigininalVertex() const { return m_OriginalVertex; }
	const Vec3& getDirection() const { return m_Direction; }
	Vec3 dumpPointAtParameter(Float vParameter) const { return m_OriginalVertex + vParameter * m_Direction; }

private:
	Vec3 m_OriginalVertex;
	Vec3 m_Direction;
};