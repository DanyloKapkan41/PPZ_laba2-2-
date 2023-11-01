#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 100000 + 1;
			i++;
			filling(nums, i, n, mode);
		}
	} else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < 1 || nums[i]>100000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int*& nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
int breaking(int numb)
{
	int x = 0, n = numb;
	while (n > 0)
	{
		n = n / 10;
		x++;
	}
	return x;
}
int finding(int* nums, int n)
{
	int i = 0, max = 0;
	while (i < n)
	{
		if(breaking(nums[i])%2==0)
			max++;
		i++;
	}
	return max;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 500): ";
		cin >> n;
	} while (n <= 0 || n >= 500);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	cout << "\nResult: " << finding(nums, n);
}
