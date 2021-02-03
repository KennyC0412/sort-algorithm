#include <iostream>
#include <vector>
#include <algorithm>

void swap(int &lhs,int &rhs) 
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
void bubbleSort(std::vector<int>& data)
{
	bool swapFlag = false;
	int length = data.size();
	if (length < 2)
		return;
	for (int i = 0; i < length-1; ++i) {
		for (int j = 0; j < length-1-i; ++j) {
			if (data[j] > data[j + 1]) {
				swapFlag |= 0x01;
				swap(data[j], data[j + 1]);
			}
		}
		if (!swapFlag)
			break;
		else
			swapFlag &= 0x0;
	}
}

int main() 
{
	std::vector<int> data;
	srand(time(0));
	for (int i = 0; i < 50; ++i) {
		data.push_back(rand() % 100);
	}
	bubbleSort(data);
	std::for_each(data.begin(), data.end(), []( int ret) {std::cout << ret << ' '; });
	return 0;
}