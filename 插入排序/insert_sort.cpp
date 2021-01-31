#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void insertSort(std::vector<int>& data)
{
	int length = data.size();
	for (int i = 1; i < length; ++i) {
		for (int j = i - 1; j >= 0 && data[j+1] < data[j]; --j) {
			swap(data[j + 1], data[j]);
		}
	}
}

int main()
{
	std::vector<int> data;
	int input;
	while (std::cin >> input) {
		data.push_back(input);
	}
	insertSort(data);
	std::for_each(data.begin(), data.end(),[](int num) {std::cout << num << " "; });
	return 0;
}