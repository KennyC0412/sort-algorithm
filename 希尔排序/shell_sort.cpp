#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
//空间复杂度O(1),时间复杂度O(n^1.3)
void shellSort(std::vector<int>& data)
{
	int length = data.size();
	//knuth序列
	int h = 1;
	while (h <= length / 3) {
		h = h * 3 + 1;
	}

	int gap = h;
	while (gap > 0) {
		for (int i = gap; i < length; ++i) {
			for (int j = i; j > gap - 1; j -= gap) {
				if (data[j] < data[j - gap])
					swap(data[j], data[j - gap]);
			}
		}
		gap = (gap - 1) / 3;
	}
}

int main()
{
	std::vector<int> data;
	int input;
	while (std::cin >> input) {
		data.push_back(input);
	}
	shellSort(data);
	std::for_each(data.begin(), data.end(), [](int num) {std::cout << num << " "; });
	return 0;
}
