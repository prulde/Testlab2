#include "lr1.h"
#include <iostream>

Res countAndSum(const std::vector<int> &array)
{
	Res output;
	int size = array.size();
	if (size > 1024)
	{
		output.errors.push_back(oversized);
		return output;
	}

	int half = size / 2;
	int mod = size % 2;

	for (int i = 0; i < half; ++i)
	{
		int pos = half + i + mod;
		int sum = INT_MAX;

		long long c = (long long)array[i] + (long long)array[pos];
		if (c > INT_MAX || c < INT_MIN)
		{
			output.errors.push_back(overflow);
			return output;
		}
		sum = array[i] + array[pos];
		output.result.push_back(sum);

		if (output.min > sum)
		{
			output.min = sum;
			output.sizeChanged = true;
		}
	}

	if (mod == 1)
	{
		int sum = INT_MAX;
		long long c = (long long)array[half] + (long long)array[half];
		if (c > INT_MAX || c < INT_MIN)
		{
			output.errors.push_back(overflow);
			return output;
		}
		sum = array[half] + array[half];
		output.result.push_back(sum);

		if (output.min > sum)
		{
			output.min = sum;
			output.sizeChanged = true;
		}
	}
	return output;
}