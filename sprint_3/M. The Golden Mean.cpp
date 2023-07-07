#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	int A_size = nums1.size();
	int B_size = nums2.size();

	if (B_size < A_size)
		return findMedianSortedArrays(nums2,nums1);

	int total_size = A_size + B_size;
	int left = 0;
	int right = A_size;

	while (left <= right) {
		int i = (left + right) / 2;
		int j = (total_size + 1) / 2 - i;

		int A_left = i > 0 ? nums1[i - 1] : INT_MIN;
		int B_left = j > 0 ? nums2[j - 1] : INT_MIN;
		int A_right = i < A_size ? nums1[i] : INT_MAX;
		int B_right = j  < B_size ? nums2[j] : INT_MAX;

		if (A_left <= B_right && B_left <= A_right) {
			if (total_size % 2 == 0)
				return (double)(max(A_left, B_left) + min(A_right, B_right)) / 2;
			else
				return max(A_left, B_left);
			break;
		}
		else if (A_left > B_right) {
			right = i - 1;
		}
		else{
			left = i + 1;
		}
	}
	return 0;
}


int main() {
	int n, m;
	cin >> n;
	cin >> m;

	vector<int> north(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> north[i];
	}

	vector<int> south(m, 0);
	for (int i = 0; i < m; ++i) {
		cin >> south[i];
	}

	cout << findMedianSortedArrays(north, south);

	return 0;
}
