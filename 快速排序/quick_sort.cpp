//�ռ临�Ӷ�O(n) ƽ��ʱ�临�Ӷ�O(nlogn) �O(n^2)(���������)
#include <iostream>
#include <vector>
#include <algorithm>

void swap(int& lhs, int& rhs) 
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

//���ѡ��һ���������ύ������������
int random(int leftBound,int rightBound)
{
		int ret = 0;
		for (int i = 0; i < 10; ++i) {
			ret += rand() % (rightBound - leftBound) + leftBound;
		}
	return ret/10;
}
int partition(std::vector<int>& data, int left, int right)
{
	int rand = random(left,right);
	swap(data[right], data[rand]);
	int pivot = data[right];
	int l = left;
	int r = right - 1;
	while (l <= r) {
		while (l <= r && data[l] <= pivot)
			++l;
		while (l <= r && data[r] > pivot)
			--r;
		if(l < r)
			swap(data[l], data[r]);
	}
	swap(data[right], data[l]);
	return l;
}

void quickSort(std::vector<int>& data, int left, int right) 
{
	if (left >= right)
		return;
	if(left < right) {
		int mid = partition(data, left, right);
		quickSort(data, left, mid-1);
		quickSort(data, mid + 1, right);
	}
}


int main()
{
	std::vector<int> data;
	std::srand(time(0));
	for (int i = 0; i < 30; ++i) {
		data.push_back(rand());
	}
	quickSort(data, 0, data.size() - 1);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}