#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int> arr)
{
	int mx = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(vector<int>& arr, int exp)
{
	vector<int> output(arr.size());
	int i, count[10] = {0};

	for (i = 0; i < arr.size(); i++)
		count[ (arr[i]/exp)%10 ]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = arr.size()- 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}


	for (i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}


void radixsort(vector<int> &arr)
{
	int m = getMax(arr);

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, exp);
}

void print(vector<int> arr)
{
   // cout<<"\nArshdeep 17103014\n\n\n\n";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

    cout<<endl;
}

int main()
{
	vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
	cout<<"Unsorted Array is: ";
	print(arr);

	radixsort(arr);
    cout<<"Unsorted Array is: ";

	print(arr);
	return 0;
}
