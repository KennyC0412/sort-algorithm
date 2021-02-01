#include <iostream>
#include <vector>
#include <algorithm>
//时间复杂度O(n*logn) 空间复杂度O(n)

std::vector<int> merge(std::vector<int>& data, int left, int right, int bound)
{
	int mid = right - 1;
	std::vector<int> ret;
	while (left <= mid && right <= bound) {
		if (data[left] <= data[right]) {
			ret.push_back(data[left]);
			left++;
		}
		else {
			ret.push_back(data[right]);
			right++;
		}
	}
	while (left <= mid) {
		ret.push_back(data[left++]);
	}
	while (right <= bound) {
		ret.push_back(data[right++]);
	}
	return ret;
}

void mergeSort(std::vector<int>& data, int left, int right) {
	if (left >= right)
		return;
	//分隔数组
	int mid = left + ((right - left) >> 1);
	//对左部分进行排序
	mergeSort(data, left, mid);
	//对右部分进行排序
	mergeSort(data, mid + 1,right);
	//合并数组
	std::vector<int> temp = merge(data, left, mid+1, right);
	for (auto x : temp) {
		data[left++] = x;
	}
}


int main() 
{
	std::vector<int> data;
	std::srand(time(0));
	for (int i = 0; i < 30; i++) {
		data.push_back(rand()%100);
	}
	mergeSort(data,0,data.size()-1);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}