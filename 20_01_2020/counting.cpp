
//Counting sort which takes negative numbers as well
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int> arr)
{
	int mx = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

int getMin(vector<int> arr)
{
	int mn = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] < mn)
			mn = arr[i];
	return mn;
}

void countSort(vector <int>& arr)
{
	int max = getMax(arr);
	int min = getMin(arr);
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for(int i = 0; i < arr.size(); i++)
		count[arr[i]-min]++;

	for(int i = 1; i < count.size(); i++)
		count[i] += count[i-1];


	for(int i = arr.size()-1; i >= 0; i--)
	{
		output[ count[arr[i]-min] -1 ] = arr[i];
			count[arr[i]-min]--;
	}

	for(int i=0; i < arr.size(); i++)
			arr[i] = output[i];
}

void printArray(vector <int> & arr)
{
  //  cout<<"\nArshdeep 17103014\n\n\n\n";

	for (int i=0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
		cout<<"Unsorted Array is: ";
		printArray (arr);

	countSort (arr);
	cout<<"Sorted Array is: ";
	printArray (arr);
	return 0;
}
