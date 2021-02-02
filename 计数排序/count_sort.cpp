//时间复杂度O(n+k) 空间复杂度O(n+k)
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> countSort(std::vector<int> &data,int max)
{
	int length = data.size();
	std::vector<int> ret(length);
	std::vector<int> count(max,0);
	for (int i = 0; i < length; ++i) {
		count[data[i]]++;
	}
	for (int i = 0,j = 0; j < count.size(); ++j) {
		while (count[j]--) {
			ret[i++] = j;
		}
	}
	return ret;
}

int main()
{
	std::vector<int> data;
	int max = 100;
	std::srand(time(0));
	for (int i = 0; i < 100; ++i) {
		data.push_back(rand() % max);
	}
	data = countSort(data,max);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}

