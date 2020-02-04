#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(vector<float> &arr)
{
	vector<float> b[arr.size()];

	for (int i=0; i< arr.size(); i++)
	{
	int bi = arr.size()*arr[i];
	b[bi].push_back(arr[i]);
	}

	for (int i=0; i<arr.size(); i++)
	sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < arr.size(); i++){

	for (int j = 0; j < b[i].size(); j++)
		arr[index++] = b[i][j];

		b[i].clear();

	}

}

int main()
{
    vector<float> arr= {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    cout<<"Unsorted Array is: ";
    for (int i=0; i<arr.size(); i++)
	cout << arr[i] << " ";
	cout<<endl;

	bucketSort(arr);

   // cout<<"\nArshdeep 17103014\n\n\n\n";
	cout << "Sorted array is \n";
	for (int i=0; i<arr.size(); i++)
	cout << arr[i] << " ";
	cout<<endl;
	return 0;
}
