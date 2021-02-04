#include <iostream>
#include <vector>
#include <algorithm>


void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void heapInsert(std::vector<int>& data,int index)
{
	while (index) {
		int p_index = (index - 1) >> 1;
		if (data[p_index] > data[index]) {
			swap(data[index], data[p_index]);
			index = p_index;
		}
		else {
			break;
		}
	}
}

void heapify(std::vector<int>& data,int index,int heapsize)
{
	int left = index * 2 + 1;
		while (left < heapsize) {
			int min =(left +1 <= heapsize && data[left + 1] < data[left]) ? left +1 : left;
			if (data[index] < data[min])
				break;
			swap(data[index], data[min]);
			index = min;
			left = index * 2 + 1;
		}
}

void heapSort(std::vector<int> &data)
{
	int length = data.size();
	if (length < 2)
		return;
	for (int i = 0; i < length; ++i) {
		heapInsert(data, i);
	}
	int heapsize = length;
	while (heapsize--) {
		int cur = 0;
		int left = cur * 2 + 1;
		int index = heapsize;
		swap(data[cur], data[index--]);
		heapify(data, cur,index);
	}
}

int main()
{
	std::vector<int> data;
	std::srand(time(0));
	for (int i = 0; i < 100; ++i) {
		data.push_back(rand() % 20);
	}
	heapSort(data);
	std::for_each(data.rbegin(), data.rend(), [](int data) { std::cout << data << ' '; });
	return 0;

}