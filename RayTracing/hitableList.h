#pragma once
#include <vector>
#include "hitable.h"

class CHitableList : public IHitable
{
public:
	CHitableList() = default;
	CHitableList(const std::vector<IHitable*>& vHitableList);
	~CHitableList() = default;

	virtual bool hit(const CRay& vRay, Float vtMin, Float vtMax, SHitRecord& voRecord) const override;

private:
	std::vector<IHitable*> m_HitableList;
};

