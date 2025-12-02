#include "KNNDouble.h"

KNNDouble::KNNDouble() : KNN<pair<double,double>>() {}

KNNDouble::KNNDouble(int k) : KNN<pair<double,double>>(k) {}

double KNNDouble::similarityMeasure(const pair<double,double>& a, const pair<double,double>& b) const {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}