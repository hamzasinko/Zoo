#pragma once
#include "KNN.h"

class KNNDouble : public KNN<pair<double,double>>
{
	public:
		KNNDouble();
		KNNDouble(int);
		double similarityMeasure(const pair<double,double>&, const pair<double,double>&) const override;
};

