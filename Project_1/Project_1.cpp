﻿#include <iostream>
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



	return 0;
}