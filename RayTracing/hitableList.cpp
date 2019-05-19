#include "hitableList.h"

CHitableList::CHitableList(const std::vector<IHitable*>& vHitableList) : m_HitableList(vHitableList)
{
}

//*************************************************************************************
//Function:
bool CHitableList::hit(const CRay& vRay, Float vtMin, Float vtMax, SHitRecord& voRecord) const
{
	SHitRecord TempRecord;
	bool IsHitAnything = false;
	Float ClosestSoFar = vtMax;
	for (auto& TempHitable : m_HitableList)
	{
		if (TempHitable->hit(vRay, vtMin, vtMax, TempRecord))
		{
			IsHitAnything = true;
			if (TempRecord.t < ClosestSoFar)
			{
				ClosestSoFar = TempRecord.t;
				voRecord = TempRecord;
			}
		}
	}
	return IsHitAnything;
}
