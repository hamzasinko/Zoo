#pragma once
#include "KNN.h"

class KNNString : public KNN<string>
{
	public:
		KNNString();
		KNNString(int);
		double similarityMeasure(const string&, const string&) const override;
};