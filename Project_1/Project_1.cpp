#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <fstream>

bool simple(uint64_t n)
{
	for (auto i = 2; i < std::floor(sqrt(n)) + 1; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
std::vector<int64_t> div_simple(int64_t n)
{
	std::vector<int64_t> dels;

	for (int64_t i = 2; i < std::floor(sqrt(n)) + 1; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
			{
				dels.push_back(i);
			}
			else
			{
				if (simple(i))
					dels.push_back(i);
				if (simple(n / i))
					dels.push_back(n / i);
			}
		}
	}
	return dels;
}
int64_t fac(uint64_t n)
{
	int64_t fact = 1;
	for (auto i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}
bool palindrom(uint64_t n)
{
	auto temp = n;
	auto b = 0;

	while (temp != 0)
	{
		b = b * 10 + temp % 10;
		temp /= 10;
	}

	if (n == b)
		return true;

	return false;
}
bool palindrom_str(std::string word)
{
	auto len = word.length();

	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}


// leetcode ------------------------------


// 1. Two Sum
class Solution1
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> ans;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
		return ans;
	}
};
// 1


// 3. Longest Substring Without Repeating Characters
class Solution3
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		int store[256] = { 0 };
		int left = 0;
		int right = 0;
		int ans = 0;

		while (right < s.length())
		{
			store[s[right]]++;

			while (store[s[right]] > 1)
			{
				store[s[left]]--;
				left++;
			}

			ans = std::max(ans, right - left + 1);
			right++;
		}
		return ans;
	}
};
// 3


// 5. Longest Palindromic Substring
class Solution5
{
public:
	bool isPal(std::string temp)
	{
		for (size_t i = 0; i < temp.size() / 2; i++)
		{
			if (temp[i] != temp[temp.size() - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	std::string longestPalindrome(std::string s)
	{
		if (s.size() == 1)
		{
			return s;
		}
		std::string ans;
		ans.push_back(s[0]);
		size_t maxx = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			for (size_t j = i + 1; j < s.size(); j++)
			{
				auto tmp = s.substr(i, j - i + 1);
				if (isPal(tmp))
				{
					if (tmp.size() > maxx)
					{
						ans = tmp;
						maxx = tmp.size();
					}
				}
			}
		}
		return ans;
	}
};
// 5


// 9. Palindrome Number
class Solution9
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}

		size_t temp = x;
		size_t b = 0;

		while (temp != 0)
		{
			b = b * 10 + temp % 10;
			temp /= 10;
		}

		if (x == b)
		{
			return true;
		}

		return false;
	}
};
// 9


//14. Longest Common Prefix
class Solution14
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		std::string str;
		size_t maxx = 0;

		for (size_t i = 0; i < strs.size(); i++)
		{
			maxx = std::max(maxx, strs[i].size());
		}
		for (int i = 0; i < maxx; i++)
		{
			bool temp = true;

			for (int j = 1; j < strs.size(); j++)
			{
				if (strs[j - 1][i] != strs[j][i])
				{
					return str;
				}
			}
			str += strs[0][i];
		}
		return str;
	}
};
// 14


// 20. Valid Parentheses
class Solution20
{
public:
	bool isValid(std::string s)
	{
		int16_t temp_count = 0;
		int16_t count = 0;
		std::vector<bool> buffer {};
		buffer.reserve(20);
		int16_t _s = s.size();
		for (int16_t i = 0, j = _s - 1; i < _s; i++, j--)
		{
			if (s[i] != ')' && s[i] != ']' && s[i] != '}')
			{
				buffer.push_back(false);
				buffer.push_back(false);
				count += 2;
			}
			else
			{
				if (buffer.empty())
				{
					return false;
				}
				temp_count = i - 1;
				while (buffer[temp_count] != false)
				{
					temp_count--;
					if (temp_count == -1)
					{
						return false;
					}
				}
				if (char(s[temp_count]) == char(s[i] - 1) || char(s[temp_count]) == char(s[i] - 2))
				{
					buffer[temp_count] = true;
					buffer[i] = true;
					count -= 2;
				}
				else
				{
					return false;
				}
			}
		}
		if (count != 0)
		{
			return false;
		}
		return true;
	}
};
// 20


// 27. Remove Element
class Solution27
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		int count = std::count(nums.begin(), nums.end(), val);
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			for (size_t j = 0; j < nums.size() - 1; j++)
			{
				if (nums[j] == val)
				{
					std::swap(nums[j], nums[j + 1]);
				}
			}
		}
		return nums.size() - count;
	}
};
// 27


// 66. Plus One
class Solution66
{
public:
	std::vector<int> plusOne(std::vector<int>& digits)
	{
		if (digits.empty())
		{
			return digits;
		}
		for (int i = digits.size() - 1; i > -1; i--)
		{
			if (digits[i] + 1 < 10)
			{
				digits[i]++;
				return digits;
			}
			else
			{
				digits[i] = 0;
			}
		}
		if (digits[0] == 0)
		{
			auto iter = digits.begin();
			digits.emplace(iter, 1);
		}
		return digits;
	}
};
// 66

// leetcode ------------------------------





int main()
{
	// (№ 5288) (М. Фирсов) - 25 егэ
	/*

	for (int i = 100000; i < 500000 + 1; i++)
	{
		auto dels = div_simple(i);
		auto flag = false;
		auto diff = 0;
		int64_t fac;
		if (dels.size() > 3)
		{
			auto tmp_it1 = dels.begin();
			auto tmp_it2 = tmp_it1;
			std::advance(tmp_it2, 1);
			diff = *tmp_it2 - *tmp_it1;
			fac = dels.size() * diff;
			flag = true;
			if (diff != 0)
			{
				tmp_it1 = dels.begin();
				tmp_it2 = dels.begin();
				for (auto j = dels.size() - 1; j > 0; j--)
				{
					std::advance(tmp_it2, 1);
					if (*tmp_it2 - *tmp_it1 == diff)
						flag *= true;
					else
						flag *= false;
					std::advance(tmp_it1, 1);
				}
			}

		}

		if (flag)
			std::cout << i << ' ' << fac << '\n';
	}
	*/
	// (№ 5169) (Д. Муфаззалов) - 25 егэ
	/*
	std::set<int> nums;

	for (int i = 2; i < 14 + 1; i++)
	{
		if ((div_simple(fac(i)).size()) & 1)
		{
			nums.insert(i);
		}
		std::cout << i << ' ' << div_simple(fac(i)).size() << '\n';
	}
	*/
	// (№ 5021) (И.Женецкий) - 25 егэ
	/*
	std::vector<int64_t> nums_of_2;

	for (auto i = 0; i < 50; i++)
	{
		nums_of_2.push_back(std::pow(2, i));
	}


	for (auto i = 99999; i < 1048571 + 1; i++)
	{
		if (simple(i))
		{
			for (auto j = 0; j < nums_of_2.size(); j++)
			{
				if (std::abs(i - nums_of_2[j]) <= 5)
				{
					std::cout << i << ' ' << nums_of_2[j] << '\n';
				}
			}
		}
	}

	*/
	// (№ 4986) (М. Фирсов) - 25 егэ
	/*std::vector<uint64_t> nums;
	std::vector<uint64_t> sums;
	auto count = 0;
	for (auto i = 1000000000; i > 99; i--)
	{
		if (palindrom(i))
		{
			uint64_t summ = 1;
			auto tmp = i;
			if (simple(i))
			{
				while (tmp != 0)
				{
					if (tmp % 10 != 0)
					{
						summ *= tmp % 10;
						tmp /= 10;
					}
					else
						tmp /= 10;
				}
				nums.push_back(i);
				sums.push_back(summ);
			}
		}
		count++;
		if (count == 1000000)
		{
			std::cout << i << '\n';
			count = 0;
		}
	}

	int64_t maxx = 0;
	int64_t maxx_n = 0;

	for (auto i = 0; i < sums.size(); i++)
	{
		if (std::count(sums.begin(), sums.end(), sums[i]) > maxx)
		{
			maxx = std::count(sums.begin(), sums.end(), sums[i]);
			maxx_n = sums[i];
		}
	}

	for (auto i = 0; i < nums.size(); i++)
	{
		if (sums[i] == maxx_n)
		{
			std::cout << nums[i] << '\n';
		}
	}*/
	// (№ 5174) (М. Шагитов) - 17 егэ
	/*std::string line;
	std::vector<int64_t> nums;
	std::vector<int64_t> nums50;
	auto tmp = 0;

	std::ifstream in("17 (2).txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			tmp = std::stoi(line);
			nums.push_back(tmp);
			if (tmp % 50 == 0)
				nums50.push_back(tmp);
		}
	}
	in.close();


	auto summ50 = 0;
	int64_t tmp_n;

	for (auto i = 0; i < nums50.size(); i++)
	{
		tmp_n = nums50[i];
		while (tmp_n != 0)
		{
			summ50 += tmp_n % 10;
			tmp_n /= 10;
		}
	}


	int64_t count = 0;
	int64_t maxx = 0;
	for (auto i = 2; i < nums.size(); i++)
	{
		int64_t summ_all = nums[i] + nums[i - 1] + nums[i - 2];
		int64_t summ1 = 0;
		int64_t summ2 = 0;
		int64_t summ3 = 0;

		tmp_n = nums[i - 2];
		while (tmp_n != 0)
		{
			summ1 += tmp_n % 10;
			tmp_n /= 10;
		}

		tmp_n = nums[i - 1];
		while (tmp_n != 0)
		{
			summ2 += tmp_n % 10;
			tmp_n /= 10;
		}

		tmp_n = nums[i];
		while (tmp_n != 0)
		{
			summ3 += tmp_n % 10;
			tmp_n /= 10;
		}


		if ((nums[i] == summ1 || nums[i] == summ2 || nums[i - 1] == summ1 || nums[i - 1] == summ3 || nums[i - 2] == summ2 || nums[i - 2] == summ3) && (summ_all < summ50))
		{
			count++;
			maxx = std::max(maxx, summ_all);
		}
	}

	std::cout << count << ' ' << maxx << '\n';*/
	// (№ 4202) (Б. Баобаба) - 25 егэ
	/*std::vector<int64_t> nums;

	auto count = 0;
	for (auto i = 3000000 / 6; i < (10000000 + 1) / 6; i++)
	{
		count++;
		auto n1 = 6 * i - 1;
		auto n2 = 6 * i + 1;

		if (simple(n1))
		{
			if (simple(n2))
			{
				nums.push_back(n1);
				nums.push_back(n2);
			}
		}

		if (count == 100000)
		{
			std::cout << i << '\n';
			count = 0;
		}
	}
	auto last = nums.end();
	std::cout << nums.size() / 2 << ' ' <<  (*(last - 1) + *(last - 2)) / 2 << '\n';*/
	//
	/*std::vector<int64_t> nums;



	for (auto i = 650000; i < 650000 + 300; i++)
	{
		nums = div_simple(i);
		if (!nums.empty())
		{
			auto f = std::accumulate(nums.begin(), nums.end(), 0) / nums.size();

			if (f % 37 == 23)
			{
				std::cout << i << ' ' << f << '\n';
			}
		}
	}*/
	// (№ 4280) (А. Кабанов) - 27 егэ (не оптимально, но считает быстро)
	/*int n;
	std::ifstream file("27b.txt");
	file >> n;
	std::vector<uint64_t> nums;
	size_t summ = 0;
	for (size_t i = 0; i < n; i++)
	{
		uint64_t tmp;
		file >> tmp;
		nums.push_back(tmp);
	}
	size_t count = 0;
	size_t len;
	size_t minn = pow(10, 10);
	size_t maxx = 0;
	size_t k = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (nums[i] % 39 == 0)
		{
			count++;
		}
		k++;
		summ = nums[i];
		len = 1;
		for (size_t j = i + 1; j < n; j++)
		{
			len++;
			summ += nums[j];
			if (summ % 39 == 0)
			{
				if (len <= 20)
				{
					count++;
				}
			}
			if (len > 20)
			{
				break;
			}
			if (k == 1000)
			{
				std::cout << i << '\n';
				k = 0;
			}
		}
	}

	std::cout << count << '\n';*/


	Solution20 c;
	c.isValid("()");

	return 0;
}