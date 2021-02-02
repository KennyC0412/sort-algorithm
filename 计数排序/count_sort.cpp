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
	//使用累加数组记录每一个元素最后的位置
	for (int i = 1; i < max - min; ++i) {
		count[i] += count[i - 1];
	}
	//对原数组中的每一个元素，倒序遍历，从count中查找其对应位置，保证排序稳定
	for (int i = length - 1; i >= 0; --i) {
		ret[--count[data[i]-min]] = data[i];
	}
	return ret;
}

int main()
{
	std::vector<int> data;
	int max = 100;
	int min = 40;
	std::srand(time(0));
	for (int i = 0; i < 100; ++i) {
		data.push_back(rand() % (max-min)+min);//产生范围为[min,max)
	}
	data = countSort(data,max,min);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}

