#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& lhs, int& rhs)
{
	int temp = lhs; 
	lhs = rhs;
	rhs = temp;
}

void selectionSort(std::vector<int> &data)
{
	int length = data.size();
	if (length < 2)
		return;
	for (int i = 0; i < length - 1; ++i) {
		int k = i;
		for (int j = i + 1; j < length; ++j) {
			if (data[j] < data[k])
				k = j;
		}
		if (k != i) 
			swap(data[i], data[k]);
	}
}

int main()
{
	std::vector<int> data;
	int input;
	while (std::cin >> input)
		data.push_back(input);
	selectionSort(data);
	std::for_each(data.begin(), data.end(), [](int ret) {std::cout << ret << " "; });
	return 0;
}
