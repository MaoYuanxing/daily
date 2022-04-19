#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

string reverse_one_word(string str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = tmp;
	}
	return str;
}

vector<string> split(const string &str, const string &delim)
{ //将分割后的子字符串存储在vector中
	vector<string> res;
	if ("" == str)
		return res;

	string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
	size_t pos;
	size_t size = strs.size();

	for (int i = 0; i < size; ++i)
	{
		pos = strs.find(delim, i); // pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
		if (pos < size)
		{										//如果查找到，如果没有查找到分隔符，pos为string::npos
			string s = strs.substr(i, pos - i); //*****从i开始长度为pos-i的子字符串
			res.push_back(s);					//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
			i = pos + delim.size() - 1;
		}
	}
	return res;
}

void test1()
{ //空字符串
	cout << "******test1****** " << endl;
	string s = "";

	std::vector<string> res = split(s, " ");
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
}

void test2()
{ //只有一个字符串
	cout << "******test2****** " << endl;
	string s = "my";

	std::vector<string> res = split(s, " ");
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
}

void test3()
{ //正常字符串
	cout << "******test3****** " << endl;
	string s = "my name is  lmm   ";

	std::vector<string> res = split(s, " ");
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
}
int main()
{

	// test1();
	// test2();
	// test3();
	vector<int> a = {1, 2, 3, 43, 45, 32, 45, 12, 345, 34, 6};
	cout << *lower_bound(a.begin(), a.end(), 7) << endl;
	cout << INT_MAX << " :: " << INT_MIN << endl;
	return 0;
}
