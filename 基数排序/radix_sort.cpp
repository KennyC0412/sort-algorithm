#include <iostream>
#include <vector>
#include <algorithm>
//�������ֵ��λ��
int calcFigure(const std::vector<int>& data )  
{
	int ret = 0;
	int max = 0;
	for (int x : data) {
		if (max < x)
			max = x;
	}
	while (max) {
		ret++;
		max /= 10;
	}
	return ret;
}
//ʱ�临�Ӷ�O(d(n+k)) dΪ���λ����nΪԪ�ظ����� k��ÿһλ���ֵķ�Χ
void radix_sort(std::vector<int>& data,int figure)
{
	int length = data.size();
	for (int i = 0,dev = 1; i < figure; ++i,dev*=10) {
		std::vector<std::vector<int>> count(10);
		for (int j = 0; j < length; ++j) {
			int num = (data[j] / dev) % 10;
			count[num].push_back(data[j]);
		}
		int index = 0;
		for (int k = 0; k < 10; k++) {
			for (int i = 0; i < count[k].size(); ++i) {
				data[index++] = count[k][i];
			}
		}
	}
}

int main()
{
	std::vector<int> data;
	std::srand(time(0));
	for (int i = 0; i < 50; ++i) {
		data.push_back(rand() % 1024);
	}
	int max = 0;
	for (auto x : data) {
		if (max < x)
			x = max;
	}
	int figure = calcFigure(data);
	radix_sort(data,figure);
	std::for_each(data.begin(), data.end(), [](int data) { std::cout << data << ' '; });
	return 0;
}