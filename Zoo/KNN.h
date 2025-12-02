#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class KNN
{
	private:
		int k;
	public:
		KNN() : k(3) {};
		KNN(int k) : k(k) {};

		int getK() const { return k; };

		virtual double similarityMeasure(const T&, const T&) const = 0;

		vector<int> findNearestNeighbours(const vector<T>& trainData, const T& target) const
		{
			if (trainData.size() < k)
			{
				throw invalid_argument("Dataset size is smaller than k");
			}

			vector<pair<double, int>> distances;

			for (size_t i = 0; i < trainData.size(); ++i)
			{
				double distance = similarityMeasure(trainData[i], target);
				distances.push_back(make_pair(distance, i));
			}

			sort(distances.begin(), distances.end(),
				[](const pair<double, int>& a, const pair<double, int>& b)
				{
					return a.first < b.first;
				});

			vector<int> neighbors;
			for (int i = 0; i < k; ++i)
			{
				neighbors.push_back(distances[i].second);
			}

			return neighbors;
		};
};