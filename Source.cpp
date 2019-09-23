540. Single Element in a Sorted Array
Description :
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Find this single element that appears only once.

Example 1
    Input : [1, 1, 2, 3, 3, 4, 4, 8, 8]
	Output : 2
Example 2
	Input : [3, 3, 7, 7, 10, 11, 11]
	Output : 10


	
Solution :
Intuition and Algorithm

	All elements have first occurrence at even index(0, 2, ..) and next occurrence at odd index(1, 3, …).Let element X occur only once that means all 
	elements after the required element have first occurrence at odd index and next occurrence at even index.
	For example : Input: [1, 1, 2, 3, 3, 4, 4, 8, 8]
	Index occurence : [0, 1, 2, 3, 4, 5, 6, 7, 8]
	We can easily find that occurence of all element after element 2 all elements after the required element have first occurrence at odd index and next
	occurrence at even index.Therefore we can use bonary search to find that element using binary search to find the index of that element.
	ALGORITHM :
	1) Find the middle index, say ‘mid’.
	2) If ‘mid’ is even, then compare nums[mid] and nums[mid + 1].If both are same, then the required element after ‘mid’ else before mid.
	3) If ‘mid’ is odd, then compare nums[mid] and nums[mid – 1].If both are same, then the required element after ‘mid’ else before mid.


SOURCE CODE:
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums)
	{
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left < right)
		{
			int mid = (right + left) / 2;
			if (mid % 2 == 0)
			{
				if (nums[mid] == nums[mid - 1])
				{
					right = mid - 2;
				}
				else if (nums[mid] == nums[mid + 1])
				{
					left = mid + 2;
				}
				else
				{
					return nums[mid];
				}
			}
			else
			{
				if (nums[mid] == nums[mid - 1])
				{
					left = mid + 1;
				}
				else if (nums[mid] == nums[mid + 1])
				{
					right = mid - 1;
				}
			}
		}
		return nums[left];
	}
};
