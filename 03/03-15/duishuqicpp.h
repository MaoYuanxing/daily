#ifndef _DUISHUQICPP_H_
#define _DUISHUQICPP_H_
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> randomArray(int maxLen, int maxValue);
//检查数组是否排列好顺序
extern bool isSorted(int arr[], int len);
#endif