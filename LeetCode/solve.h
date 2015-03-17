#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define min(x,y) x>y?y:x
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int overflow = 0;
	vector<int> result;
	for (vector<int>::size_type index = digits.size() - 1; index >= 0; --index)
	{
		cout << index << endl;
		if (index == digits.size() - 1)
		{
			result.push_back((digits[index] + 1 + overflow) % 10);
			overflow = (digits[index] + 1 + overflow) / 10;
		}
		else
		{
			if (overflow != 0)
			{
				result.push_back((digits[index] + overflow) % 10);
				overflow = (digits[index] + overflow) / 10;
			}
			else result.push_back(digits[index]);
		}
	}
	if (overflow != 0) result.push_back(overflow);
	reverse(result.begin(), result.end());
	return result;
}
vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> result;
	for (int i = 1; i <= k; ++i)
	{
		if (i == 1)
		{
			for (int begin = 1; begin <= n - k + i; ++begin)
			{
				vector<int> tempcombine;
				tempcombine.push_back(begin);
				result.push_back(tempcombine);
			}
			if (result.empty()) break;
		}
		else
		{
			size_t processSize = result.size();
			for (size_t index = 0; index != processSize; ++index)
			{
				vector<int> increase(result[index]);
				bool changed = false;
				for (int begin = result[index][i - 2]+1; begin <= n - k + i; ++begin)
				{
					if (!changed)
					{
						result[index].push_back(begin);
						changed = true;
					}
					else
					{
						vector<int> tempcombine(increase);
						tempcombine.push_back(begin);
						result.push_back(tempcombine);
					}
				}
			}
		}
	}
	return result;
}
void reverse(int nums[], int first, int last)
{
	while (first < last)
	{
		int temp = nums[first];
		nums[first] = nums[last];
		nums[last] = temp;
		++first;
		--last;
	}
}

void rotate(int nums[], int n, int k) {
	reverse(nums, 0, n - k - 1);
	reverse(nums, n - k, n - 1);
	reverse(nums, 0, n - 1);
}

bool cmp(const string s1, const string s2) {
	return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> snum;
		string result;
		for (size_t i = 0; i != num.size(); ++i)
			snum.push_back(int2string(num[i]));
		sort(snum.begin(), snum.end(), cmp);
		for (size_t i = 0; i != snum.size(); ++i)
		{
			cout << snum[i] << endl;
			result = snum[i] + result;
		}
		return result;
	}
	string int2string(int num)
	{
		string result = "";
		do
		{
			result = char(num % 10 + '0') + result;
			num /= 10;
		} while (num);
		return result;
	}
};
//typedef pair<int, int> position;
//vector<vector<string> > solveNQueens(int n) {
//	vector<position> queens(n);
//	setQueens(queens, 1, n);
//
//}
//void setQueens(vector<position> &q, int level, int n)
//{
//	for (int i = q[level].second+1; i <= n; ++i)
//	{
//		int j = 1;
//		for (; j <= level; ++j)
//		{
//			if (q[j].second == i || abs(q[j].first - level) == abs(q[j].second - i))
//				break;
//		}
//		if (j > level)
//		{
//			q[level].first = level;
//			q[level].second = i;
//			if (level == n)
//				return;
//			else
//				setQueens(q, level + 1, n);
//		}
//	}
//	setQueens(q, level - 1, n);
//}
class Test{
public:
	Test(int n)
	{
		data = new int[n];
	};
	~Test()
	{
		cout << "let's delete data" << endl;
		delete data;
	}
private:
	int *data;
};