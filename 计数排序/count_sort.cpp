//时间复杂度O(n+k) 空间复杂度O(n+k)
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> countSort(std::vector<int> &data,int max,int min)
{
	int length = data.size();
	std::vector<int> ret(length);
	std::vector<int> count(max-min,0);
	for (int i = 0; i < length; ++i) {
		count[data[i]-min]++;
	}
	for (int i = 0,j = 0; j < count.size(); ++j) {
		while (count[j]--) {
			ret[i++] = j+min;
		}
	}
	return ret;
}

int main()
{
	std::vector<int> data;
	int max = 100;
	int min = 40;
	std::srand(time(0));
	for (int i = 0; i < 200; ++i) {
		data.push_back(rand() % (max-min)+min);//产生范围为[min,max)
	}
	data = countSort(data,max,min);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}

