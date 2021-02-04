//空间复杂度O(logn) 平均时间复杂度O(nlogn) 最坏O(n^2)(逆序或正序)
#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& lhs, int& rhs) 
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

//随机选择一个数与中轴交换，避免最坏情况
int random(int leftBound,int rightBound)
{
		int ret = 0;
		for (int i = 0; i < 10; ++i) {
			ret += rand() % (rightBound - leftBound) + leftBound;
		}
	return ret/10;
}

std::vector<int> partition(std::vector<int>& data, int left, int right)
{
	std::vector<int> ret(2);
	int rand = random(left,right);
	swap(data[right], data[rand]);
	int pivot = data[right];

	int l = left;
	int less = l - 1;
	int more = right;
	while (l < more) {
		if (data[l] < pivot) {
			swap(data[++less], data[l++]);
		}
		else if (data[l] > pivot) {
			swap(data[--more], data[l]);
		}
		else {
			l++;
		}
	}
	swap(data[right], data[more++]);
	ret[0] = less;
	ret[1] = more;
	return ret;
}

void quickSort(std::vector<int>& data, int left, int right) 
{
	if (left >= right)
		return;
	if(left < right) {
		std::vector<int> range = partition(data, left, right);
		quickSort(data, left, range[0]);
		quickSort(data, range[1], right);
	}
}


int main()
{
	std::vector<int> data;
	std::srand(time(0));
	for (int i = 0; i < 100; ++i) {
		data.push_back(rand()%20);
	}
	quickSort(data, 0, data.size() - 1);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}